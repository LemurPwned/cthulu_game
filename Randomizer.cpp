//
// Created by lemurpwned on 19/10/17.
//

#include "Randomizer.h"

char Randomizer::random_sign_list[] = {'(', '!', '>', '?', ')', '/', '.', '|', '"', '@',
                                       '%', '*', '&', '%', '~'};
int Randomizer::random_sign_list_size = 15;

int Randomizer::generateRandomToken(int indicator) {
    std::uniform_int_distribution<int> dist_token(0, indicator);
    std::random_device randomizer_device;
    std::mt19937 m_mt_seed(randomizer_device());
    return dist_token(m_mt_seed);
}

char Randomizer::drawRandomSign() {
    std::uniform_int_distribution <int> dist_null_char(0, random_sign_list_size);
    // use it here to generate some random characters
    std::random_device randomizer_device;
    std::mt19937 m_mt_seed(randomizer_device());
    return random_sign_list[dist_null_char(m_mt_seed)];
}

