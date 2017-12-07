//
// Created by 53269 on 28/11/2017.
//

#include <vector>
#include <tuple>
#include <chrono>
#include "../../include/ai/GomokuAi.hpp"
#include "../../include/ai/IterativeDeepening/IterativeDeepening.hpp"

int GomokuAi::gomoStart(int size) {
    if (size > 4 && size < 21)
        gomoSendStart(true);
    else
        gomoStart(false);
    std::vector<int> line;
    int data;
    int i = 0;
    data = NONE;
    while (i < size)
    {
        line.push_back(data);
        i++;
    }
    i = 0;
    while (i < size)
    {
        board.push_back(line);
        i++;
    }
    return 0;
}

int GomokuAi::gomoTurn(int ennemyX, int ennemyY) {
    board[ennemyY][ennemyX] = OPPONENT;

    if (miniMax == nullptr)
        miniMax = new MiniMax(board);
    miniMax->updateBoard(board);

    MoveData bestMove = miniMax->getBestPlay(ennemyX, ennemyY);
//    MoveData bestMove = miniMax->decideMove(2);
//    IterativeDeepening iterativeDeepening(board, 3);
//    MoveData bestMove = iterativeDeepening.makeMove(5);

    gomoSendTurn(bestMove.x, bestMove.y);
    board[bestMove.y][bestMove.x] = PLAYER;
    return 0;
}

int GomokuAi::gomoBegin() {
    if (miniMax == nullptr)
        miniMax = new MiniMax(board);
    gomoSendTurn(board.size()/2, board.size()/2);
    board[board.size()/2][board.size()/2] = PLAYER;
    return 0;
}

int GomokuAi::gomoInfo(const std::string &infoKey) {
    return 0;
}

int GomokuAi::gomoEnd(

) {
    return 0;
}

int GomokuAi::gomoAbout() {
    gomoSendAbout();
    return 0;
}

int GomokuAi::gomoBoard(std::vector<std::string> &newBoard) {
    gomoSendTurn(1, 1);
    return 0;
}

GomokuAi::GomokuAi() {
    about = R"(name="gomukobrain", version="1.0", author="Devia", country="FR")";
}