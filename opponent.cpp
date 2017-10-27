//
// Created by lemurpwned on 10/10/17.
//

#include "opponent.h"
#include "Statistics.h"
#include "Randomizer.h"

void Opponent::defend(Hero *hero_state) {
    std::cout<<"You choose to take on defensive stance"<<std::endl;
    int damage = getStrength()*Randomizer::generateRandomNumberFromInterval(1,10)/10 -\
        hero_state->getStrength()*(Randomizer::generateRandomNumberFromInterval(1,10)/5);
    if (damage < 0) damage = 0;
    std::cout<<getName()<<" attacks and deals "<<damage<<" damage"<<std::endl;
    hero_state->setHp(hero_state->getHp()-damage);
    if (!hero_state->isAlive()){
        std::cout<<"\nA deadly blow was delivered, you had no chance surviving...\n";
        return;
    }
}

void Opponent::retaliate(Hero *hero_state) {
    int damage;
    if (hero_state->getStrength() < getStrength()){
        damage = hero_state->getStrength()*Randomizer::generateRandomNumberFromInterval(1,5)/10;
        setHp(getHp()-damage);
        Statistics::addDamage_dealt(damage);
        if (!isAlive()){
            Statistics::addEnemies_defeated();
            std::cout<<"You have defeated "<<getName()<<std::endl;
            return;
        }
        std::cout<<"You're weaker than "<<getName()<<" so you'll receive penalty"<<std::endl;
        std::cout<<"Dealt "<<damage<<" damage!\n"<<std::endl;
        damage = getStrength()*(1 + hero_state->getFear_level()*\
                                Randomizer::generateRandomNumberFromInterval(1,5)/10);
        hero_state->setHp(hero_state->getHp() - damage);
        Statistics::addDamaged_received(damage);
        std::cout<<getName()<<" retaliates! with "<<damage<<" damage points"<<std::endl;
    }
    else{
        damage = hero_state->getStrength()*Randomizer::generateRandomNumberFromInterval(1,3)/10;
        setHp(getHp()-damage);
        Statistics::addDamage_dealt(damage);
        if (!isAlive()){
            Statistics::addEnemies_defeated();
            std::cout<<"You have defeated "<<getName()<<std::endl;
            return;
        }
        std::cout<<"Dealt "<<damage<<" damage!\n"<<std::endl;
        damage = getStrength()*Randomizer::generateRandomNumberFromInterval(1,5)/10;
        hero_state->setHp(hero_state->getHp() - damage);
        Statistics::addDamaged_received(damage);
        std::cout<<getName()<<" retaliates! with "<<damage<<" damage points"<<std::endl;
    }
}

void Opponent::introduction(Hero *hero_state) {
    Character::checkCurrentState(hero_state);
    Character::introduction();

    while(true){
        if (!NPC::isAlive()) return;
        std::cout<<"What do you wish to do about "<<getName()<<"?"<<std::endl;
        //list dialogs here
        //check if dialogs exist?
        Opponent::listDialogOptions(hero_state);

        char selection;
        std::cin>>selection;
        //convert to int, access to vector
        int selected_dialog = selection - '0';

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

void Opponent::listDialogOptions(Hero *hero_state) {
    Character::listDialogOptions(hero_state);
    std::cout<<"a) Attack"<<std::endl; // extra options for the opponent type
    std::cout<<"d) Defend"<<std::endl;
}

