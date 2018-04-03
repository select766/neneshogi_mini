import { Shogi, Piece, Color, IMove } from "./Shogi.js/src/shogi";
import { IMovePromote } from "./board_converter";


const pieceKindKifuName = {
    "FU": "歩",
    "KY": "香",
    "KE": "桂",
    "GI": "銀",
    "KA": "角",
    "HI": "飛",
    "KI": "金",
    "OU": "玉",
    "TO": "と",
    "NY": "成香",
    "NK": "成桂",
    "NG": "成銀",
    "UM": "馬",
    "RY": "竜",
};

const zenkakusuji = "０１２３４５６７８９";
const kansuji = "〇一二三四五六七八九";

export class KifuTool {
    public static GetMoveString(pos: Shogi, move: IMovePromote, last_move?: IMovePromote) {
        let kind = move.kind;
        if (!kind) {
            kind = pos.get(move.from.x, move.from.y).kind;
        }
        let str = `${zenkakusuji[move.to.x]}${kansuji[move.to.y]}`;
        if (move.kind) {
            // 打ち
            str += pieceKindKifuName[kind];
            str += "打";
        } else {
            // 移動
            if (last_move) {
                if (move.to.x === last_move.to.x && move.to.y === last_move.to.y) {
                    str += "同";
                }
            }
            str += pieceKindKifuName[kind];
            if (move.promote) {
                str += "成";
            }
            str += `(${move.from.x}${move.from.y})`;
        }

        return str;
    }
}
