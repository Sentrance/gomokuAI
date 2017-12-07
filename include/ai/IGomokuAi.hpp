//
// Created by 53269 on 28/11/2017.
//

#ifndef GOMUKO_IGOMUKOAI_HPP
#define GOMUKO_IGOMUKOAI_HPP

#include <string>

class IGomokuAi {
    /*
     * Destructor
     */
public:
    virtual ~IGomokuAi() = default;

    /*
     * Methods
     */
protected:
    //First call to tell you to create a new board.
    virtual int gomoStart(int size) = 0;

    //Expects you to make a move. The params are the last opponents move.
    virtual int gomoTurn(int x, int y) = 0;

    //Expects you to make a move. This method means you are the first to play.
    virtual int gomoBegin() = 0;

    //Forces you to get a new field.
    virtual int gomoBoard(std::vector<std::string> &newBoard) = 0;

    //Expects you to know game parameters. You can ignore them, but if you exeed the time limit you lose.
    virtual int gomoInfo(const std::string &infoKey) = 0;

    //Expects you to terminate as soon as possible without any output.
    virtual int gomoEnd() = 0;

    //Expects you to send a one line information about the program.
    // Each info must be written as keyword, equals sign, text value in quotation marks.
    // Recommended keywords are name, version, author, country, www, email.
    // Values should be separated by commas that can be followed by spaces.
    virtual int gomoAbout() = 0;
};

#endif //GOMUKO_IGOMUKOAI_HPP
