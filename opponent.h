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

    void introduction(Hero *hero_state) override;

    void retaliate(Hero *hero_state);

    void defend(Hero *hero_state);

    const std::string &getName() const override {
        return Character::getName();
    }

    void setName(const std::string &name) override {
        Character::setName(name);
    }

    int getHp() const override {
        return Character::getHp();
    }

    void setHp(int hp) override {
        Character::setHp(hp);
    }

    bool isAlive() const override {
        return Character::isAlive();
    }

    const std::string &getDescription() const override {
        return Character::getDescription();
    }

    void setDescription(const std::string &description) override {
        Character::setDescription(description);
    }

    int getStrength() const {
        return strength;
    }

    void setStrength(int strength) {
        Opponent::strength = strength;
    }
};
#endif //CTHULU_GAME_OPPONENT_H
