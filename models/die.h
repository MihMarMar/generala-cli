#ifndef GENERALA_DIE_H
#define GENERALA_DIE_H

#include <random>


class die {
public:
    die();

    explicit die(unsigned int numSides);

    unsigned int roll();

    unsigned int getSide();

private:
    unsigned int numSides;
    unsigned int side;
};


#endif //GENERALA_DIE_H
