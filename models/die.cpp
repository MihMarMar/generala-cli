#include "die.h"

die::die() {
    numSides = 6;
    roll();
}

die::die(unsigned int numSides) {
    this->numSides = numSides;
    roll();
}

unsigned int die::roll() {
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(1, 6);
    side = dis(gen);
}

unsigned int die::getSide() {
    return side;
}
