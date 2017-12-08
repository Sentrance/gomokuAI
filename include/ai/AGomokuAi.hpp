//
// Created by 53269 on 29/11/2017.
//

#ifndef GOMUKO_AGOMUKOAI_HPP
#define GOMUKO_AGOMUKOAI_HPP

#include <iostream>
#include <vector>
#include <sstream>
#include "IGomokuAi.hpp"

#define PLAYER 1
#define OPPONENT 2
#define NONE 0

typedef struct s_data
{
    int x;
    int y;
    int value;
} MoveData;

class AGomokuAi : public IGomokuAi {
    /*
     * Variables
     */
protected:
    std::string about;

    /*
     * Constructor and destructor
     */
public:
    AGomokuAi() { about = R"(name="UNKNOWN", version="UNKNOWN", author="UNKNOWN", country="UNKNOWN")"; };
    virtual ~AGomokuAi() = default;

    /*
     * Methods
     */

    //
    // COMMUNICATION METHODS
    //

    //Message sending methods
protected:
    void gomoSend(const std::string &toSend) {
        std::cout <<  toSend << std::endl;
    };
    void gomoSendStart(bool isOk) {
        if (isOk)
            return gomoSend("OK");
        return gomoSend("ERROR");
    }
    void gomoSendTurn(int x, int y) {
        gomoSend(std::to_string(x) + "," + std::to_string(y));
    }
    void gomoSendAbout() {
        gomoSend(about);
    }

public:
    //Receiving methods
    int gomoGo() {
        std::string line;

        while (std::getline(std::cin, line)) {
			gomoSend("DEBUG " + line);
            if (line.find("TURN") != std::string::npos) {
                line.erase(0, 5);

                std::vector<unsigned int> coord = split(line, ',');
                if (gomoTurn(coord[0], coord[1]) == 84)
                    return 84;
            }
            else if (strncmp("START", line.c_str(), 5) == 0) {
                line.erase(0, 6);

                if (gomoStart(static_cast<unsigned int>(std::stoi(line))) == 84)
                    return 84;
            }
            else if (line.find("BEGIN") != std::string::npos) {
                if (gomoBegin() == 84)
                    return 84;
            }
            else if (line.find("BOARD") != std::string::npos) {
                std::vector<std::string> board;
				while (std::getline(std::cin, line)) {
					if (line.compare("DONE"))
						if (gomoBoard(board) == 84)
							return 84;
					board.push_back(line);
				}
            }
            else if (line.find("INFO") != std::string::npos) {
                if (gomoInfo("DEBUG") == 84)
                    return 84;
            }
            else if (line.find("ABOUT") != std::string::npos) {
                std::wcerr << "Dans le about" << std::endl;
                if (gomoAbout() == 84)
                    return 84;
            }
            else if (line.find("END") != std::string::npos)
                return gomoEnd();
            else
                gomoSend("UNKNOWN Whoops, I didn't understood what you said! Maybe the command isn't implemented?");
        }
		return 0;
    };

    //
    // TOOLS
    //

    // Parse and split
    std::vector<unsigned int> split(const std::string &str, char delimiter) {
        std::vector<unsigned int> result;
        std::stringstream ss(str);
        std::string token;

        while(std::getline(ss, token, delimiter))
            result.push_back(static_cast<unsigned int>(std::stoi(token)));

        return result;
    }
};

#endif //GOMUKO_AGOMUKOAI_HPP
