//
// Created by lemurpwned on 19/10/17.
//

#ifndef CTHULU_GAME_RANDOMIZER_H
#define CTHULU_GAME_RANDOMIZER_H

#include <random>
#include <iostream>

class Randomizer{
private:
    static char random_sign_list[];
    static int random_sign_list_size;

public:

    Randomizer() = default;

    static int generateRandomToken(int indicator);

    static char drawRandomSign();

    static int generateRandomNumberFromInterval(int start, int stop);
};
#endif //CTHULU_GAME_RANDOMIZER_H
