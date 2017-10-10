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

public:
    explicit Hero(const std::string &name);

    std::string getItem(){
        return item;
    }

    void setItem(const std::string &item) {
        Hero::item = item;
    }
};
#endif //CTHULU_GAME_HERO_H
