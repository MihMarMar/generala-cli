//
// Created by mishi9 on 19-01-20.
//

#ifndef GENERALA_SCORING_H
#define GENERALA_SCORING_H

#include "game.h"

/**
 * calculate score for the given category
 * @param1 dice
 * @param2 category
 * @return
 */
int calculateScore(std::vector<die> &, unsigned int);

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

/**
 * Get the score of threes
 * @return The score for threes or -1 if not present
 */
int calculateThrees(std::vector<die> &);

/**
 * Get the score of fours
 * @return The score for fours or -1 if not present
 */
int calculateFours(std::vector<die> &);

/**
 * Get the score of fives
 * @return The score for fives or -1 if not present
 */
int calculateFives(std::vector<die> &);

/**
 * Get the score of sixes
 * @return The score for sixes or -1 if not present
 */
int calculateSixes(std::vector<die> &);

/**
 * Get the score of straight
 * @return The score for straight or -1 if not present
 */
int calculateStraight(std::vector<die> &);

/**
 * Get the score of full house
 * @return The score for full house or -1 if not present
 */
int calculateFullHouse(std::vector<die> &);

/**
 * Get the score of four of a kind
 * @return The score for four of a kind  or -1 if not present
 */
int calculateFourOfAKind(std::vector<die> &);

/**
 * Get the score of generala
 * @return The score for generala or -1 if not present
 */
int calculateGenerala(std::vector<die> &);

void sortDice(std::vector<die> &dice);

#endif //GENERALA_SCORING_H
