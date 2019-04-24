#include <iostream>
#include <string>

#include "Game.h"
#include "Logic.h"
#include "FrontendCLI.h"
#include "ai/Minimax.h"

// 21.04.2019 - termin

int main(void) {
    Game g;
    FrontendCLI front = FrontendCLI(g);
    Logic logic(g);
    front.draw();
    std::cout << std::endl;
    AIMinimax ai_black(g, false);
    AIMinimax ai_white(g, true);

    while(!std::cin.eof()) {
#if 0
        std::cout << "> ";
        std::string input;
        std::cin >> input;
        BoardPosition from, to;
        from = g.board.get(input.substr(0, 2));
        to = g.board.get(input.substr(2, 2));
        // from.x = input[0];
        // from.y = input[1] - '0';
        // to.x = input[2];
        // to.y = input[3] - '0';
        // to.figure = from.figure;
        // from.figure = FIGURE_EMPTY;
        // from.white = true;
        // to.white = true;
        Move move = { from, to };
        if(input.size() != 4 || !logic.is_move_valid(move)) {
            std::cout << "Invalid move " << input << std::endl;
            continue;
        }
        g.board.set(move);
#endif
#if 1
        std::cout << "White Thinking..." << std::endl;
        Move move = ai_white.find_best_move();
        if(move.from.is_empty()) {
            break;
        }
        std::cout << "AI found move: " << move.from.x << move.from.y << " -> " << move.to.x << move.to.y << std::endl;
        g.board.set(move);
        front.draw();
#endif

        std::cout << "Black Thinking..." << std::endl;
        move = ai_black.find_best_move();
        std::cout << "AI found move: " << move.from.x << move.from.y << " -> " << move.to.x << move.to.y << std::endl;
        g.board.set(move);
        front.draw();
        if(move.from.x == 'a' && move.to.x == 'h' && move.from.y == 2 && move.to.y == 2) {
            break;
        }
        // std::cout << std::endl;
    }
}

