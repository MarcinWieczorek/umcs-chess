#include "Logic.h"

Logic::Logic(Game &game) {
    this->game = &game;
}

Move Logic::find_best_move(bool white) {
    int best_value = 100;
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

bool Logic::is_move_valid(Move &) {
    return true;
}

