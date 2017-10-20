//
// Created by Jakub on 06/10/2017.
//

#ifndef CTHULU_GAME_HERO_H
#define CTHULU_GAME_HERO_H

#include <iostream>
#include <vector>

class Hero {
private:
    std::string name;

    std::vector<std::string> inventory;

    int strength;
    int fear_level = 0;
    int hp = 100;

    bool teleport = false;

    static int hero_count; // should be exactly 1;

    explicit Hero(std::string &name); // private constructor

    explicit Hero(Hero *object);

public:
    static Hero *getHeroObject(std::string name);

    static Hero *createSoul(Hero *object);

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        Hero::name = name;
    }

    const std::vector<std::string> &getInventory() const {
        return inventory;
    }

    void setInventory(const std::vector<std::string> &inventory) {
        Hero::inventory = inventory;
    }

    int getHp() const {
        return hp;
    }

    void setHp(int hp) {
        Hero::hp = hp;
    }

    bool isAlive() {
        if (hp > 0){
            return true;
        }
        else{
            return false;
        }
    }

    static int getHero_count() {
        return hero_count;
    }

    static void setHero_count(int hero_count) {
        Hero::hero_count = hero_count;
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

    virtual ~Hero();
};
#endif //CTHULU_GAME_HERO_H
