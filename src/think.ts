import { Shogi } from "./Shogi.js/src/shogi";
import { BoardConverter, IMovePromote } from "./board_converter";
import { KifuTool } from "./kifu_tool";
import { load, DescriptorRunner } from "webdnn";
import SymbolicFloat32Array from "webdnn/symbolic_typed_array/symbolic_float32array";
import { Game } from "./game";

export class Think {
    private model: DescriptorRunner
    private input_view: SymbolicFloat32Array;
    private output_policy_view: SymbolicFloat32Array;
    private output_value_view: SymbolicFloat32Array;
    public softmax_temperature: number;

    constructor() {
        this.softmax_temperature = 0;
    }

    async load(model_name: string, progressCallback) {
        this.model = await load(`./webdnn_model/${model_name}`,
            { backendOrder: "webassembly", progressCallback: progressCallback });
        [this.input_view] = this.model.getInputViews();
        [this.output_policy_view, this.output_value_view] = this.model.getOutputViews();
        console.log('model loaded');
    }

    async do_think(game: Game): Promise<IMovePromote> {
        let pos = game.pos;
        let moves = BoardConverter.GetLegalMoves(pos);
        console.log(`${moves.length} legal moves`);

        if (moves.length === 0) {
            return null;
        }

        let input_array = BoardConverter.MakeInput(pos, game.game_ply);
        this.input_view.set(input_array);
        console.log("Running model");
        await this.model.run();
        let value = this.output_value_view.toActual()[0];
        console.log(`Value ${value}`);
        let policy = this.output_policy_view.toActual();

        let scores = [];
        for (let i = 0; i < moves.length; i++) {
            let move = moves[i];
            let mi = BoardConverter.GetMoveIndex(move, pos.turn);
            let score = policy[mi];
            scores.push(score);
            console.log(`${KifuTool.GetMoveString(pos, move)}, score ${score}`);
        }

        let { probabilities, index } = this.softmaxSampling(scores);
        let best_move = moves[index];
        console.log(`${KifuTool.GetMoveString(pos, best_move)} ${probabilities[index] * 100 | 0}%`)

        return best_move;
    }

    private softmaxSampling(scores: number[]): { probabilities: number[], index: number } {
        if (this.softmax_temperature <= 0) {
            // find highest score
            let best_score = -Infinity;
            let best_index = 0;
            let probabilities = [];
            for (let i = 0; i < scores.length; i++) {
                probabilities.push(0);
                if (best_score < scores[i]) {
                    best_score = scores[i];
                    best_index = i;
                }
            }
            probabilities[best_index] = 1;
            return { probabilities: probabilities, index: best_index };
        } else {
            // calculate probability and randomly choice

            // get maximum
            let best_score = -Infinity;
            for (let i = 0; i < scores.length; i++) {
                if (best_score < scores[i]) {
                    best_score = scores[i];
                }
            }

            let exp_scores = [];
            let exp_sum = 0.0;
            for (let i = 0; i < scores.length; i++) {
                let exp_score = Math.exp((scores[i] - best_score) / this.softmax_temperature);
                exp_scores.push(exp_score);
                exp_sum += exp_score;
            }

            let probabilities = [];
            for (let i = 0; i < scores.length; i++) {
                let probability = exp_scores[i] / exp_sum;
                probabilities.push(probability);
            }

            let rnd = Math.random();
            let chosen_index = 0;
            for (let i = 0; i < scores.length; i++) {
                rnd -= probabilities[i];
                if (rnd <= 0) {
                    chosen_index = i;
                    break;
                }
            }

            return { probabilities: probabilities, index: chosen_index };
        }
    }
}
