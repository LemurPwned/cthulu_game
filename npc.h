//
// Created by lemurpwned on 22/10/17.
//

#ifndef CTHULU_GAME_NPC_H
#define CTHULU_GAME_NPC_H

#include <string>

class NPC{
protected:
    std::string name;
    std::string description;
    int hp = 100;

public:
    NPC() = default;

    explicit NPC(const std::string &name): name(name){};

    NPC(const std::string &name, const std::string &description): name(name), description(description) {};

    void setName(std::string &name) {
        NPC::name = name;
    }

    void setDescription(std::string &desc){
        description = desc;
    }

    std::string getName(){
        return name;
    }

    std::string getDescription(){
        return description;
    }

    int getHp() {
        return hp;
    }

    void setHp(int hp) {
        NPC::hp = hp;
        if (NPC::hp < 0){
            std::cout<<NPC::name<<" has died"<<std::endl;
        }
    }

    virtual bool isAlive() {
        if (hp){
            return true;
        }
        else{
            std::cout<<"Totally dead"<<std::endl;
            return false;
        }
    }

    virtual void introduction() = 0;
};
#endif //CTHULU_GAME_NPC_H
