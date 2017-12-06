//
// Created by 53269 on 06/12/2017.
//

#include <chrono>
#include <unistd.h>
#include "../../../include/ai/IterativeDeepening/IterativeDeepening.hpp"
#include "../../../include/ai/IterativeDeepening/IDThread.hpp"

MoveData IterativeDeepening::makeMove(int depth) {
    std::chrono::time_point<std::chrono::system_clock> start, now;

    MoveData bestMove{};
    bestMove.value = -1;

    //TODO: deepening thread à appeler ici
    IDThread *iDThread = new IDThread(board, depth);
    iDThread->start();

    start, now = std::chrono::system_clock::now();
    while (std::chrono::duration_cast<std::chrono::seconds>(now - start).count() < 5 || bestMove.value == -1) {
        bestMove = iDThread->bestMoveEver;
        if (bestMove.value == -1)
            usleep(200);
        else
            bestMoveEver = bestMove;
        if (iDThread->hasEnded)
            break;
        now = std::chrono::system_clock::now();
    }
    iDThread->hasEnded = true;
    bestMoveEver = iDThread->bestMoveEver;
    return bestMoveEver;
}
