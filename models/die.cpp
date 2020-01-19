#include "die.h"

die::die() {
    numSides = 6;
    side = (int) random() % numSides + 1;
}

die::die(unsigned int numSides) {
    this->numSides = numSides;
    side = (int) random() % numSides + 1;
}

unsigned int die::roll() {
    side = (int) random() % numSides + 1;
}

unsigned int die::getSide() {
    return side;
}
