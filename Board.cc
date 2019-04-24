#include "Board.h"
#include "Constants.h"
#include <iostream> //TODO DEBUG

void Board::generate() {
    // Clear the board
    for(int y = 1; y <= 8; y++) {
        for(char x = 'a'; x <= 'h'; x++) {
            this->set(x, y, FIGURE_EMPTY, true);
        }
    }

    // Knights
    set('b', 1, FIGURE_KNIGHT, true);
    set('g', 1, FIGURE_KNIGHT, true);
    set('b', 8, FIGURE_KNIGHT, false);
    set('g', 8, FIGURE_KNIGHT, false);

    // Pawns
    for(char x = 'a'; x <= 'h'; x++) {
        set(x, 2, FIGURE_PAWN, true);
        set(x, 7, FIGURE_PAWN, false);
    }
}

void Board::set(std::string pos, int figure, bool white) {
    char x = pos[0];
    int y = pos[1] - '0';
    set(x, y, figure, white);
}

void Board::set(char x, int y, int figure, bool white) {
    BoardPosition &pos = get(x, y);
    pos.x = x;
    pos.y = y;
    pos.figure = figure;
    pos.white = white;
}

BoardPosition &Board::get(char x, int y) {
    // std::cout << "DEBUG: get: " << y * 8 + x << std::endl;
    return this->data[(8 - y) * 8 + x];
}

BoardPosition &Board::get(std::string str) {
    return get(str[0], str[1] - '0');
}

void Board::set(Move move) {
    move.to.figure = move.from.figure;
    move.from.figure = FIGURE_EMPTY;
    move.to.white = move.from.white;
    set(move.from);
    set(move.to);
}

void Board::undo(Move move) {
    set(move.from);
    set(move.to);
}

void Board::set(BoardPosition &bp) {
    set(bp.x, bp.y, bp.figure, bp.white);
}

