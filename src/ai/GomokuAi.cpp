//
// Created by 53269 on 28/11/2017.
//

#include <vector>
#include <tuple>
#include <chrono>
#include <unistd.h>
#include "../../include/ai/GomokuAi.hpp"

//TODO: On doit aussi limiter la size de la board (pour qu'elle soit de 5 à 20)
int GomokuAi::gomoStart(unsigned int size) {
    gomoSendStart(true);

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

    gomoSendTurn(bestMove.x, bestMove.y);
    board[bestMove.x][bestMove.y] = PLAYER;
    return 0;
}

int GomokuAi::gomoBegin() {
    if (miniMax == nullptr)
        miniMax = new MiniMax(board);
    gomoSendTurn(9, 9);
    board[9][9] = PLAYER;
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