import { Shogi, Color } from "./Shogi.js/src/shogi";
import { Think } from "./think";
import { KifuTool, Zenkakusuji, Kansuji, PieceKindKifuName, PieceKindBoardName } from "./kifu_tool";
import { Game } from "./game";
let think = new Think();
think.softmax_temperature = 1.0;
think.load();

let board_cells;
let hand_cells;
let game: Game;
let in_step: boolean = false;
let game_end = true;
async function step() {
    if (in_step) {
        console.warn("called step while performing last step");
        return;
    }
    in_step = true;

    let msg = "";
    if (game_end) {
        // 初期局面を設定
        game = new Game();
        msg = "対局開始前";
        game_end = false;
    } else {
        if (game.game_ply > 256) {
            msg = "256手により引き分け";
            game_end = true;
        } else {
            let best_move = await think.do_think(game.pos);
            if (!best_move) {
                console.log("Mated");
                msg = "投了";
                game_end = true;
            } else {
                let move_str = game.GetMoveString(best_move, true);
                console.log(`Move: ${move_str}`);
                msg = `${game.game_ply} ${move_str}`;
                game.MoveOrDrop(best_move);
            }
        }
    }
    document.getElementById("last_move").innerText = msg;
    console.log(game.pos.toCSAString());
    console.log(`Check: ${game.pos.isCheck()}`);
    updateBoard(game);

    in_step = false;
}

async function step_move() {

}

function initBoard() {
    board_cells = {};
    let table = document.getElementById("board");
    for (let y = 0; y <= 9; y++) {
        let tr = document.createElement("tr");
        table.appendChild(tr);
        board_cells[y] = {};
        for (let x = 9; x >= 0; x--) {
            // 右端がx==1
            let td = document.createElement("td");
            let span = document.createElement("span");
            if (y === 0) {
                if (x !== 0) {
                    span.innerText = Zenkakusuji[x];
                }
            } else if (x === 0) {
                span.innerText = Kansuji[y];
            } else {
                board_cells[y][x] = span;
            }
            td.appendChild(span);
            tr.appendChild(td);
        }
    }

    hand_cells = {};
    hand_cells[Color.Black] = document.getElementById("hand-black");
    hand_cells[Color.White] = document.getElementById("hand-white");
}

function updateBoard(game: Game) {
    for (let y = 1; y <= 9; y++) {
        for (let x = 1; x <= 9; x++) {
            let piece = game.pos.get(x, y);
            let str = "　";
            let style_class = "piece";
            if (piece != null) {
                str = PieceKindBoardName[piece.kind];
                if (piece.color === Color.White) {
                    style_class += " white";//180度回転
                }

                if (game.last_move) {
                    if (game.last_move.to.x === x && game.last_move.to.y === y) {
                        style_class += " last_move";
                    }
                }
            }

            let span = board_cells[y][x];
            span.className = style_class;
            span.innerText = str;
        }
    }

    [Color.Black, Color.White].forEach((color) => {
        let str = "";
        let hand_counts = game.pos.getHandsSummary(color);
        Object.keys(hand_counts).forEach((kind) => {
            if (hand_counts[kind] > 0) {
                str += PieceKindKifuName[kind] + hand_counts[kind] + " ";
            }
        });
        hand_cells[color].innerText = str;
    });
}

window.onload = () => {
    initBoard();
    setImmediate(step);
    setInterval(step, 2000);
}
