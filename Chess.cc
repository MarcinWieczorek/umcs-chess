#include <iostream>
#include <string>

#include "Game.h"
#include "Logic.h"
#include "FrontendCLI.h"

// 21.04.2019 - termin

int main(void) {
    Game g;
    FrontendCLI front = FrontendCLI(g);
    Logic logic(g);
    front.draw();
    std::cout << std::endl;

    while(!std::cin.eof()) {
        std::cout << "> ";
        std::string input;
        std::cin >> input;
        BoardPosition from, to;
        from = g.board.get(input.substr(0, 2));
        to = g.board.get(input.substr(2, 2));
        Move move = { from, to };
        if(input.size() != 4 || !logic.is_move_valid(move)) {
            std::cout << "Invalid move " << input << std::endl;
            continue;
        }
        g.board.set(move);
        front.draw();
        std::cout << std::endl;
    }
}

