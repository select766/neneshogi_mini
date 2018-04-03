import { Shogi } from "./Shogi.js/src/shogi";
let pos = new Shogi();
console.log(pos.toCSAString());
console.log(pos.board);
import { Think } from "./think";
let think = new Think();
think.load().then(() => {
    think.do_think(pos);
});
