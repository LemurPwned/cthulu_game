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

class Character: public NPC {
protected:
    std::vector<std::string> reaction_set;

    std::vector<EventChain *> event_chain;
    int current_state = 0;
    int max_state = current_state + 1;

public:
    Character();

    explicit Character(const std::string &name) : NPC(name) {};

    Character(const std::string &name, const std::string &desc) : NPC(name, desc) {
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

    void introduction() override;

    void checkCurrentState(Hero *hero_state);

    virtual void listDialogOptions(Hero *hero_state);

    void refactorString(std::string &text, int scaler);
};
#endif //CTHULU_GAME_CHARACTER_H
