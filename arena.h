//
// Created by lemurpwned on 24/10/17.
//

#ifndef CTHULU_GAME_ARENA_H
#define CTHULU_GAME_ARENA_H

#include "abstractLocation.h"
#include "spawn_opponent.h"

class Arena: public abstractLocation{

private:
    int waves;

public:
    Arena(const std::string &name, const std::string &desc, int waves);

    void arenaLoop(Hero *hero){
        std::cout<<"You've entered arena"<<std::endl;
        std::cout<<"and you shall fight for your life"<<std::endl;
        //in this loop spawn enemies and manage the resources
        while(true){
            if(hero->isAlive() && waves > 0){
                std::cout<<"WAVES TO GO: "<<waves<<std::endl;
                if (!characters[0]->isAlive()){
                    return;
                }
                spawnEnemy(hero);
                waves--;
            }
            else{
                break;
            }
        }
    }

    void spawnEnemy(Hero *hero){
        //do spawn opponents here
        std::cout<<"You face another opponent"<<std::endl;
        characters[0]->introduction(hero);
        if (!characters[0]->isAlive() && hero->isAlive()) {
            std::cout << "Enemy defeated" << std::endl;
            auto *tmp = (Spawn *) characters[0];
            characters[0] = new Spawn(*tmp);
        }
        else if(!hero->isAlive()){
            return;
        }
        else{
            std::cout<<"Chose to quit the arena"<<std::endl;
        }
    }

    int getWaves(){
        return waves;
    }

    void listCharacters(Hero *hero_state) override;

    void introduction() override;
};

#endif //CTHULU_GAME_ARENA_H
