//
// Created by 53269 on 06/12/2017.
//

#include "../../../include/ai/IterativeDeepening/IDThread.hpp"
#include "../../../include/ai/AGomokuAi.hpp"
IDThread::IDThread(const std::vector<std::vector<int>> &board, int depth) {
    this->board = board;
    this->depth = depth;
}

void IDThread::start() {
    MoveData bestMove;
    bestMove.value = -1;

    //TODO: coder ici
    while (depth++) {
        miniMax = new MiniMax(board);
        MoveData newMove = miniMax->decideMove(depth);
        if (bestMove.value == -1 || newMove.value > bestMove.value) {
            bestMove = newMove;
            bestMoveEver = bestMove;
        }

        if (hasEnded)
            break;
    }
    //bestMoveEver = miniMax.getBestEver();
    hasEnded = true;
    delete(miniMax);
}