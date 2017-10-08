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

void Character::loadCharacter(const std::string &filename) {
    std::ifstream stream(filename);
    nlohmann::json j;
    stream >> j; //parse stream to json struct
    setName(j["character"]["name"]);
    setDescription(j["character"]["description"]);
}

void Character::introduction() {
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
        for (auto i: dialog_options) {
            std::cout<<available_answers<<") "<<i<<std::endl;
            available_answers++;
        }
        char selection;
        std::cin>>selection;
        int selected_dialog = selection - '0'; //convert to int, access to vector

        if (selected_dialog -1 < dialog_options.size()){
            std::cout<<"-"<<dialog_answers[selected_dialog -1]<<std::endl;
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