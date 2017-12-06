//
// Created by 53269 on 05/12/2017.
//

#include "../../include/ai/MiniMax.hpp"

//Mémo : i = y / j = x
int MiniMax::getValue(int i, int j, int player) {
    int k;
    int len;
    int value = 0;
    int r;
    int l;
    bool right;
    bool left;

    if (terminate(i, j, PLAYER, 5))
        value += 200000;
    if (terminate(i, j, OPPONENT, 5))
        value += 100000;
    if (terminate(i, j, PLAYER, 4))
        value += 10000;
    if (terminate(i, j, OPPONENT, 4))
        value += 10000;
    if (terminate(i, j, PLAYER, 3))
        value += 1000;
    if (terminate(i, j, OPPONENT, 3))
        value += 1000;
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
                    if (right && board[i][j + len] == player) {
                        r = len - 1;
                        right = false;
                    }
                    if (left && j - len < 0) {
                        l = len - 1;
                        left = false;
                    }
                    if (left && board[i][j - len] == player) {
                        l = len - 1;
                        left = false;
                    }
                    break;
                case 1:
                    if (right && (i + len >= board.size() || j + len >= board.size())) {
                        r = len - 1;
                        right = false;
                    }
                    if (right && board[i + len][j + len] == player) {
                        r = len - 1;
                        right = false;
                    }
                    if (left && (i - len < 0 || j - len < 0)) {
                        l = len - 1;
                        left = false;
                    }
                    if (left && board[i - len][j - len] == player) {
                        l = len - 1;
                        left = false;
                    }
                    break;
                case 2:
                    if (right && i + len >= board.size()) {
                        r = len - 1;
                        right = false;
                    }
                    if (right && board[i + len][j] == player) {
                        r = len - 1;
                        right = false;
                    }
                    if (left && i - len < 0) {
                        l = len - 1;
                        left = false;
                    }
                    if (left && board[i - len][j] == player) {
                        l = len - 1;
                        left = false;
                    }
                    break;
                case 3:
                    if (right && (i - len < 0 || j + len >= board.size())) {
                        r = len - 1;
                        right = false;
                    }
                    if (right && board[i - len][j + len] == player) {
                        r = len - 1;
                        right = false;
                    }
                    if (left && (i + len >= board.size() || j - len < 0)) {
                        l = len - 1;
                        left = false;
                    }
                    if (left && board[i + len][j - len] == player) {
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

bool MiniMax::terminate(int x, int y, int player, int align) {
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
        if (r + l + 1 >= align)
            return (true);
        k++;
    }
    return (false);
}

MiniMax::MiniMax(const std::vector<std::vector<int>> &board) {
    this->board = board;
}

MoveData MiniMax::getBestPlay(int x, int y) {
    std::vector<MoveData> moveDataV;
    MoveData tempMoveData{};

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            if (board[i][j] == NONE) {
                tempMoveData.x = j;
                tempMoveData.y = i;
                tempMoveData.value = getValue(i, j, OPPONENT);
                moveDataV.push_back(tempMoveData);
            }
        }
    }

    //todo: à enlever lorsqu'on fera l'iterative deepening
    MoveData bestMove{};
    bestMove.value = -1;
    for (auto e : moveDataV) {
        if (e.value > bestMove.value)
            bestMove = e;
    }
    return bestMove;
}

void MiniMax::updateBoard(const std::vector<std::vector<int>> &board) {
    this->board = board;
}
