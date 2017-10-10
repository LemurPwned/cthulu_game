//
// Created by Jakub on 06/10/2017.
//

#include <iostream>
#include "json/json.hpp"
#include <fstream>
#include "character.h"

Character::Character() {
    Character::name = "A stranger";
    Character::alive = true;
    Character::hp = 100;
}

void Character::introduction(Hero *hero_state) {
    if (hero_state->getItem() == getReaction()){
        if (! (hero_state->getItem() == "None")){
            if (Character::current_state < max_state){
                setCurrentState(++Character::current_state);
            }
        }
    }
    //standard character introduction
    std::cout<<"This person's name is: "<<getName()<<std::endl;
    //std::cout<<"He would not admit it but his hp is currently at "<<getHp()<<std::endl;
    if (!isAlive()) std::cout<<"He is totally dead"<<std::endl;
    std::cout<<getDescription()<<std::endl;

    while(true){
        std::cout<<"What do you wish to talk about with "<<getName()<<"?"<<std::endl;
        //list dialogs here
        //check if dialogs exist?
        int available_answers = 1;

        for (auto i: event_chain[current_state]->getChain()) {
            std::cout<<available_answers<<") "<<i->getQuestion()<<std::endl;
            available_answers++;
        }
        char selection;
        std::cin>>selection;
        int selected_dialog = selection - '0'; //convert to int, access to vector

        if (selected_dialog -1 < event_chain[current_state]->getChain().size()){
            std::cout<<"-"<<event_chain[current_state]->getChain()[selected_dialog-1]->getAnswer()<<std::endl;
            if (event_chain[current_state]->getChain()[selected_dialog-1]->isEvent_item()){
                std::cout<<"Received: "<<event_chain[current_state]->getChain()[selected_dialog-1]->getItem()<<std::endl;
                hero_state->setItem(event_chain[current_state]->getChain()[selected_dialog-1]->getItem());
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