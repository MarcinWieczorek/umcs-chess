#include <iostream>

#include "FrontendCLI.h"

FrontendCLI::FrontendCLI(Game &game) {
    this->game = &game;
}

Game &FrontendCLI::getGame() {
    return *game;
}

void FrontendCLI::draw() {
    for(int y = 0; y < 8; y++) {
        for(int x = 0; x < 8; x++) {
            BoardPosition &pos = this->getGame().board.get(x, y);
            char c = pos.figure;

            if(!pos.white && pos.figure != FIGURE_EMPTY) {
                c -= 'A' - 'a';
            }

            std::cout << c << " ";
        }
        std::cout << std::endl;
    }
}

