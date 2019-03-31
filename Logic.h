#pragma once
#include "Move.h"
#include "Game.h"

class Logic {
    private:
        Game *game;
    public:
        Logic(Game &);
        bool is_move_valid(Move &);
        Move find_best_move(bool);
};

