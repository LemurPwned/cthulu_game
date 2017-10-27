//
// Created by Jakub on 06/10/2017.
//

#include <iostream>
#include "location.h"
#include "FileReader.h"

Location::Location(const std::string &name, const std::string &desc) : abstractLocation(name, desc) {};

void Location::introduction() {
    std::cout<<getName()<<std::endl;
    std::cout<<getDescription()<<std::endl;
}

void Location::listCharacterOptions(){
    int option = 1;
    //list characters
    for (auto *character : characters) {
        std::cout<<option<<") "<<character->getName()<<std::endl;
        option ++;
    }
}
void Location::listCharacters(Hero *hero_state){
    if (!hero_state->isAlive()) return;
    std::cout<<"\nThere is someone... or something... in the "<<getName()<<std::endl;
    char selection;
    while (true){
        if (!hero_state->isAlive()){
            std::cout<<"\n DEAD \n"<<std::endl;
            return;
        }
        Location::listCharacterOptions();

        std::cin>>selection;
        int currently_selected = selection - '0'; //parse to int
        if (currently_selected -1 < characters.size()){
            // introduce the selected character here (character loop is invoked)
            characters[currently_selected-1]->introduction(hero_state);
            if (teleport_dest != "None" && hero_state->isTeleport()){
                teleport(hero_state);
                hero_state->setTeleport(false); //disable teleport
            }
        }
        else if (selection == 'q'){
            std::cout<<"Leaving "<<getName()<<std::endl;
            break;
        }
        else{
            std::cout<<"Invalid input "<<selection<<std::endl;
        }
    }
}

void Location::teleport(Hero *hero_state) {
    std::string content_pack = R"(/home/lemurpwned/repos/cthulu_game)";
    FileReader *fr = new FileReader(content_pack);
    abstractLocation *location = fr->jsonLoadLocation(teleport_dest);
    //implicit downcast here because must use implementation
    location->introduction();
    location->listCharacters(hero_state);
}



