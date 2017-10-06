//
// Created by Jakub on 06/10/2017.
//

#include "hero.h"

void Hero::introduction() {
    Character::introduction();
    std::cout<<"Current stats are:\n";
    std::cout<<"Speech "<<getSpeech()<<std::endl;
    std::cout<<"Intelligence "<<getSpeech()<<std::endl;
    std::cout<<"Fear level "<<getFear_level()<<std::endl;
    if (isPanic()){
        std::cout<<"You are in panic"<<std::endl;
    }
}