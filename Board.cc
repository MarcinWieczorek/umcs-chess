#include "Board.h"
#include "Game.h"
#include <iostream> //TODO DEBUG

void Board::generate() {
    // for(int y = 1; y <= 8; y++) {
    //     for(char x = 'a'; x <= 'h'; x++) {
    //         std::cout << "Resetting: " << x << ", " << y << std::endl;
    //         // BoardPosition &pos = this->getGame().board.get(x, y);
    //         // char c = pos.figure;
    //         this->set(x, y, FIGURE_EMPTY, true);
    //     }
    // }
    for(char x = 'a'; x <= 'h'; x++) {
        set(x, 2, FIGURE_PAWN, true);
        set(x, 7, FIGURE_PAWN, false);
    }
    // set("b2", FIGURE_PAWN, true);
}

void Board::set(std::string pos, int figure, bool white) {
    // int x = pos[0] - 'a';
    char x = pos[0];
    // int y = (pos[1] - '1');
    int y = pos[1] - '0';
    // std::cout << "DEBUG: set(" << x << ", " << y << ") " << (white ? "white" : "black") << std::endl;
    set(x, y, figure, white);
}

void Board::set(char x, int y, int figure, bool white) {
    x -= 'a';
    y = 8 - y;
    BoardPosition &pos = get(x, y);
    std::cout << "DEBUG: " << (int)x << ", " << y << std::endl;
    pos.x = x;
    pos.y = y;
    pos.figure = figure;
    pos.white = white;
}

BoardPosition &Board::get(int x, int y) {
    // std::cout << "DEBUG: get: " << y * 8 + x << std::endl;
    return this->data[y * 8 + x];
}

BoardPosition &Board::get(std::string str) {
    std::cout << "Getting by string: '" << str << "'" << std::endl;
    return get(str[0] - 'a', 8 - (str[1] - '0'));
}

void Board::set(Move &move) {
    std::cout << "DEBUG: moving from " << move.from.x << move.from.y << " to " << move.to.x << move.to.y << std::endl;
    set(move.from);
    set(move.to);
}

void Board::set(BoardPosition &bp) {
    set(bp.x, bp.y, bp.figure, bp.white);
}

