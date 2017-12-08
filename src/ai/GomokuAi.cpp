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
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			line.push_back(NONE);
		board.push_back(line);
	}
    return 0;
}

int GomokuAi::gomoTurn(int ennemyX, int ennemyY) {
    board[ennemyY][ennemyX] = OPPONENT;

    if (miniMax == nullptr)
        miniMax = new MiniMax(board);
    miniMax->updateBoard(board);

    MoveData bestMove = miniMax->decideMove(2);

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

int GomokuAi::gomoEnd() {
	board.clear();
	delete(miniMax);
    return 0;
}

int GomokuAi::gomoAbout() {
    gomoSendAbout();
    return 0;
}

int GomokuAi::gomoBoard(std::vector<std::string> &newBoard) {
	if (board.size() == 0) {
		gomoStart(19);
		return gomoBegin();
	} else {
		std::vector<unsigned int> coord;
		for (int i = 0; i < static_cast<int>(board.size()); i++)
			for (int j = 0; j < static_cast<int>(board.size()); j++)
				board[i][j] = 0;
		for (std::string newInfo : newBoard) {
			coord = split(newInfo, ',');
			board[coord[1]][coord[0]] = coord[2];
		}
		gomoTurn(coord[0], coord[1]);
	}
	return 0;
}

GomokuAi::GomokuAi() {
    about = R"(name="gomukobrain", version="1.0", author="Devia", country="FR")";
}