#pragma once
#include "Frontend.h"
#include "Board.h"
#include "Game.h"

class FrontendCLI : Frontend {
    public:
        FrontendCLI(Game &game);
        Game *game;
        Game &getGame();
        void draw();
};
