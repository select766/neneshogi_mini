import { Shogi } from "./Shogi.js/src/shogi";
import { BoardConverter, IMovePromote } from "./board_converter";
import { KifuTool } from "./kifu_tool";
import { load, DescriptorRunner } from "webdnn";
import SymbolicFloat32Array from "webdnn/symbolic_typed_array/symbolic_float32array";

export class Think {
    private model: DescriptorRunner
    private input_view: SymbolicFloat32Array;
    private output_policy_view: SymbolicFloat32Array;
    private output_value_view: SymbolicFloat32Array;

    async load() {
        this.model = await load("./webdnn_model", { "backendOrder": "webassembly" });
        [this.input_view] = this.model.getInputViews();
        [this.output_policy_view, this.output_value_view] = this.model.getOutputViews();
        console.log('model loaded');
    }

    async do_think(pos: Shogi): Promise<IMovePromote> {
        let moves = BoardConverter.GetLegalMoves(pos);
        console.log(`${moves.length} legal moves`);

        if (moves.length === 0) {
            return null;
        }

        let input_array = BoardConverter.MakeInput(pos);
        this.input_view.set(input_array);
        console.log("Running model");
        await this.model.run();
        let value = this.output_value_view.toActual()[0];
        console.log(`Value ${value}`);
        let policy = this.output_policy_view.toActual();

        let scores = [];
        let best_move;
        let best_score = -Infinity;
        for (let i = 0; i < moves.length; i++) {
            let move = moves[i];
            let mi = BoardConverter.GetMoveIndex(move, pos.turn);
            let score = policy[mi];
            scores.push(score);
            console.log(`${KifuTool.GetMoveString(pos, move)}, score ${score}`);
            if (score > best_score) {
                best_score = score;
                best_move = move;
            }
        }

        return best_move;
    }
}
