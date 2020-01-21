#ifndef GENERALA_GAME_H
#define GENERALA_GAME_H


#include <vector>
#include <algorithm>
#include "../models/player.h"
#include "../models/die.h"
#include "scoring.h"

#define MAX_ROLLS 3

//categories
#define ONES 1
#define TWOS 2
#define THREES 3
#define FOURS 4
#define FIVES 5
#define SIXES 6
#define STRAIGHT 7
#define FULL_HOUSE 8
#define FOUR_OF_A_KIND 9
#define GENERALA 10

//categories strings

//points
#define P_ONES 1
#define P_TWOS 2
#define P_THREES 3
#define P_FOURS 4
#define P_FIVES 5
#define P_SIXES 6
#define P_STRAIGHT 20
#define P_FULL_HOUSE 30
#define P_FOUR_OF_A_KIND 40
#define P_GENERALA 50
#define SCORE_NOT_PRESENT (-1)


class game {
private:
    std::vector<player> players;
    std::vector<die> dice;
    std::map<int, bool> categories;
    int turn;
    int maxTurns;
    bool over;
    int playerIndex;
    int winnerIndex;
    int roll;

    void printRoll() const;

    void printAvailableCategories();

    bool scratchCategory(int);

    static std::string getCategoryString(int);

    void initializeCategories();

    void addPointsSequence(player &player);

    void scratchCategorySequence();

    void findWinner();

public:
    /**
     * initialize the game
     * @param maxTurns how many maximum turns are played if a player doesn't win earlier
     */
    explicit game(int maxTurns);


    /**
     * poll if game is over
     * @return true if games is over, false othewise
     */
    [[nodiscard]] bool isOver() const;

    /**
     * add a player to the game
     */
    void addPlayer(std::string);

    /**
     * play a single turn of the game
     */
    void playTurn();

    /**
     * get the winner
     * @return a reference to the winner
     */
    player getWinner();

};


#endif //GENERALA_GAME_H
