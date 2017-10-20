//
// Created by Jakub on 06/10/2017.
//

#include <iostream>
#include "location.h"
#include "FileReader.h"

Location::Location(const std::string &name, int length, int width): name(std::move(name)),
                                                                    length(length),
                                                                    width(width) {};

Location::Location(const std::string &name, const std::string &desc) : name(name), description(desc) {
    length = 0;
    width = 0;
}

void Location::fillSpaceGrid() {
    Location::space_grid.resize(getLength(), std::vector<int>(getWidth(), 0));
    for (int i = 0; i < getLength(); ++i) {
        for (int j = 0; j < getWidth(); ++j) {
            if (i == getLength()-1 || i == 0 || j == getWidth()-1 || j == 0){
                Location::space_grid[i][j] = -1; // wall
            }
        }
    }
    setStatus(true);
}

void Location::display(){
    if (isStatus()){
        for (int i = 0; i < getLength(); ++i) {
            for (int j = 0; j < getWidth(); ++j) {
                if (Location::space_grid[i][j] == -1){
                    std::cout<<'*';
                }
                else if (Location::space_grid[i][j] == 0){
                    std::cout<<' ';
                }
            }
            std::cout<<"\n";
        }
    }
    else{
        std::cout<<"Location not defined"<<std::endl;
    }

}

void Location::introduction() {
    std::cout<<getName()<<std::endl;
    std::cout<<getDescription()<<std::endl;
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
        int option = 1;
        for (auto *character : Location::characters) {
            std::cout<<option<<") "<<character->getName()<<std::endl;
            option ++;
        }
        std::cin>>selection;
        int currently_selected = selection - '0'; //parse to int
        if (currently_selected -1 < characters.size()){
            // introduce the selected character here (character loop is invoked)
            Location::characters[currently_selected-1]->introduction(hero_state);
            if (teleport_dest != "None" && hero_state->isTeleport()){
                teleport(hero_state);
                //Location::characters[currently_selected-1]; perhaps remove teleport
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
    std::string content_pack = R"(/home/lemurpwned/repos/cthulu_game)"; //weak spot
    FileReader fr(content_pack);
    Location *location = fr.jsonLoadLocation(teleport_dest);
    location->introduction();
    location->listCharacters(hero_state);
}



