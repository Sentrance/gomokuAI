//
// Created by 53269 on 28/11/2017.
//

#ifndef GOMUKO_GOMUKOAI_HPP
#define GOMUKO_GOMUKOAI_HPP

#include <thread>
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
public:
    GomokuAi();
    virtual ~GomokuAi() = default;

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
    int gomoStart(int size) override;
};

#endif //GOMUKO_GOMUKOAI_HPP
