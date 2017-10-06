//
// Created by Jakub on 06/10/2017.
//

#ifndef CTHULU_GAME_HERO_H
#define CTHULU_GAME_HERO_H

#include "character.h"

class Hero: public Character{
private:
    int fear_level;
    bool panic = false;

    int speech;
    int intelligence;
    int cthulhu_knowledge = 0;
public:
    void introduction() override;

    Hero(const std::string &name, int intelligence, int speech) : Character(name) {
        setIntelligence(intelligence);
        setSpeech(speech);
        setFear_level(0);
    }

    int getFear_level() const {
        return fear_level;
    }

    void setFear_level(int fear_level) {
        if (fear_level > 80){ setPanic(true); }
        if (fear_level > 1000) { std::cout<<"Invalid value"<<std::endl;}
        Hero::fear_level = fear_level;
    }

    bool isPanic() const {
        return panic;
    }

    void setPanic(bool panic) {
        Hero::panic = panic;
    }

    int getSpeech() const {
        return speech;
    }

    void setSpeech(int speech) {
        Hero::speech = speech;
    }

    int getIntelligence() const {
        return intelligence;
    }

    void setIntelligence(int intelligence) {
        Hero::intelligence = intelligence;
    }

    int getCthulhu_knowledge() const {
        return cthulhu_knowledge;
    }

    void setCthulhu_knowledge(int cthulhu_knowledge) {
        Hero::cthulhu_knowledge = cthulhu_knowledge;
    }
};
#endif //CTHULU_GAME_HERO_H
