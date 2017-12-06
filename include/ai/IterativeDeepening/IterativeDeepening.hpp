//
// Created by 53269 on 06/12/2017.
//

#ifndef GOMOKU_ITERATIVEDEEPENING_HPP
#define GOMOKU_ITERATIVEDEEPENING_HPP


#include <vector>
#include "../AGomokuAi.hpp"

class IterativeDeepening {
    /*
     * Variables
     */
private:
    std::vector<std::vector<int>> board;
    int timeLimit;
    MoveData bestMoveEver;

    /*
     * Constructor and destructor
     */
public:
    IterativeDeepening(const std::vector<std::vector<int>> &board, int timeLimit) {
        this->board = board;
        this->timeLimit = timeLimit;
    }
    ~IterativeDeepening() = default;

    /*
     * Methods
     */
public:
    MoveData makeMove(int depth);
};


#endif //GOMOKU_ITERATIVEDEEPENING_HPP
