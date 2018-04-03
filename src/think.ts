import { Shogi } from "./Shogi.js/src/shogi";
import { load } from "webdnn";

export class Think {
    async load() {
        let model = await load("./webdnn_model", { "backendOrder": "webassembly" });
        console.log('model loaded');
    }
}
