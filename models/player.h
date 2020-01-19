#ifndef GENERALA_PLAYER_H
#define GENERALA_PLAYER_H

#include <string>
#include <map>
#include <iostream>

#define ONES 1
#define TWOS 2
#define THREES 3
#define FOURS 4
#define FIVES 5
#define SIXES 6

class player {
private:
    std::string name;
public:
    [[nodiscard]] const std::string &getName() const;

private:
    unsigned int score;
    std::map<int, bool> combinationsAvailable;
public:
    explicit player(std::string name);

public:
    [[nodiscard]] unsigned int getScore() const;

    void addScore(int score);

    bool combinationAvailable(int);

    void scratchCategory(int);
};


#endif //GENERALA_PLAYER_H
