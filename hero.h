//
// Created by Jakub on 06/10/2017.
//

#ifndef CTHULU_GAME_HERO_H
#define CTHULU_GAME_HERO_H

#include "hero.h"
#include <iostream>
#include <vector>

class Hero{
private:
    std::string name;

    std::vector<std::string> inventory;

    int strength;
    int fear_level = 0;
    int hp = 100;

    bool teleport = false;

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

    int getStrength() const {
        return strength;
    }

    void setStrength(int strength) {
        Hero::strength = strength;
        if (Hero::strength <= 0){
            std::cout<<"You lost your will to fight"<<std::endl;
            std::cout<<"That means any encounter will end up most likely in your death"<<std::endl;
            Hero::strength = 0;
        }
    }

    int getFear_level() const {
        return fear_level;
    }

    void setFear_level(int fear_level);

    void pushItem(const std::string &item){
        inventory.push_back(item);
    }

    bool isInInventory(std::string &item){
        for (auto i : inventory) {
            if (item == i){
                return true;
            }
        }
        return false;
    }

    bool isTeleport() const {
        return teleport;
    }

    void setTeleport(bool teleport) {
        Hero::teleport = teleport;
    }
};
#endif //CTHULU_GAME_HERO_H
