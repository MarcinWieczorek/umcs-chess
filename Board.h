#pragma once
#include <string>

#include "BoardPosition.h"
#include "Move.h"

class Board {
    private:
    public:
        BoardPosition data[64];
        void generate();
        void set(char, int, int, bool);
        void set(std::string, int, bool);
        void set(BoardPosition &);
        void set(Move &);
        BoardPosition &get(char, int);
        BoardPosition &get(std::string);
};

