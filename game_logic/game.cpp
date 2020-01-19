#include "game.h"

#include <utility>

game::game(int maxTurns) : maxTurns(maxTurns) {
    dice.reserve(5);
    for (int i = 0; i < 5; i++) {
        dice.emplace_back();
    }
    turn = 0;
    roll = 1;
    over = false;
    playerIndex = 0;
    winnerIndex = -1;
    initializeCategories();
}

void game::addPlayer(std::string name) {
    players.emplace_back(player(std::move(name)));
}

void game::playTurn() {
    turn++;
    roll = 0;
    auto &player = players.at(playerIndex);
    std::cout << "Turn " << turn << " of " << maxTurns << "\r\n";
    std::cout << "Player " << player.getName() << "'s turn. ";
    std::cout << "Score until now: " << player.getScore() << "\r\n";
    for (die &d : dice) {
        d.roll();
    }
    while (++roll < MAX_ROLLS + 1) {
        std::cout << "Roll " << roll << " of " << MAX_ROLLS << "!\r\n";
        printRoll();

        // Check for roll one win
        if (roll == 1 && calculateScore(dice, GENERALA) != -1) {
            player.addScore(P_GENERALA);
            winnerIndex = playerIndex;
            over = true;
            return;
        }

        std::cout << "Mark which dice you want to reroll! (y/n y/n y/n y/n y/n) \r\n";
        for (die &d : dice) {
            char choice;
            std::cin >> choice;
            if (choice == 'y') {
                d.roll();
            }
        }
    }


    while (true) {
        printRoll();
        std::cout << "Do you want to add points(p) or scratch(s) a category?\r\n";
        char choice;
        std::cin >> choice;
        if (choice == 'p') {

            // get points
            printAvailableCategories();
            int scoreToAdd;
            do {
                std::cout << "Choose a number: ";
                int scoreChoice;
                std::cin >> scoreChoice;
                scoreToAdd = calculateScore(dice, scoreChoice);
                if (scoreToAdd != -1) {
                    player.addScore(scoreToAdd);
                    std::cout << "Now " << player.getName() << "'s score is " << player.getScore() << "\r\n";
                }
            } while (scoreToAdd == -1);
            break;
        } else if (choice == 's') {

            // scratch category
            bool success;
            do {
                printAvailableCategories();
                std::cout << "Choose a number: ";
                int scratchChoice;
                std::cin >> scratchChoice;
                success = scratchCategory(scratchChoice);
            } while (!success);
            break;
        } // end of scratch
        // if choice does not match loop again

    } // end of points/scratch loop


    advancePlayer();

    if (turn == maxTurns) {
        std::cout << "\r\nGAME OVER";
        over = true;
        findWinner();
    }
} // playTurn()


void game::printRoll() const {
    std::cout << "You've rolled" << "\r\n";
    for (die d : this->dice) {
        std::cout << d.getSide() << " ";
    }
    std::cout << "\r\n";
}

bool game::isOver() const {
    return over;
}

void game::advancePlayer() {
    playerIndex++;
    if (playerIndex == players.size()) {
        playerIndex = 0;
    }
}

player game::getWinner() {
    return players.at(winnerIndex);
}

void game::printAvailableCategories() {
    std::cout << "Available categories: \r\n";
    for (auto cat : categories) {
        if (cat.second) {
            std::cout << cat.first << ". " + getCategoryString(cat.first) << "\r\n";
        }
    }
}

std::string game::getCategoryString(int cat) {
    switch (cat) {
        case ONES:
            return "Ones";
        case TWOS:
            return "Twos";
        case THREES:
            return "Threes";
        case FOURS:
            return "Fours";
        case FIVES:
            return "Fives";
        case SIXES:
            return "Sixes";
        case STRAIGHT:
            return "Straight";
        case FULL_HOUSE:
            return "Full House";
        case FOUR_OF_A_KIND :
            return "Four of a kind";
        case GENERALA:
            return "Generala";
        default:
            return "Unknown";
    }
}

bool game::scratchCategory(int cat) {
    if (categories[cat]) {
        categories[cat] = false;
        return true;
    }
    return false;
}

void game::initializeCategories() {
    categories[ONES] = true;
    categories[TWOS] = true;
    categories[THREES] = true;
    categories[FOURS] = true;
    categories[FIVES] = true;
    categories[SIXES] = true;
    categories[STRAIGHT] = true;
    categories[FULL_HOUSE] = true;
    categories[FOUR_OF_A_KIND] = true;
    categories[GENERALA] = true;
}

void game::findWinner() {
    // this method assumes that winner will be explicitly set if he rolls a generala on roll 1
    // so it calculates the winner only based on max points
    int maxScore = -1;
    int playerMaxIndex = 0;
    for (int i = 0; i < players.size(); ++i) {
        player p = players.at(i);
        if ((int) p.getScore() > maxScore) {
            maxScore = (int) p.getScore();
            playerMaxIndex = i;
        }
    }
    winnerIndex = playerMaxIndex;
}
