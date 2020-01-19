//
// Created by mishi9 on 19-01-20.
//

#include "scoring.h"

void sortDice(std::vector<die> &dice);

int calculateOnes(std::vector<die> &dice) {
    if (dice.size() != 5) {
        return SCORE_NOT_PRESENT;
    }

    int i = 0;
    for (die d : dice) {
        if (d.getSide() == 1) {
            i++;
        }
    }
    if (i == 0) {
        return SCORE_NOT_PRESENT;
    }
    return i * P_ONES;
}

int calculateTwos(std::vector<die> &dice) {
    if (dice.size() != 5) {
        return SCORE_NOT_PRESENT;
    }

    int i = 0;
    for (die d : dice) {
        if (d.getSide() == 2) {
            i++;
        }
    }
    if (i == 0) {
        return SCORE_NOT_PRESENT;
    }
    return i * P_TWOS;
}

int calculateThrees(std::vector<die> &dice) {
    if (dice.size() != 5) {
        return SCORE_NOT_PRESENT;
    }

    int i = 0;
    for (die d : dice) {
        if (d.getSide() == 3) {
            i++;
        }
    }
    if (i == 0) {
        return SCORE_NOT_PRESENT;
    }
    return i * P_THREES;
}

int calculateFours(std::vector<die> &dice) {
    if (dice.size() != 5) {
        return SCORE_NOT_PRESENT;
    }

    int i = 0;
    for (die d : dice) {
        if (d.getSide() == 4) {
            i++;
        }
    }
    if (i == 0) {
        return SCORE_NOT_PRESENT;
    }
    return i * P_FOURS;
}

int calculateFives(std::vector<die> &dice) {
    if (dice.size() != 5) {
        return SCORE_NOT_PRESENT;
    }

    int i = 0;
    for (die d : dice) {
        if (d.getSide() == 5) {
            i++;
        }
    }
    if (i == 0) {
        return SCORE_NOT_PRESENT;
    }
    return i * P_FIVES;
}

int calculateSixes(std::vector<die> &dice) {
    if (dice.size() != 5) {
        return SCORE_NOT_PRESENT;
    }

    int i = 0;
    for (die d : dice) {
        if (d.getSide() == 6) {
            i++;
        }
    }
    if (i == 0) {
        return SCORE_NOT_PRESENT;
    }
    return i * P_SIXES;
}

int calculateStraight(std::vector<die> &dice) {
    if (dice.size() != 5) {
        return SCORE_NOT_PRESENT;
    }

    // Rules say that if all numbers are different there's a straight
    sortDice(dice);
    auto identicalAt = std::adjacent_find(dice.begin(), dice.end());
    if (identicalAt != dice.end()) {
        return SCORE_NOT_PRESENT;
    }

    // all elements different so we return the points
    return P_STRAIGHT;
}

int calculateFullHouse(std::vector<die> &dice) {
    if (dice.size() != 5) {
        return SCORE_NOT_PRESENT;
    }

    int occurences[6] = {0, 0, 0, 0, 0, 0};
    for (die d : dice) {
        occurences[d.getSide() - 1]++;
    }

    std::sort(std::begin(occurences), std::end(occurences));
    if (occurences[5] == 3 && occurences[4] == 2) {
        return P_FULL_HOUSE;
    }

    return SCORE_NOT_PRESENT;
}

int calculateFourOfAKind(std::vector<die> &dice) {
    if (dice.size() != 5) {
        return SCORE_NOT_PRESENT;
    }
    sortDice(dice);

    int i = 0;
    unsigned int prevSide = 0;
    for (die d : dice) {
        unsigned int currentSide = d.getSide();
        if (currentSide == prevSide) {
            i++;
            prevSide = currentSide;
        } else {
            i = 0;
            prevSide = currentSide;
        }
        if (i == 4) {
            return P_FOUR_OF_A_KIND;
        }
    }

    return SCORE_NOT_PRESENT;
}

int calculateGenerala(std::vector<die> &dice) {
    if (dice.size() != 5) {
        return SCORE_NOT_PRESENT;
    }

    // Check if all elements match
    const unsigned int first = dice.begin()->getSide();
    for (die d : dice) {
        if (d.getSide() != first) {
            return SCORE_NOT_PRESENT;
        }
    }

    // All match if function has still not returned so return the score for Generala.
    return P_GENERALA;
}

void sortDice(std::vector<die> &dice) {
    std::sort(dice.begin(), dice.end(),
              [](die &d1, die &d2) {
                  return d1.getSide() < d2.getSide();
              });
}
