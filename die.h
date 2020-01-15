//
// Created by mishi9 on 15-01-20.
//

#ifndef GENERALA_DIE_H
#define GENERALA_DIE_H

#include <random>


class Die {
public:
    Die();

    explicit Die(unsigned int numSides);

    unsigned int roll();

    unsigned int getSide();
private:
    unsigned int numSides;
    unsigned int side;
};


#endif //GENERALA_DIE_H
