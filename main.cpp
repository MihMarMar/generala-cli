#include <iostream>
#include "game_logic/game.h"

using namespace std;

int main() {
    cout << "Welcome to Generala!" << "\r\n";
    game game(5);
    while (true) {
        cout << "Do you want to add another player? (y/n) \r\n";
        char choice;
        cin >> choice;
        if (choice == 'y') {
            cout << "Enter player name: ";
            string name;
            cin >> name;
            game.addPlayer(name);
        } else break;
    }
    while (!game.isOver()) {
        game.playTurn();
    }
    std::cout << "\r\nGAME OVER\r\n";
    cout << "Player " << game.getWinner().getName() << " won with a score of: " << game.getWinner().getScore()
         << "\r\n";
    cout << "Press any key to close";
    cin.get();

    return 0;
}
