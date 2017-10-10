//
// Created by Jakub on 06/10/2017.
//

#ifndef CTHULU_GAME_HERO_H
#define CTHULU_GAME_HERO_H

#include "hero.h"
#include <iostream>

class Hero{
private:
    std::string item = "None";
    std::string name;

    int strength;
    int fear_level = 0;
    int hp = 100;

public:
    explicit Hero(const std::string &name);

    int getHp() const {
        return hp;
    }

    bool isAlive() const {
        if (hp > 0){
            return true;
        }
        else{
            return false;
        }
    }

    void setHp(int hp) {
        Hero::hp = hp;
    }

    std::string getItem(){
        return item;
    }

    void setItem(const std::string &item) {
        Hero::item = item;
    }

    int getStrength() const {
        return strength;
    }

    void setStrength(int strength) {
        Hero::strength = strength;
    }

    int getFear_level() const {
        return fear_level;
    }

    void setFear_level(int fear_level) {
        Hero::fear_level = fear_level;
    }
};
#endif //CTHULU_GAME_HERO_H
