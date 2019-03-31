#pragma once
#include "Frontend.h"
#include "Board.h"
#include "Game.h"

class FrontendCLI : Frontend {
    public:
        // Board &board;
        FrontendCLI(Game &game);
        Game *game;
        Game &getGame();
        void draw();
};
