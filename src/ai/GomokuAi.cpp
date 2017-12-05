//
// Created by 53269 on 28/11/2017.
//

#include <vector>
#include <tuple>
#include "../../include/ai/GomokuAi.hpp"

//TODO: gomoSend est à changer (correspond à la réponse attendu par le programme)
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

int GomokuAi::gomoTurn(unsigned int ennemyX, unsigned int ennemyY) {
    board[ennemyX][ennemyY] = OPPONENT;
//    gomoSendTurn(1, 1);
    return 0;
}

int GomokuAi::gomoBegin() {
//    gomoSendTurn(1, 1);
    return 0;
}

int GomokuAi::gomoInfo(const std::string &infoKey) {
    return 0;
}

int GomokuAi::gomoEnd() {
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

int GomokuAi::maxScore(int depth, int a, int b, MoveData previousMove)
{
    //todo: coder le maximise
}

int GomokuAi::minScore(int depth, int a, int b, MoveData previousMove)
{
    //todo: coder le minimise
}

MoveData GomokuAi::decideMove(int depth)
{
    return MoveData();
}

bool GomokuAi::terminate(int x, int y, int player)
{
    int k;
    int len;
    int r;
    int l;
    bool right;
    bool left;

    k = 0;
    while (k < 4) {
        r = 0;
        l = 0;
        len = 1;
        right = true;
        left = true;
        while (len < 5) {
            switch (k) {
                case 0:
                    if (right && x + len >= board.size()) {
                        r = len - 1;
                        right = false;
                    }
                    if (right && board[x][y + len] != player) {
                        r = len - 1;
                        right = false;
                    }
                    if (left && y - len < 0) {
                        l = len - 1;
                        left = false;
                    }
                    if (left && board[x][y - len] != player) {
                        l = len - 1;
                        left = false;
                    }
                    break;
                case 1:
                    if (right && (x + len >= board.size() || y + len >= board.size())) {
                        r = len - 1;
                        right = false;
                    }
                    if (right && board[x + len][y + len] != player) {
                        r = len - 1;
                        right = false;
                    }
                    if (left && (x - len < 0 || y - len < 0)) {
                        l = len - 1;
                        left = false;
                    }
                    if (left && board[x - len][y - len] != player) {
                        l = len - 1;
                        left = false;
                    }
                    break;
                case 2:
                    if (right && x + len >= board.size()) {
                        r = len - 1;
                        right = false;
                    }
                    if (right && board[x + len][y] != player) {
                        r = len - 1;
                        right = false;
                    }
                    if (left && x - len < 0) {
                        l = len - 1;
                        left = false;
                    }
                    if (left && board[x - len][y] != player) {
                        l = len - 1;
                        left = false;
                    }
                    break;
                case 3:
                    if (right && (x - len < 0 || y + len >= board.size())) {
                        r = len - 1;
                        right = false;
                    }
                    if (right && board[x - len][y + len] != player) {
                        r = len - 1;
                        right = false;
                    }
                    if (left && (x + len >= board.size() || y - len < 0)) {
                        l = len - 1;
                        left = false;
                    }
                    if (left && board[x + len][y - len] != player) {
                        l = len - 1;
                        left = false;
                    }
                    break;
                default:
                    break;
            }
            len++;
        }
        if (right)
            r = 4;
        if (left)
            l = 4;
        if (r + l + 1 >= 5)
            return (true);
        k++;
    }
    return (false);
}

int GomokuAi::getValue(int i, int j) {
    int k;
    int len;
    int value = 0;
    int r;
    int l;
    bool right;
    bool left;

    k = 0;
    while (k < 4) {
        r = 0;
        l = 0;
        len = 1;
        right = true;
        left = true;
        while (len < 5) {
            switch (k) {
                case 0:
                    if (right && j + len >= board.size()) {
                        r = len - 1;
                        right = false;
                    }
                    if (right && board[i][j + len] == OPPONENT) {
                        r = len - 1;
                        right = false;
                    }
                    if (left && j - len < 0) {
                        l = len - 1;
                        left = false;
                    }
                    if (left && board[i][j - len] == OPPONENT) {
                        l = len - 1;
                        left = false;
                    }
                    break;
                case 1:
                    if (right && (i + len >= board.size() || j + len >= board.size())) {
                        r = len - 1;
                        right = false;
                    }
                    if (right && board[i + len][j + len] == OPPONENT) {
                        r = len - 1;
                        right = false;
                    }
                    if (left && (i - len < 0 || j - len < 0)) {
                        l = len - 1;
                        left = false;
                    }
                    if (left && board[i - len][j - len] == OPPONENT) {
                        l = len - 1;
                        left = false;
                    }
                    break;
                case 2:
                    if (right && i + len >= board.size()) {
                        r = len - 1;
                        right = false;
                    }
                    if (right && board[i + len][j] == OPPONENT) {
                        r = len - 1;
                        right = false;
                    }
                    if (left && i - len < 0) {
                        l = len - 1;
                        left = false;
                    }
                    if (left && board[i - len][j] == OPPONENT) {
                        l = len - 1;
                        left = false;
                    }
                    break;
                case 3:
                    if (right && (i - len < 0 || j + len >= board.size())) {
                        r = len - 1;
                        right = false;
                    }
                    if (right && board[i - len][j + len] == OPPONENT) {
                        r = len - 1;
                        right = false;
                    }
                    if (left && (i + len >= board.size() || j - len < 0)) {
                        l = len - 1;
                        left = false;
                    }
                    if (left && board[i + len][j - len] == OPPONENT) {
                        l = len - 1;
                        left = false;
                    }
                    break;
                default:
                    break;
            }
            len++;
        }
        if (right)
            r = 4;
        if (left)
            l = 4;
        if (r + l + 1 > 4)
            value += (r + l + 1) - 5 + 1;
        else
            value += 0;
        k++;
    }
    return (value);
}