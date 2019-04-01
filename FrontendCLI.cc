#include <iostream>

#include "FrontendCLI.h"
#include "Constants.h"

FrontendCLI::FrontendCLI(Game &game) {
    this->game = &game;
}

Game &FrontendCLI::getGame() {
    return *game;
}

void FrontendCLI::draw() {
    for(int y = 8; y > 0; y--) {
        for(int x = 'a'; x <= 'h'; x++) {
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

