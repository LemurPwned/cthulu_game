//
// Created by lemurpwned on 27/10/17.
//

#ifndef CTHULU_GAME_SPAWN_OPPONENT_H
#define CTHULU_GAME_SPAWN_OPPONENT_H

#include "opponent.h"

class Spawn: public Character{
private:
    int current_level;
    int experience;
    int power;
public:
    Spawn(const std::string &name, const std::string &description, int power);

    Spawn(Spawn &object);

    void levelUp();

    void introduction(Hero *hero_state) override;

    void introduction() override;

    void addExperience(int exp);

    void listDialogOptions(Hero *hero_state) override;

    void spawn_attack(Hero *hero_state, int modifier);

    void hero_attack(Hero *hero_state);

    void decreasePower();
};
#endif //CTHULU_GAME_SPAWN_OPPONENT_H
