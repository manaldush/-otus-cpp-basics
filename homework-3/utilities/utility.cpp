#include <iostream>
#include <fstream>
#include <string>
#define MAX_VALUE "100"
#define STATS_FILE "stats.txt"


namespace utilities {

    char* getArgument(int argc, char** argv, std::string argName) {

        if (argc > 1) {
            for(int index = 1; index < argc;++index) {
                std::string arg{ argv[index] };
                if (argName == arg && ++index < argc) {
                    return argv[index];
                }
            }
        }

        return MAX_VALUE;
    }

    int getMaxArgument(int argc, char** argv) {
        int maxValue = std::stoi(getArgument(argc, argv, "-max"));
        return maxValue;
    }

    bool hasArgument(int argc, char** argv, char* argName) {
        if (argc > 1) {
            for(int index = 1; index < argc;++index) {
                std::string arg{ argv[index] };
                if (argName == arg) {
                    return true;
                }
            }
        }

        return false;
    }

    std::string getName() {

        std::string name;

        std::cout << "Enter please your name" << std::endl;
        std::cin  >> name;
        std::cout << "Your name is " << name << std::endl;
    
        return name;
    }

    int getRandomNumber(int maxValue) {
        std::srand(std::time(nullptr));
        int value = std::rand() % maxValue;

        return value;
    }

    unsigned int guess(int value) {

        unsigned int attempts = 0;
        int attemptNumber;
        do {

            std::cout << "Attempt number " << ++attempts << std::endl;
            std::cin >> attemptNumber;
            if (attemptNumber > value) {
                std::cout << "Less then" << std::endl;
            } else if (attemptNumber < value) {
                std::cout << "More then" << std::endl;
            }
        } while(attemptNumber != value);

        std::cout << "You win, attempts number = " << attempts << std::endl;

        return attempts;
    }

    void saveScore(std::string name, unsigned int attempts) {

        std::ofstream out_file{STATS_FILE, std::ios_base::app};
		if (!out_file.is_open()) {
			std::cout << "Failed to open file for append: " << STATS_FILE << "!" << std::endl;
		} else {
            out_file << name << ' ';
		    out_file << attempts;
		    out_file << std::endl;
            out_file.close();
        }
    }

    void printStats() {
        std::ifstream in{STATS_FILE};

        if (!in.is_open()) {
			std::cout << "Failed to open file for read: " << STATS_FILE << "!" << std::endl;
		} else {
		    std::cout << "Statistics table:" << std::endl;

		    std::string name;
		    int score = 0;
		    while (true) {
			    in >> name;
			    in >> score;
			    in.ignore();
			    if (in.fail()) {
				    break;
			    }
                std::ios::pos_type position = in.tellg();
                std::string name2;
		        int score2;
                in.clear();
                in.seekg(0);
                while(true) {
			        in >> name2;
			        in >> score2;
			        in.ignore();
			        if (in.fail()) {
                        std::cout << name << '\t' << score << std::endl;
				        break;
			        }
                    if (name == name2) {
                        if (score > score2) {
                            break;
                        } else if (score == score2 && position < in.tellg()) {
                            //print last
                            break;
                        }
                    }
                }
                in.clear();
                in.seekg(position);
		    }

            in.close();
        }
    }
}