#include "Logic.h"
#include "Constants.h"

Logic::Logic(Game &game) {
    this->game = &game;
}

Move Logic::find_best_move(bool white) {
    // int best_value = 100;
    Move best_move;

    for(int x = 'a'; x <= 'h'; x++) {
        for(int y = 0; y <= 8; y++) {
            BoardPosition &pos = this->game->board.get(x, y);
            if(pos.is_empty()) {
                // board[i][j] = SYMBOL_PLAYER;
                // int move_val = minimax(board, 0, false, -INT_MAX, INT_MAX);
                // board[i][j] = ' ';
                //
                // if(move_val > best_value) {
                //     best_value = move_val;
                //     best_move = { i, j };
                // }
            }
        }
    }

    return best_move;
}

bool Logic::is_move_valid(Move &m) {
    switch(m.from.figure) {
        case FIGURE_EMPTY: //move from empty spot
            return false;
        case FIGURE_PAWN:
            //not straight
            if(m.to.is_empty()) {
                if(m.from.x != m.to.x) {
                    return false;
                }
            }
            else {
                //onto own figure
                if(m.to.white == m.from.white) {
                    return false;
                }

                //More than 1 place
                if(!(m.to.x == m.from.x - 1 || m.to.x == m.from.x + 1)) {
                    return false;
                }
            }

            //backwards
            if(m.from.y > m.to.y) {
                return false;
            }

            break;
    }

    return true;
}

