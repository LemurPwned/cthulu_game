//
// Created by lemurpwned on 22/10/17.
//

#ifndef CTHULU_GAME_NPC_H
#define CTHULU_GAME_NPC_H

#include <string>

class NPC{
protected:
    std::string name;
    int hp = 100;

public:
    NPC() = default;

    std::string &getName(){
        return name;
    }

    void setName(std::string &name) {
        NPC::name = name;
    }

    int getHp() {
        return hp;
    }

    void setHp(int hp) {
        NPC::hp = hp;
    }

    bool isAlive() {
        if (hp > 0){
            return true;
        }
        else{
            return false;
        }
    }

    void introduction();
};
#endif //CTHULU_GAME_NPC_H
