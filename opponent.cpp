//
// Created by lemurpwned on 10/10/17.
//

#include "opponent.h"
#include <random>

void Opponent::retaliate(Hero *hero_state) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution dist(1, 10);
    //initialize c++11 random magic
    int damage;
    std::cout<<"Your strength "<<hero_state->getStrength()<<std::endl;
    std::cout<<getName()<<" strength "<<getStrength()<<std::endl;
    std::cout<<"SEED "<<dist(gen)<<std::endl;
    if (hero_state->getStrength() < getStrength()){
        damage = hero_state->getStrength()*dist(gen)/10;
        std::cout<<"You're weaker than "<<getName()<<" so you'll receive penalty"<<std::endl;
        std::cout<<"Dealt "<<damage<<" damage!\n"<<std::endl;
        damage = getStrength()*(1 + hero_state->getFear_level()*dist(gen)/10);
        hero_state->setHp(hero_state->getHp() - damage);
        std::cout<<getName()<<" retaliates! with "<<damage<<" damage points"<<std::endl;
    }
    else{
        damage = hero_state->getStrength()*dist(gen)/10;
        setHp(getHp()-damage);
        if (!isAlive()){
            std::cout<<"You have defeated "<<getName()<<std::endl;
            return;
        }
        std::cout<<"Dealt "<<damage<<" damage!\n"<<std::endl;
        damage = getStrength()*dist(gen)/10;
        hero_state->setHp(hero_state->getHp() - damage);
        std::cout<<getName()<<" retaliates! with "<<damage<<" damage points"<<std::endl;
    }
}

void Opponent::introduction(Hero *hero_state) {
    if (hero_state->getItem() == getReaction()){
        if (! (hero_state->getItem() == "None")){
            if (Opponent::current_state < max_state){
                setCurrentState(++Opponent::current_state);
            }
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
        std::cout<<"What do you wish to talk about with "<<getName()<<"?"<<std::endl;
        //list dialogs here
        //check if dialogs exist?
        int available_answers = 1;

        for (auto i: event_chain[current_state]->getChain()) {
            std::cout<<available_answers<<") "<<i->getQuestion()<<std::endl;
            available_answers++;
        }
        std::cout<<"a) Attack"<<std::endl;
        char selection;
        std::cin>>selection;
        int selected_dialog = selection - '0'; //convert to int, access to vector

        if (selected_dialog -1 < event_chain[current_state]->getChain().size()) {
            std::cout << "-" << event_chain[current_state]->getChain()[selected_dialog - 1]->getAnswer() << std::endl;
            if (event_chain[current_state]->getChain()[selected_dialog - 1]->isEvent_item()) {
                std::cout << "Received: " << event_chain[current_state]->getChain()[selected_dialog - 1]->getItem()
                          << std::endl;
                hero_state->setItem(event_chain[current_state]->getChain()[selected_dialog - 1]->getItem());
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
        else if (selection == 'q'){
            std::cout<<"Chose to quit"<<std::endl;
            break;
        }
        else{
            std::cout<<"Invalid input "<<selection<<std::endl;
        }
    }
}
