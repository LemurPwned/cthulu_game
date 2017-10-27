//
// Created by lemurpwned on 27/10/17.
//

#include "spawn_opponent.h"
#include "Randomizer.h"

void Spawn::spawn_attack(Hero *hero_state, int modifier){
    int damage = (Randomizer::generateRandomToken(3)*Spawn::power)/modifier;
    hero_state->setHp(hero_state->getHp()-damage);
    std::cout<<Spawn::getName()<<" attacks and deals: "<<damage<<std::endl;
    std::cout<<"Your current hp is: "<<hero_state->getHp()<<std::endl;
    addExperience(damage/2);
}

void Spawn::hero_attack(Hero *hero_state){
    int damage = (Randomizer::generateRandomToken(5))*hero_state->getStrength();
    Spawn::setHp(Spawn::getHp()-damage);
    std::cout<<"You attack and deal: "<<damage<<" damage"<<std::endl;
}

void Spawn::introduction(Hero *hero_state) {
    if (!hero_state->isAlive()) return;
    introduction();
    while(true){
        listDialogOptions(hero_state);
        char selection;
        std::cout<<"Please select an option"<<std::endl;
        std::cin>>selection;
        if (selection == 'a'){
            hero_attack(hero_state);
            if (!isAlive())
                break;
            spawn_attack(hero_state, 1);
        }
        else if (selection == 'd'){
            spawn_attack(hero_state, 10); //10 times less effective
            if (!hero_state->isAlive()) return;
            hero_state->setHp(getHp()+10);
            std::cout<<"You recover 10 hp, current hp is: "<<hero_state->getHp()<<std::endl;
        }
        else if (selection == 't'){
            decreasePower();
            spawn_attack(hero_state, 2);
        }
        else{
            std::cout<<"Invalid selection"<<std::endl;
        }
        if (!isAlive()) {
            std::cout<<"Spawn has been defeated"<<std::endl;
            return;
        }
        if (!hero_state->isAlive()){
            return;
        }
    }
}

void Spawn::decreasePower(){
    int decrease = Randomizer::generateRandomToken(15);
    if (power > 10) {
        power -= decrease;
    }
    std::cout<<getName()<<" decreased in power by: "<<decrease<<std::endl;
    std::cout<<"Current power:"<<power<<std::endl;
}
void Spawn::introduction() {
    Character::introduction();
}

void Spawn::listDialogOptions(Hero *hero_state) {
    if (!hero_state->isAlive()){
        return;
    }
    std::cout<<"a) Attack"<<std::endl;
    std::cout<<"d) Defend"<<std::endl;
    std::cout<<"t) Taunt"<<std::endl;
}

void Spawn::levelUp() {
    std::cout<<"Leveled up"<<std::endl;
    Spawn::power+= 10;
    Spawn::setHp(100);
}

Spawn::Spawn(const std::string &name, const std::string &description, int power):
        Character(name, description){
    current_level = 0;
    experience = 0;
    Spawn::power = power;
    current_level++;
}

void Spawn::addExperience(int exp) {
    experience += exp;
    if (experience > 50){
        levelUp();
        experience = 0;
    }
}


Spawn::Spawn(Spawn &object) {
    name = object.name;
    description = object.description;
    power = object.power;
    experience = object.experience;
    addExperience(20);
    hp = 100;
    current_level = object.current_level;
}
