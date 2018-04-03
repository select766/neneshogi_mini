import { Shogi } from "./Shogi.js/src/shogi";
import { Think } from "./think";
import { KifuTool } from "./kifu_tool";
import { Game } from "./game";
let think = new Think();
think.softmax_temperature = 1.0;
think.load();

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
}

window.onload = () => {
    document.getElementById("next").onclick = next;
}
