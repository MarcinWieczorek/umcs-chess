#include <algorithm>
#include <cassert>
#include <iostream> //TODO debug

#include "Minimax.h"
#include "../Move.h"
#include "../Constants.h"

#define MINIMAX_DEBUG 0

AIMinimax::AIMinimax(Game &g, bool white) {
    this->game = &g;
    this->white = white;
}

Move AIMinimax::find_best_move() {
#if MINIMAX_DEBUG
    std::cout << "LOOKING FOR BEST MOVE" << std::endl;
#endif
    Move m;
    m.from.figure = FIGURE_EMPTY;
    minimax(4, true, m);
    return m;
}

int AIMinimax::minimax(int depth, bool is_max, Move &target) {
#if MINIMAX_DEBUG
    std::cout << "MINIMAX depth=" << depth << ", max=" << is_max << std::endl;
#endif
    if(depth == 0) {
        return this->evaluate();
    }
    // std::cout << "NOT ZERO depth=" << depth << std::endl;

    signed int best = is_max ? -9999 : 9999;
    std::vector<Move> moves = this->get_moves();

    if(moves.size() == 0) {
        std::cout << "MINIMAX has no moves!" << std::endl;
        return best;
    }
    Move notarget;
    for(Move m : moves) {
        this->game->board.set(m);
        int mbest = minimax(depth - 1, !is_max, notarget);
        // std::cout << "  MBEST: " << mbest << std::endl;

        if(is_max) {
            if(mbest > best) {
#if MINIMAX_DEBUG
                std::cout << "NEW MAX: " << best << " -> " << mbest << std::endl;
#endif
                target = m;
                best = mbest;
            }
        }
        else {
            if(mbest < best) {
#if MINIMAX_DEBUG
                std::cout << "NEW MIN: " << best << " -> " << mbest << std::endl;
#endif
                target = m;
                best = mbest;
            }
        }
        this->game->board.undo(m);
    }

    return best;
}

int AIMinimax::evaluate() {
    int score = 0;

    for(int x = 'a'; x <= 'h'; x++) {
        for(int y = 8; y > 0; y--) {
            int figure_score = 0;
            BoardPosition &pos = this->game->board.get(x, y);

            if(pos.is_empty()) {
                continue;
            }

            switch(pos.figure) {
                case FIGURE_PAWN:
                    figure_score = POWER_PAWN;
                    break;
                case FIGURE_KNIGHT:
                    figure_score = POWER_KNIGHT;
                    break;
            }

            if(pos.white != this->white) {
                figure_score *= -1;
            }

            score += figure_score;
        }
    }

#if MINIMAX_DEBUG
    if(score != 0)
        std::cout << "Evaluated score: " << score << std::endl;
#endif
    return score;
}

Move AIMinimax::move_construct(BoardPosition from, int x, int y) {
    BoardPosition to = this->game->board.get(from.x + x, from.y + y);
    assert(from.x + x >= 'a');
    assert(from.x + x <= 'h');
    assert(from.y + y >= 1);
    assert(from.y + y <= 8);
#if MINIMAX_DEBUG == 2
    std::cout << "Constructed move: " << from.x << from.y << " -> " << to.x << to.y << std::endl;
#endif

    return { from, to };
}

std::vector<Move> AIMinimax::get_moves() {
    std::vector<Move> moves;

    for(int x = 'a'; x <= 'h'; x++) {
        for(int y = 8; y > 0; y--) {
            BoardPosition &pos = this->game->board.get(x, y);
            int m = this->white ? 1 : -1;

            if(pos.white != this->white || pos.is_empty()) {
                continue;
            }

            if(pos.figure == FIGURE_PAWN) {
                if(this->white) {
                    if(pos.y == 8) {
                        continue;
                    }
                }
                else {
                    if(pos.y == 1) {
                        continue;
                    }
                }

                BoardPosition nearpos = this->game->board.get(x, y + 1*m);
                if(nearpos.is_empty()) {
                    moves.push_back(move_construct(pos, 0, 1 *m));
                }

                // First pawn move
                if((this->white && pos.y == 1) || (!this->white && pos.y == 7)) {
                    moves.push_back(move_construct(pos, 0, 2 *m));
                }

                if(x < 'h') {
                    nearpos = this->game->board.get(x + 1, y + 1*m);
                    if(!nearpos.is_empty() && nearpos.white != this->white) {
                        moves.push_back(move_construct(pos, 1, 1 *m));
                    }
                }

                if(x > 'a') {
                    nearpos = this->game->board.get(x - 1, y + 1*m);
                    if(!nearpos.is_empty() && nearpos.white != this->white) {
                        moves.push_back(move_construct(pos, -1, 1 *m));
                    }
                }
            }
            else if(pos.figure == FIGURE_KNIGHT) {
                int tx = 0, ty = 0;
                BoardPosition np;
                std::pair<int, int> options[8] = {
                    { -2, -1 },
                    { -2, +1 },
                    { +2, -1 },
                    { +2, +1 },
                    { -1, -2 },
                    { -1, +2 },
                    { +1, -2 },
                    { +1, +2 },
                };

                for(std::pair<int, int> &p : options) {
                    tx = p.first;
                    ty = p.second;
                    np = this->game->board.get(x + tx, y + ty);
                    if((np.is_empty() || np.white != this->white)
                            && x + tx >= 'a' && x + tx <= 'h'
                            && y + ty >= 1 && y + ty <= 8) {
                        moves.push_back(move_construct(pos, tx, ty));
                    }
                }
            }
        }
    }

    return moves;
}
