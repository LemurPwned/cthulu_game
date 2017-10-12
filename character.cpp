//
// Created by Jakub on 06/10/2017.
//

#include <iostream>
#include "json/json.hpp"
#include <fstream>
#include "character.h"

Character::Character() {
    Character::name = "A stranger";
    Character::hp = 100;
}

void Character::introduction(Hero *hero_state) {
    for (int i = 0; i < reaction_set.size(); i++){
        if (hero_state->isInInventory(reaction_set[i])){
            setCurrentState(i+1);
        }
    }
    //standard character introduction
    std::cout<<"This person's name is: "<<getName()<<std::endl;
    if (!isAlive()) {
        std::cout<<"He is totally dead"<<std::endl;
        return;
    }
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
        std::string the_item;
        if (selected_dialog -1 < event_chain[current_state]->getChain().size()){
            std::cout<<"-"<<event_chain[current_state]->getChain()[selected_dialog-1]->getAnswer()<<std::endl;
            if (event_chain[current_state]->getChain()[selected_dialog-1]->isEvent_item()){
                //item reception happens here
                the_item = event_chain[current_state]->getChain()[selected_dialog-1]->getItem();
                std::cout<<"\nReceived: "<<the_item<<std::endl;
                // add item to inventory
                hero_state->pushItem(the_item);
            }
            if(event_chain[current_state]->getChain()[selected_dialog-1]->isEffect()){
                std::cout<<"EFFECT IS ENABLED"<<std::endl;
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
        else if (selection == 'q'){
            std::cout<<"Chose to quit"<<std::endl;
            break;
        }
        else{
            std::cout<<"Invalid input "<<selection<<std::endl;
        }
    }
}