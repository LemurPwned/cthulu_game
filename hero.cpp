//
// Created by Jakub on 06/10/2017.
//

#include "hero.h"

//initialize static variables
int Hero::hero_count = 0;

Hero::Hero(std::string &name) : NPC(name) {
    Hero::introduction();
    Hero::hero_count++;
}

void Hero::setFear_level(int fear) {
    //warning: this function does not *set* exactly but accumulates the fear passed
    Hero::fear_level = Hero::fear_level + fear;
    if (fear > 0 ){
        if (Hero::fear_level > 10){
            std::cout<<"You start feeling a little bit uncertain about the situation"<<std::endl;
        }
        else if (Hero::fear_level > 30){
            std::cout<<"Previous discomfort turns into more serious concern"<<std::endl;
            strength -= 2;
        }
        else if (Hero::fear_level > 50){
            std::cout<<"You feel a serious fear and start shivering a little"<<std::endl;
            strength -= 9;
        }
        else if (Hero::fear_level > 80){
            std::cout<<"You barely can control yourself. Your thoughts "\
                    "way swiftly through your mind"<<std::endl;
            std::cout<<"Fear won't let you concentrate anymore"<<std::endl;
            strength -= 12;
        }
        else if (Hero::fear_level > 90){
            std::cout<<"You've lost your chance to calm down a long time ago"<<std::endl;
            std::cout<<"Now death would be a salvation in your condition"<<std::endl;
            std::cout<<"That is the price you pay for curiosity"<<std::endl;
            strength -= 20;
        }
    }
    else if (fear < -1){
        strength -= fear; // increase statistics
    }
}

Hero::~Hero() {
    std::cout<<"Ending player's journey ... "<<std::endl;
    delete &hp;
    delete &fear_level;
    delete &strength;
    delete &name;
}

Hero* Hero::getHeroObject(std::string name) {
    if (Hero::hero_count >= 1){
        std::cout<<hero_count<<std::endl;
        std::cout<<"There has been already one hero object created"<<std::endl;
        return nullptr; //alternatively throw an error
    }
    else{
        return new Hero(name);
    }
}

Hero::Hero(Hero *object) {
    name = object->name;
    hp = 100;
    fear_level = object->getFear_level();
    strength = 100;
}

Hero *Hero::createSoul(Hero *hero) {
    return new Hero(hero);
}

void Hero::introduction() {
    std::cout<<getName()<<std::endl;
    std::cout<<"It's your name now"<<std::endl;
}
