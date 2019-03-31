#pragma once
#include <string>

class BoardPosition {
    private:
    public:
        BoardPosition();
        BoardPosition(std::string &);
        bool white;
        char x;
        int y;
        int figure;
        bool is_empty();
};

