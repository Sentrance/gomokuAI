//
// Created by 53269 on 05/12/2017.
//

#ifndef GOMOKU_MINIMAX_HPP
#define GOMOKU_MINIMAX_HPP

#include "AGomokuAi.hpp"
#include <vector>

class MiniMax {
    /*
     * Variables
     */
private:
    std::vector<std::vector<int>> board;

    /*
     * Constructor / Destructor
     */
public:
    explicit MiniMax(const std::vector<std::vector<int>> &board);
    ~MiniMax() = default;

    /*
     * Methods
     */
public:
    MoveData getBestPlay(int x, int y);
    int getValue(int i, int j, int player);
    bool terminate(int x, int y, int player, int align);
    //todo: enlever ça aussi
    void updateBoard(const std::vector<std::vector<int>> &board);
};


#endif //GOMOKU_MINIMAX_HPP
