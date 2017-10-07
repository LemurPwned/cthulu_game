//
// Created by Jakub on 06/10/2017.
//

#include <iostream>
#include "character.h"

Character::Character() {
    Character::name = "Stranger";
    Character::alive = true;
    Character::hp = 100;
}
void Character::introduction() {
    std::cout<<"My name? This person's name is: "<<getName()<<std::endl;
    std::cout<<"He would not admit it but his hp is currently at "<<getHp()<<std::endl;
    if (!isAlive()) std::cout<<"He is totally dead"<<std::endl;
    std::cout<<getDesctiption()<<std::endl;
}