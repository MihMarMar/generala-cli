#include "player.h"

#include <utility>

unsigned int player::getScore() const {
    return score;
}

void player::addScore(int points) {
    player::score += points;
}

player::player(std::string name) : name(std::move(name)) {
    score = 0;
    combinationsAvailable[ONES] = true;
    combinationsAvailable[TWOS] = true;
    combinationsAvailable[THREES] = true;
    combinationsAvailable[FOURS] = true;
    combinationsAvailable[FIVES] = true;
    combinationsAvailable[SIXES] = true;
}

bool player::combinationAvailable(int cat) {
    return combinationsAvailable[cat];
}

void player::scratchCategory(int cat) {
    if (!combinationsAvailable[cat]) {
        std::cout << "category already used";
        throw;
    }
    combinationsAvailable[cat] = false;
}

const std::string &player::getName() const {
    return name;
}
