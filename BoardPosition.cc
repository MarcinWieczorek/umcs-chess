#include "BoardPosition.h"
#include "Constants.h"

BoardPosition::BoardPosition() {
    x = -1;
    y = -1;
    white = false;
    figure = FIGURE_EMPTY;
}

BoardPosition::BoardPosition(std::string &str) {
    x = str[0];
    y = str[1] - '0';
    white = false;
    figure = FIGURE_EMPTY;
}

bool BoardPosition::is_empty() {
    return this->figure == FIGURE_EMPTY;
}

