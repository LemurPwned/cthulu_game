//
// Created by Jakub on 06/10/2017.
//

#ifndef CTHULU_GAME_CHARACTER_H
#define CTHULU_GAME_CHARACTER_H

#include <string>
#include <iostream>
#include <vector>
#include "hero.h"
#include "EventChain.h"

class Character {
private:
    std::string name;
    std::string description;

    int hp = 100;

protected:
    std::vector<std::string> reaction_set;

    std::vector<EventChain *> event_chain;
    int current_state = 0;
    int max_state = current_state + 1;

public:
    Character();

    explicit Character(const std::string &name) : name(name) {};

    Character(const std::string &name, const std::string &desc) : name(name), description(desc) {
    };

    virtual ~Character();

    void setChain(std::vector <EventChain*> &chain){
        event_chain = chain;
    }

    int getMax_state() const {
        return max_state;
    }

    void setMax_state(int max_state) {
        Character::max_state = max_state;
    }

    EventChain* getChain(){
        return event_chain[current_state];
    }

    void setCurrentState(int state){
        current_state = state;
    }

    void pushReaction(std::string reaction){
        reaction_set.push_back(reaction);
    }

    std::vector<std::string> getReactionList(){
        return reaction_set;
    }

    virtual void introduction(Hero *hero_state);

    virtual const std::string &getName() const {
        return name;
    }

    virtual void setName(const std::string &name) {
        Character::name = name;
    }

    virtual int getHp() const {
        return hp;
    }

    virtual void setHp(int hp) {
        Character::hp = hp;
        if (Character::hp < 0){
            std::cout<<Character::name<<" has died"<<std::endl;
        }
    }

    virtual bool isAlive() const {
        if (hp < 0){
            return false;
        }
        else{
            return true;
        }
    }

    virtual const std::string &getDescription() const {
        return description;
    }

    virtual void setDescription(const std::string &description) {
        Character::description = description;
    }

    void refactorString(std::string &text, int scaler);
};
#endif //CTHULU_GAME_CHARACTER_H
