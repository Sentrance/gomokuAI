//
// Created by 53269 on 05/12/2017.
//

#include "../../include/ai/MiniMax.hpp"

//Mémo : i = y / j = x

int MiniMax::getValue(int x, int y)
{
	int value = 0;

	if (terminate(x, y, PLAYER, 5))
		value += 2000000;
	if (terminate(x, y, OPPONENT, 5))
		value += 1000000;
	if (terminate(x, y, PLAYER, 4) == 2)
		value += 200000;
	if (terminate(x, y, OPPONENT, 4) == 2)
		value += 200000;
	if (terminate(x, y, PLAYER, 4) == 1)
		value += 10000;
	if (terminate(x, y, OPPONENT, 4) == 1)
		value += 10000;
	if (terminate(x, y, PLAYER, 3) == 2)
		value += 20000;
	if (terminate(x, y, OPPONENT, 3) == 2)
			value += 20000;
	if (terminate(x, y, PLAYER, 3) == 1)
		value += 1000;
	if (terminate(x, y, OPPONENT, 3) == 1)
			value += 1000;
	if (terminate(x, y, PLAYER, 2))
		value += 1000;
	if (terminate(x, y, OPPONENT, 2))
		value += 1000;
	return (value);
}

int MiniMax::terminate(int x, int y, int player, int align) {
    int k;
    int len;
    int r;
    int l;
	bool right;
	bool left;
	bool blockr;
	bool blockl;

    k = 0;
    while (k < 4) {
        r = 0;
        l = 0;
        len = 1;
		right = true;
		left = true;
		blockr = false;
		blockl = false;
		while (len < 5) {
            switch (k) {
                case 0:
                    if (right && y + len >= static_cast<int>(board.size())) {
                        r = len - 1;
						blockr = true;
						right = false;
                    }
                    if (right && board[x][y + len] != player) {
                        r = len - 1;
						if (board[x][y + len] != NONE)
							blockr = true;
						right = false;
                    }
                    if (left && y - len < 0) {
                        l = len - 1;
						blockl = true;
						left = false;
                    }
                    if (left && board[x][y - len] != player) {
                        l = len - 1;
						if (board[x][y - len] != NONE)
							blockl = true;
						left = false;
                    }
                    break;
                case 1:
                    if (right && (x + len >= static_cast<int>(board.size()) || y + len >= static_cast<int>(board.size()))) {
                        r = len - 1;
						blockr = true;
						right = false;
                    }
                    if (right && board[x + len][y + len] != player) {
                        r = len - 1;
						if (board[x + len][y + len] != NONE)
							blockr = true;
						right = false;
                    }
                    if (left && (x - len < 0 || y - len < 0)) {
                        l = len - 1;
						blockl = true;
						left = false;
                    }
                    if (left && board[x - len][y - len] != player) {
                        l = len - 1;
						if (board[x - len][y - len] != NONE)
							blockl = true;
                        left = false;
                    }
                    break;
                case 2:
                    if (right && x + len >= static_cast<int>(board.size())) {
                        r = len - 1;
						blockr = true;
						right = false;
                    }
                    if (right && board[x + len][y] != player) {
                        r = len - 1;
						if (board[x + len][y] != NONE)
							blockr = true;
                        right = false;
                    }
                    if (left && x - len < 0) {
						l = len - 1;
						blockl = true;
						left = false;
                    }
                    if (left && board[x - len][y] != player) {
                        l = len - 1;
						if (board[x - len][y] != NONE)
							blockl = true;
                        left = false;
                    }
                    break;
                case 3:
                    if (right && (x - len < 0 || y + len >= static_cast<int>(board.size()))) {
                        r = len - 1;
						blockr = true;
						right = false;
                    }
                    if (right && board[x - len][y + len] != player) {
                        r = len - 1;
						if (board[x - len][y + len] != NONE)
							blockr = true;
                        right = false;
                    }
                    if (left && (x + len >= static_cast<int>(board.size()) || y - len < 0)) {
                        l = len - 1;
						blockl = true;
						left = false;
                    }
                    if (left && board[x + len][y - len] != player) {
                        l = len - 1;
						if (board[x + len][y - len] != NONE)
							blockl = true;
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
		{
			if (blockr && blockl)
				return (0);
			if (!blockr && !blockl)
				return (2);
			if ((blockr && !blockl) || (!blockr && blockl))
				return (1);
		}
        k++;
    }
    return (0);
}

MiniMax::MiniMax(const std::vector<std::vector<int>> &board) {
    this->board = board;
    hasEnded = false;
}

MoveData MiniMax::getBestPlay(int x, int y) {
    std::vector<MoveData> moveDataV;
    MoveData tempMoveData{};

    for (int i = 0; i < static_cast<int>(board.size()); i++) {
        for (int j = 0; j < static_cast<int>(board.size()); j++) {
            if (board[i][j] == NONE) {
                tempMoveData.x = j;
                tempMoveData.y = i;
                tempMoveData.value = getValue(i, j);
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

MoveData MiniMax::decideMove(int depth) {
    std::vector<MoveData> allMoves = getAllMoves(PLAYER);
    MoveData bestMove{};
    bestMove.value = -1;
    int current;
    boardCpy = board;

    for (MoveData moveData : allMoves) {
        boardCpy[moveData.y][moveData.x] = PLAYER;

        current = minMove(depth, -50000000, 50000000, moveData);

        if (bestMove.value == -1 || bestMove.value < current)
            bestMove = moveData;
        boardCpy[moveData.y][moveData.x] = NONE;
        if (hasEnded)
            break;
    }
    return bestMove;
}

int MiniMax::minMove(int depth, int alpha, int beta, MoveData prevMove) {
    int result;

    if (depth == 0 || hasEnded)
        return prevMove.value;
    result = 5000000;
    std::vector<MoveData> allMoves = getAllMoves(OPPONENT);
    for (MoveData newMove : allMoves) {
        boardCpy[newMove.y][newMove.x] = OPPONENT;
        int score = maxMove(depth - 1, alpha, beta, newMove);
        boardCpy[newMove.y][newMove.x] = NONE;

        result = (result < score) ? result : score;
        beta = (score < beta) ? score : beta;
        if (beta <= alpha)
            break;
    }
    return result;
}


int MiniMax::maxMove(int depth, int alpha, int beta, MoveData prevMove) {
    int result;

    if (depth == 0 || hasEnded)
        return prevMove.value;
    result = -5000000;
    std::vector<MoveData> allMoves = getAllMoves(PLAYER);
    for (MoveData newMove : allMoves) {
        boardCpy[newMove.y][newMove.x] = PLAYER;
        int score = maxMove(depth - 1, alpha, beta, newMove);
        boardCpy[newMove.y][newMove.x] = NONE;

        result = (result > score) ? result : score;
        alpha = (score > alpha) ? score : alpha;
        if (beta <= alpha)
            break;
    }
    return result;
}

std::vector<MoveData> MiniMax::getAllMoves(int player) {
    std::vector<MoveData> moveDataV;
    MoveData tempMoveData{};

    for (int i = 0; i < static_cast<int>(board.size()); i++) {
        for (int j = 0; j < static_cast<int>(board.size()); j++) {
            if (board[i][j] == NONE) {
                tempMoveData.x = j;
                tempMoveData.y = i;
                tempMoveData.value = getValue(i, j);
                moveDataV.push_back(tempMoveData);
            }
        }
    }

    //todo: à enlever lorsqu'on fera l'iterative deepening
    std::vector<MoveData> allMoves;
    for (auto e : moveDataV) {
        if (e.value > 100)
            allMoves.push_back(e);
    }
    return allMoves;
}