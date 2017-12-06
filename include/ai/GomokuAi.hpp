//
// Created by 53269 on 28/11/2017.
//

#ifndef GOMUKO_GOMUKOAI_HPP
#define GOMUKO_GOMUKOAI_HPP

#include <vector>
#include <array>
#include <tuple>
#include "AGomokuAi.hpp"
#include "MiniMax.hpp"

class GomokuAi final : public AGomokuAi {
    /*
     * Variables
     */
private:
    std::vector<std::vector<int>> board;
    MiniMax *miniMax = nullptr;

    /*
     * Constructor and destructor
     */

    int gomoStart(unsigned int size) override;

public:
    GomokuAi();
    virtual ~GomokuAi() = default;
    int getValue(int x, int y);
    bool terminate(int x, int y, int player);

    //Fonctions de décision des mouvement
    MoveData decideMove(int depth);
    int minScore(int depth, int a, int b, MoveData previousMove);
    int maxScore(int depth, int a, int b, MoveData previousMove);

    /*
     * Methods
     */

protected:
    int gomoTurn(int x, int y) override;
    int gomoBegin() override;
    int gomoBoard(std::vector<std::string> &newBoard) override;
    int gomoInfo(const std::string &infoKey) override;
    int gomoEnd() override;
    int gomoAbout() override;
};

#endif //GOMUKO_GOMUKOAI_HPP
