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
}

void game::addPlayer(std::string name) {
    players.emplace_back(player(std::move(name)));
}

void game::playTurn() {
    turn++;
    roll = 0;
    auto &player = players.at(playerIndex);
    std::cout << "Player " << player.getName() << "'s turn. \r\n";
    for (die d : dice) {
        d.roll();
    }
    // todo check for generalla
    while (++roll < MAX_ROLLS + 1) {
        std::cout << "Roll " << roll << " of " << MAX_ROLLS << "!\r\n";
        printRoll();
        std::cout << "Mark which dice you want to reroll! (y/n y/n y/n y/n y/n) \r\n";
        for (die &d : dice) {
            char choice;
            std::cin >> choice;
            if (choice == 'y') {
                d.roll();
            }
        }
    }
}

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
