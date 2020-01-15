#include <iostream>
#include <vector>
#include "die.h"

using namespace std;

int main() {
    cout << "Welcome to Generala!" << "\r\n";
//    cout << "Press enter to continue";
    cin.get();
    vector<Die> dice;

    dice.reserve(5);
    for (int i = 0; i < 5; i++) {
        dice.emplace_back();
    }

    for (Die d : dice) {
        cout << d.getSide() << " ";
    }
    cout << "\r\n";

    return 0;
}
