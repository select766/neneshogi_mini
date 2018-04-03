import { Shogi, Color } from "./Shogi.js/src/shogi";
import { IMovePromote, BoardConverter } from "./board_converter";
import { KifuTool } from "./kifu_tool";

// 対局情報クラス
export class Game {
    pos: Shogi
    move_history: IMovePromote[];
    last_move: IMovePromote;
    game_ply: number;

    constructor() {
        this.pos = new Shogi();
        this.move_history = [];
        this.last_move = null;
        this.game_ply = 1;
    }

    public GetLegalMoves(): IMovePromote[] {
        // TODO: 千日手判定
        return BoardConverter.GetLegalMoves(this.pos);
    }

    public MoveOrDrop(m: IMovePromote) {
        if (m.from) {
            this.pos.move(m.from.x, m.from.y, m.to.x, m.to.y, m.promote);
        } else {
            this.pos.drop(m.to.x, m.to.y, m.kind);
        }
        this.move_history.push(m);
        this.last_move = m;
        this.game_ply++;
    }

    public GetMoveString(m: IMovePromote, appendTurn: boolean = false): string {
        let str = KifuTool.GetMoveString(this.pos, m, this.last_move);
        if (appendTurn) {
            str = (this.pos.turn === Color.Black ? "▲" : "△") + str;
        }
        return str;
    }
}
