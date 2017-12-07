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
    std::vector<std::vector<int>> boardCpy;

public:
    bool hasEnded;
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

    MoveData decideMove(int depth);
    int minMove(int depth, int alpha, int beta, MoveData prevMove);
    int maxMove(int depth, int alpha, int beta, MoveData prevMove);
    std::vector<MoveData> getAllMoves(int player);
};


#endif //GOMOKU_MINIMAX_HPP
