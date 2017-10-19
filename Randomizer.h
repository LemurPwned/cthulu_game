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

    static int generateRandomToken(int indicator){
        std::uniform_int_distribution<int> dist_token(0, indicator);
        std::random_device randomizer_device;
        std::mt19937 m_mt_seed(randomizer_device());
        return dist_token(m_mt_seed);
    }

    static char drawRandomSign(){
        std::uniform_int_distribution <int> dist_null_char(0, random_sign_list_size);
        // use it here to generate some random characters
        std::random_device randomizer_device;
        std::mt19937 m_mt_seed(randomizer_device());
        return random_sign_list[dist_null_char(m_mt_seed)];
    }
};
#endif //CTHULU_GAME_RANDOMIZER_H
