#include <iostream>
#include "../include/ai/GomokuAi.hpp"


void print_map(std::vector<std::vector<int>> board)
{
    for (auto i : board)
    {
        for (auto j : i)
        {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    GomokuAi *gomokuAi = new GomokuAi();

    gomokuAi->gomoStart(19);
    print_map(gomokuAi->board);
    return 0;
}