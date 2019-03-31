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

    while(true) {
        std::cout << "> ";
        std::string input;
        std::cin >> input;
        BoardPosition from, to;
        from = g.board.get(input.substr(0, 2));
        to = g.board.get(input.substr(2, 2));
        from.x = input[0];
        from.y = input[1] - '0';
        to.x = input[2];
        to.y = input[3] - '0';
        to.figure = from.figure;
        from.figure = FIGURE_EMPTY;
        from.white = true;
        to.white = true;
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

