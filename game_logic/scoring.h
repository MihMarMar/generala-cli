//
// Created by mishi9 on 19-01-20.
//

#ifndef GENERALA_SCORING_H
#define GENERALA_SCORING_H

#include "game.h"

/*
 * Functions to calculate score. They return -1 if score cannot be calculated for the given dice combination.
 * Otherwise the score for the combination is returned.
 */


/**
 * Get the score of ones
 * @return The score for ones or -1 if not present
 */
int calculateOnes(std::vector<die> &);

/**
 * Get the score of twos
 * @return The score for twos or -1 if not present
 */
int calculateTwos(std::vector<die> &);

int calculateThrees(std::vector<die> &);

int calculateFours(std::vector<die> &);

int calculateFives(std::vector<die> &);

int calculateSixes(std::vector<die> &);

int calculateStraight(std::vector<die> &);

int calculateFullHouse(std::vector<die> &);

int calculateFourOfAKind(std::vector<die> &);

int calculateGenerala(std::vector<die> &);

#endif //GENERALA_SCORING_H
