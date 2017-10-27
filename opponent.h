//
// Created by lemurpwned on 10/10/17.
//

#ifndef CTHULU_GAME_OPPONENT_H
#define CTHULU_GAME_OPPONENT_H

#include "character.h"

class Opponent: public Character{
private:
    int strength;
public:
    explicit Opponent(const std::string &name, int strength) : Character(name), strength(strength){

    }

    Opponent(const std::string &name, const std::string &desc, int strength) :
            Character(name, desc), strength(strength) {}


    void introduction(Hero *hero_state);

    void introduction() override {
        Character::introduction();
    }

    void listDialogOptions(Hero *hero_state);

    void retaliate(Hero *hero_state);

    void defend(Hero *hero_state);

    int getStrength() const {
        return strength;
    }

    void setStrength(int strength) {
        Opponent::strength = strength;
    }
};
#endif //CTHULU_GAME_OPPONENT_H
