//
// Created by 53269 on 06/12/2017.
//

#ifndef GOMOKU_IDTHREAD_HPP
#define GOMOKU_IDTHREAD_HPP

#include <thread>
#include <vector>
#include "../MiniMax.hpp"

class IDThread {
    /*
     * Variables
     */
private:
    MiniMax *miniMax;
    std::vector<std::vector<int>> board;
    int depth;

public:
    MoveData bestMoveEver;
    bool hasEnded;

    /*
     * Constructor and destructor
     */
public:
    IDThread(const std::vector<std::vector<int>> &board, int depth);
    ~IDThread() = default;

    /*
     * Methods
     */
public:
    void start();
	std::thread startThread() {
		return std::thread([=] { start(); });
	}
};


#endif //GOMOKU_IDTHREAD_HPP
