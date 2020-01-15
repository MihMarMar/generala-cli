//
// Created by mishi9 on 15-01-20.
//

#include "die.h"

Die::Die() {
    numSides = 6;
    side = (int) random() % numSides + 1;
}

Die::Die(unsigned int numSides) {
    this->numSides = numSides;
    side = (int) random() % numSides + 1;
}

unsigned int Die::roll() {
    side = (int) random() % numSides + 1;
}

unsigned int Die::getSide() {
    return side;
}
