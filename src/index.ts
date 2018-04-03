import { Shogi, Color } from "./Shogi.js/src/shogi";
import { Think } from "./think";
import { KifuTool, Zenkakusuji, Kansuji, PieceKindKifuName } from "./kifu_tool";
import { Game } from "./game";
let think = new Think();
think.softmax_temperature = 1.0;
think.load();

let board_cells;
let hand_cells;
let game = new Game();
async function next() {
    let best_move = await think.do_think(game.pos);
    if (!best_move) {
        console.log("Mated");
    } else {
        console.log(`Move: ${game.GetMoveString(best_move, true)}`);
        game.MoveOrDrop(best_move);
    }
    console.log(game.pos.toCSAString());
    console.log(`Check: ${game.pos.isCheck()}`);
    updateBoard(game);
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
            if (y === 0) {
                if (x !== 0) {
                    td.innerText = Zenkakusuji[x];
                }
            } else if (x === 0) {
                td.innerText = Kansuji[y];
            } else {
                board_cells[y][x] = td;
            }
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
            let str = "";
            if (piece != null) {
                str = PieceKindKifuName[piece.kind];
                if (piece.color == Color.White) {
                    str = "v" + str;
                }
            }

            board_cells[y][x].innerText = str;
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
    updateBoard(game);
    document.getElementById("next").onclick = next;
}
