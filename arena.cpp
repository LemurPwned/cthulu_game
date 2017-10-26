//
// Created by lemurpwned on 24/10/17.
//

#include "arena.h"

Arena::Arena(const std::string &name, const std::string &desc, int waves) :
        abstractLocation(name, desc), waves(waves) {}

void Arena::listCharacters(Hero *hero_state) {
    Arena::arenaLoop(hero_state);
}

void Arena::introduction() {
    std::cout<<"This is a fighting arena"<<std::endl;
    std::cout<<getName()<<std::endl;
    std::cout<<getDescription()<<std::endl;
    std::cout<<"There are "<<getWaves()<<" opponents waiting for you"<<std::endl;
}

