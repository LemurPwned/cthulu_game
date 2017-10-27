//
// Created by Jakub on 06/10/2017.
//

#include <iostream>
#include "json/json.hpp"
#include <fstream>
#include <random>
#include "Statistics.h"
#include "Randomizer.h"
#include "character.h"

Character::Character() {
    Character::name = "A stranger";
    Character::hp = 100;
}

void Character::introduction(Hero *hero_state) {
    Character::checkCurrentState(hero_state);
    //standard character introduction
    Character::introduction();

    while(true){
        //list dialogs here
        //check if dialogs exist?
        Character::listDialogOptions(hero_state);

        char selection;
        std::cin>>selection;
        int selected_dialog = selection - '0'; //convert to int, access to vector
        std::string the_item;
        if (selected_dialog -1 < event_chain[current_state]->getChain().size()){
            std::cout<<"-"<<event_chain[current_state]->getChain()[selected_dialog-1]\
                                                        ->getAnswer()<<std::endl;
            if (event_chain[current_state]->getChain()[selected_dialog-1]->isEvent_item()){
                // item reception happens here
                the_item = event_chain[current_state]->getChain()[selected_dialog-1]->getItem();
                std::cout<<"\nReceived: "<<the_item<<std::endl;
                // add item to inventory
                hero_state->pushItem(the_item);
                Statistics::addItems_received();
                // set item to zero
                event_chain[current_state]->getChain()[selected_dialog-1]->setEvent_item(false);
            }
            if(event_chain[current_state]->getChain()[selected_dialog-1]->isEffect()){
                hero_state->setFear_level(event_chain[current_state]\
                                             ->getChain()[selected_dialog-1]->getEffect());
                // remove the effect
                event_chain[current_state]->getChain()[selected_dialog-1]->setEffect(0);
            }
            if (event_chain[current_state]->getChain()[selected_dialog-1]->isTeleport()){
                hero_state->setTeleport(true); //hero should be teleported somewhere
                event_chain[current_state]->getChain()[selected_dialog-1]->disableTeleport();
                // teleportation event is triggered only once
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

Character::~Character() {
    std::cout<<"Deleting a character: "<<getName()<<std::endl;
}

void Character::refactorString(std::string &text, int scaler) {
    //get how many characters to change in a string
    if (scaler < 0){
        //safety return if hero starts with a negative fear level (possible and planned)
        return;
    }
    unsigned long int txt_size = text.size()-1;
    unsigned long int letters_to_randomize = scaler*txt_size/100;
    int position;
    for (int i = 0; i < letters_to_randomize; ++i) {
        //draw a position
        position = Randomizer::generateRandomToken(txt_size);
        //draw a sign at this position
        text[position] = Randomizer::drawRandomSign();
    }
}

void Character::introduction() {
    std::cout<<getName()<<std::endl;
    if (!isAlive()) {
        std::cout<<"He is totally dead"<<std::endl;
        return;
    }
    std::cout<<getDescription()<<std::endl;
}

void Character::checkCurrentState(Hero *hero_state) {
    //this function changes character state depending on the hero_state
    for (int i = 0; i < reaction_set.size(); i++){
        if (hero_state->isInInventory(reaction_set[i])){
            setCurrentState(i+1);
        }
    }
}

void Character::listDialogOptions(Hero *hero_state) {
    std::cout<<"What do you wish to talk about with "<<getName()<<"?"<<std::endl;
    int available_answers = 1;
    for (auto i: event_chain[current_state]->getChain()) {
        std::string possible_question = i->getQuestion();
        //change the questions depending on the fear level
        refactorString(possible_question, hero_state->getFear_level()/20);
        std::cout<<available_answers<<") "<<possible_question<<std::endl;
        available_answers++;
    }
}
