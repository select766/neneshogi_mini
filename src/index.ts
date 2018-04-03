import { Shogi } from "./Shogi.js/src/shogi";
let pos = new Shogi();
console.log(pos.toCSAString());
console.log(pos.board);
import { Think } from "./think";
import { KifuTool } from "./kifu_tool";
let think = new Think();
think.load();

let last_move = null;
async function next() {
    let best_move = await think.do_think(pos);
    if (!best_move) {
        console.log("Mated");
    } else {
        console.log(`Move: ${KifuTool.GetMoveString(pos, best_move, last_move)}`);
        if (best_move.kind) {
            // drop
            pos.drop(best_move.to.x, best_move.to.y, best_move.kind);
        } else {
            // move
            pos.move(best_move.from.x, best_move.from.y,
                best_move.to.x, best_move.to.y, best_move.promote);
        }
    }
    last_move = best_move;
    console.log(pos.toCSAString());
    console.log(`Check: ${pos.isCheck()}`);
}

window.onload = () => {
    document.getElementById("next").onclick = next;
}
