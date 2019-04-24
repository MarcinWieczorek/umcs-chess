#pragma once
#include <vector>

#include "../Game.h"

class AIMinimax {
    private:
        Game *game;
        bool white;
    public:
        AIMinimax(Game &, bool);
        Move find_best_move();
        int minimax(int, bool, Move &);
        int evaluate();
        std::vector<Move> get_moves();
        Move move_construct(BoardPosition, int, int);
};
