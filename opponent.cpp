//
// Created by lemurpwned on 10/10/17.
//

#include "opponent.h"
#include "Statistics.h"
#include <random>

void Opponent::defend(Hero *hero_state) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution dist(1, 10);
    //initialize c++11 random magic
    std::cout<<"You choose to take on defensive stance"<<std::endl;

    int damage = getStrength()*dist(gen)/10 - hero_state->getStrength()*(dist(gen)/5);
    if (damage < 0) damage = 0;
    std::cout<<getName()<<" attacks and deals "<<damage<<" damage"<<std::endl;
    hero_state->setHp(hero_state->getHp()-damage);
    if (!hero_state->isAlive()){
        std::cout<<"\nA deadly blow was delivered, you had no chance surviving...\n";
        return;
    }
}

void Opponent::retaliate(Hero *hero_state) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution dist(1, 5);
    //initialize c++11 random magic
    int damage;
    if (hero_state->getStrength() < getStrength()){
        damage = hero_state->getStrength()*dist(gen)/10;
        setHp(getHp()-damage);
        Statistics::addDamage_dealt(damage);
        if (!isAlive()){
            Statistics::addEnemies_defeated();
            std::cout<<"You have defeated "<<getName()<<std::endl;
            return;
        }
        std::cout<<"You're weaker than "<<getName()<<" so you'll receive penalty"<<std::endl;
        std::cout<<"Dealt "<<damage<<" damage!\n"<<std::endl;
        damage = getStrength()*(1 + hero_state->getFear_level()*dist(gen)/10);
        hero_state->setHp(hero_state->getHp() - damage);
        Statistics::addDamaged_received(damage);
        std::cout<<getName()<<" retaliates! with "<<damage<<" damage points"<<std::endl;
    }
    else{
        damage = hero_state->getStrength()*dist(gen)/10;
        setHp(getHp()-damage);
        Statistics::addDamage_dealt(damage);
        if (!isAlive()){
            Statistics::addEnemies_defeated();
            std::cout<<"You have defeated "<<getName()<<std::endl;
            return;
        }
        std::cout<<"Dealt "<<damage<<" damage!\n"<<std::endl;
        damage = getStrength()*dist(gen)/10;
        hero_state->setHp(hero_state->getHp() - damage);
        Statistics::addDamaged_received(damage);
        std::cout<<getName()<<" retaliates! with "<<damage<<" damage points"<<std::endl;
    }
}

void Opponent::introduction(Hero *hero_state) {
    for (int i = 0; i < reaction_set.size(); i++){
        if (hero_state->isInInventory(reaction_set[i])){
            setCurrentState(i+1);
        }
    }
    //standard opponent introduction
    std::cout<<"Your opponent's name is: "<<getName()<<std::endl;
    if (!isAlive()) {
        std::cout<<"He is totally dead"<<std::endl;
        return;
    }
    std::cout<<getDescription()<<std::endl;

    while(true){
        if (!isAlive()) {
            std::cout<<"He is totally dead"<<std::endl;
            return;
        }
        std::cout<<"What do you wish to do about "<<getName()<<"?"<<std::endl;
        //list dialogs here
        //check if dialogs exist?
        int available_answers = 1;

        for (auto i: event_chain[current_state]->getChain()) {
            std::cout<<available_answers<<") "<<i->getQuestion()<<std::endl;
            available_answers++;
        }
        std::cout<<"a) Attack"<<std::endl; // extra options for the opponent type
        std::cout<<"d) Defend"<<std::endl;

        char selection;
        std::cin>>selection;
        int selected_dialog = selection - '0'; //convert to int, access to vector

        if (selected_dialog -1 < event_chain[current_state]->getChain().size()) {
            std::cout << "-" << event_chain[current_state]->\
                    getChain()[selected_dialog - 1]->getAnswer()<< std::endl;
            if(event_chain[current_state]->getChain()[selected_dialog-1]->isEffect()){
                hero_state->setFear_level(event_chain[current_state]-> \
                getChain()[selected_dialog-1]->getEffect());
                // remove the effect
                event_chain[current_state]->getChain()[selected_dialog-1]->setEffect(0);
            }
            if (event_chain[current_state]->getChain()[selected_dialog-1]->isTeleport()){
                hero_state->setTeleport(true); //hero should be teleported somewhere
                event_chain[current_state]->getChain()[selected_dialog-1]->disableTeleport();
                //teleportation event is triggered only once
            }
        }
        else if(selection == 'a'){
            retaliate(hero_state);
            if (!hero_state->isAlive()){
                std::cout<<"Your journey has reached a dead end. Rest now"<<std::endl;
                return;
            }
            else{
                std::cout<<"You have "<<hero_state->getHp()<<" hp left"<<std::endl;
            }
        }
        else if (selection == 'd'){
            defend(hero_state); // defend form a perspective of a hero
            if (!hero_state->isAlive()){
                std::cout<<"Your journey has reached a dead end. Rest now"<<std::endl;
                return;
            }
            else{
                std::cout<<"You have "<<hero_state->getHp()<<" hp left"<<std::endl;
            }
        }
        else if (selection == 'q'){
            std::cout<<"Chose to quit"<<std::endl;
            break;
        }
        else{
            std::cout<<"Invalid input "<<selection<<std::endl;
        }
    }
}

