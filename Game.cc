#include "Game.h"

Game::Game() {
    this->white_turn = 1;
    this->board.generate();
}

