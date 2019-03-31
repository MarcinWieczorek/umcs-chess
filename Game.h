#pragma once
#include "Board.h"

#define FIGURE_PAWN  'P'
#define FIGURE_KING  'K'
#define FIGURE_EMPTY '.'

class Game {
    public:
        Board board;
        int white_turn;
        Game();
};

