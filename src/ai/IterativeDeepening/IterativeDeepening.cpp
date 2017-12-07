//
// Created by 53269 on 06/12/2017.
//

#include <thread>
#include <chrono>
#include "../../../include/ai/IterativeDeepening/IterativeDeepening.hpp"
#include "../../../include/ai/IterativeDeepening/IDThread.hpp"

MoveData IterativeDeepening::makeMove(int depth) {
    std::chrono::time_point<std::chrono::system_clock> start, now;



    MoveData bestMove{};
    bestMove.value = -1;

    //TODO: deepening thread à appeler ici
    IDThread *iDThread = new IDThread(board, depth);
	std::thread thread = iDThread->startThread();
//  iDThread->start();

    start, now = std::chrono::system_clock::now();
    while (std::chrono::duration_cast<std::chrono::seconds>(now - start).count() < timeLimit || bestMove.value == -1) {
        bestMove = iDThread->bestMoveEver;
		/*
		if (bestMove.value == -1)
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
        else
		*/
		bestMoveEver = bestMove;
        if (iDThread->hasEnded)
            break;
        now = std::chrono::system_clock::now();
    }
    iDThread->hasEnded = true;
    bestMoveEver = iDThread->bestMoveEver;
    return bestMoveEver;
}