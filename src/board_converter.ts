// DNNの入出力行列の操作

import { Shogi, Piece, Color, IMove } from "./Shogi.js/src/shogi";
import ndarray from "ndarray";

export interface IMovePromote extends IMove {
    promote?: boolean;
}

const dnn_input_channel = 86;

function fillChannel(array: ndarray, channel: number, value: number) {
    let begin = array.index(channel, 0, 0);
    let end = array.index(channel + 1, 0, 0);
    array.data.fill(value, begin, end);
}

function fillChannels(array: ndarray, channel_begin: number, channel_end: number, value: number) {
    let begin = array.index(channel_begin, 0, 0);
    let end = array.index(channel_end, 0, 0);
    array.data.fill(value, begin, end);
}

// 手番側盤上の駒のチャンネル
const pieceKindChannel = {
    "FU": 0,
    "KY": 1,
    "KE": 2,
    "GI": 3,
    "KA": 4,
    "HI": 5,
    "KI": 6,
    "OU": 7,
    "TO": 8,
    "NY": 9,
    "NK": 10,
    "NG": 11,
    "UM": 12,
    "RY": 13,
};

// 手番逆転時の盤上の駒チャンネルオフセット
const pieceKindColorOffset = 14;

// 180度回転した座標を生成する
function inverseSquare(x: number, y: number) {
    return [10 - x, 10 - y];
}

function inverseSquareObject(obj: { x: number, y: number }) {
    return { x: 10 - obj.x, y: 10 - obj.y };
}

export class BoardConverter {
    public static MakeInput(pos: Shogi): Float32Array {
        let raw_array = new Float32Array(dnn_input_channel * 9 * 9);
        let array = ndarray(raw_array, [dnn_input_channel, 9, 9]);

        let inverse = pos.turn === Color.White;
        // 盤上の駒情報設定 ch 0~28
        // 座標系: DNN(x=筋,y=段)、Shogi.js(x=筋,y=段)で同じ
        // DNNの行列を操作する際は0始まりだが、
        // Shogi.jsの関数を介する際はインデックスが1始まりなので1始まりでできるだけ処理
        for (let x = 1; x <= 9; x++) {
            for (let y = 1; y <= 9; y++) {
                let [bpx, bpy] = inverse ? inverseSquare(x, y) : [x, y];
                let p: Piece = pos.get(bpx, bpy);
                if (p != null) {
                    let channel = pieceKindChannel[p.kind];
                    if (pos.turn !== p.color) {
                        channel += pieceKindColorOffset;
                    }
                    array.set(channel, x - 1, y - 1, 1);
                }
            }
        }

        // 持ち駒 ch 28~84
        let channel_offset = 28;
        for (let i = 0; i < 2; i++) {
            let c = pos.turn;
            if (i > 0) {
                c = Piece.oppositeColor(c);
            }
            let name_count = pos.getHandsSummary(c);
            // 歩は最大8枚
            fillChannels(array, channel_offset, channel_offset + Math.min(name_count["FU"], 8), 1);
            channel_offset += 8;
            fillChannels(array, channel_offset, channel_offset + name_count["KY"], 1);
            channel_offset += 4;
            fillChannels(array, channel_offset, channel_offset + name_count["KE"], 1);
            channel_offset += 4;
            fillChannels(array, channel_offset, channel_offset + name_count["GI"], 1);
            channel_offset += 4;
            fillChannels(array, channel_offset, channel_offset + name_count["KA"], 1);
            channel_offset += 2;
            fillChannels(array, channel_offset, channel_offset + name_count["HI"], 1);
            channel_offset += 2;
            fillChannels(array, channel_offset, channel_offset + name_count["KI"], 1);
            channel_offset += 4;
        }
        // TODO: 王手・手数チャンネル
        return raw_array;
    }

    public static GetLegalMoves(pos: Shogi): IMovePromote[] {
        // 合法手を列挙
        // TODO: 王手放置禁止

        let moves: IMovePromote[] = [];
        for (let x = 1; x <= 9; x++) {
            for (let y = 1; y <= 9; y++) {
                let p = pos.get(x, y);
                if (p && p.color === pos.turn) {
                    // 手番側の駒がある
                    let piece_moves = pos.getMovesFrom(x, y);
                    piece_moves.forEach((move) => {
                        let to_rank = move.to.y; // 1-origin
                        if (pos.turn === Color.White) {
                            to_rank = 10 - to_rank;
                        }
                        // 駒が成れるか、成らずに動けるかを決定
                        let promote = to_rank <= 3;
                        let non_promote = true;
                        switch (move.kind) {
                            case "FU":
                            case "KY":
                                non_promote = to_rank >= 2;
                                break;
                            case "KE":
                                non_promote = to_rank >= 3;
                                break;
                            case "GI":
                            case "KA":
                            case "HI":
                                break;
                            default:
                                // 成れない駒
                                promote = false;
                                break;
                        }

                        if (promote) {
                            moves.push({ from: move.from, to: move.to, promote: true });
                        }
                        if (non_promote) {
                            moves.push({ from: move.from, to: move.to, promote: false });
                        }
                    })
                }
            }
        }

        let piece_drops = pos.getDropsBy(pos.turn);
        Array.prototype.push.apply(moves, piece_drops);//末端にArrayを追加

        return moves;
    }

    public static GetMoveIndex(m: IMovePromote, turn: Color) {
        let move_to = m.to;
        if (turn == Color.White) {
            move_to = inverseSquareObject(move_to);
        }

        let channel = 0;
        let move_from = m.from;
        if (m.from) {
            // move
            if (turn === Color.White) {
                move_from = inverseSquareObject(move_from);
            }

            let file_diff = move_to.x - move_from.x;
            let rank_diff = move_to.y - move_from.y;

            if (file_diff == -1 && rank_diff == -2) {
                channel = 64;
            } else if (file_diff == 1 && rank_diff == -2) {
                channel = 65;
            } else {
                let offset = 0;
                if (file_diff < 0) {
                    if (rank_diff < 0) {
                        offset = 0;
                    } else if (rank_diff === 0) {
                        offset = 8;
                    } else {
                        offset = 16;
                    }
                } else if (file_diff == 0) {
                    if (rank_diff < 0) {
                        offset = 24;
                    } else {
                        offset = 32;
                    }
                } else {
                    if (rank_diff < 0) {
                        offset = 40;
                    } else if (rank_diff === 0) {
                        offset = 48;
                    } else {
                        offset = 56;
                    }
                }
                let dist = Math.max(Math.abs(file_diff), Math.abs(rank_diff)) - 1;
                channel = offset + dist;
            }

            if (m.promote) {
                channel += 66;
            }
        } else {
            // drop
            channel = pieceKindChannel[m.kind] + 132;
            move_from = move_to;
        }

        return channel * 81 + (move_from.x - 1) * 9 + (move_from.y - 1);
    }
}
