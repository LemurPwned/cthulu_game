//
// Created by Jakub on 06/10/2017.
//

#ifndef CTHULU_GAME_CHARACTER_H
#define CTHULU_GAME_CHARACTER_H

#include <string>
#include <iostream>
#include <vector>
#include "EventChain.h"
#include "hero.h"

class Character{
private:
    std::string name;
    std::string description;

    int hp = 100;
    bool alive = true;

    std::string reacts_to = "None";
    std::vector<EventChain*> event_chain;
    int current_state = 0;
    int max_state = current_state+1;

public:
    Character();

    explicit Character(const std::string &name) : name(name) {};

    Character(const std::string &name, const std::string &desc): name(name), description(desc) {};

    void setChain(std::vector <EventChain*> &chain){
        event_chain = chain;
    }

    void setReactive(std::string item){
        reacts_to = item;
    }

    int getMax_state() const {
        return max_state;
    }

    void setMax_state(int max_state) {
        Character::max_state = max_state;
    }

    std::string getReaction(){
        return reacts_to;
    }

    EventChain* getChain(){
        return event_chain[current_state];
    }

    void setCurrentState(int state){
        current_state = state;
    }

    void introduction(Hero *hero_state);

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        Character::name = name;
    }

    int getHp() const {
        return hp;
    }

    void setHp(int hp) {
        Character::hp = hp;
        if (Character::hp < 0){
            std::cout<<Character::name<<" has died"<<std::endl;
            Character::alive = false;
        }
    }

    bool isAlive() const {
        return alive;
    }

    void setAlive(bool alive) {
        Character::alive = alive;
    }

    const std::string &getDescription() const {
        return description;
    }

    void setDescription(const std::string &description) {
        Character::description = description;
    }
};
#endif //CTHULU_GAME_CHARACTER_H
