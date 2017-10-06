//
// Created by Jakub on 06/10/2017.
//

#ifndef CTHULU_GAME_CHARACTER_H
#define CTHULU_GAME_CHARACTER_H

#include <string>
#include <iostream>

class Character{
private:
    std::string name;
    int hp = 100;
    bool alive = true;

protected:
    int x;
    int y;

public:
    Character();
    Character(const std::string &name) : name(name) {}

    virtual void introduction();

    int getX() const {
        return x;
    }

    void setX(int x) {
        Character::x = x;
    }

    int getY() const {
        return y;
    }

    void setY(int y) {
        Character::y = y;
    }

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
};
#endif //CTHULU_GAME_CHARACTER_H
