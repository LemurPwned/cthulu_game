//
// Created by lemurpwned on 07/10/17.
//

#include <iostream>
#include "level_assembler.h"
#include "FileReader.h"
#include "Statistics.h"

//initialize Hero
int LevelAssembler::assemblers_count = 0;

LevelAssembler::LevelAssembler() {
    LevelAssembler::assemblers_count++;
    createLevelChain();
}

void LevelAssembler::createLevelChain() {
    std::string content_pack = R"(/home/lemurpwned/repos/cthulu_game)"; //change here to get proper paths
    std::cout<<"GAME FILES PATH: " <<content_pack<<std::endl;
    FileReader reader(content_pack);
    std::string locations_list[] = {R"(/Locations/Tavern)", R"(/Locations/Shipyard)", R"(/Locations/Cave)"};
    int num_locs = 3; // remember to update here

    //initialize hero state
    Hero *hero = Hero::getHeroObject("A man"); // get static initializer
    if (hero == nullptr) return; //quit if applicable

    hero->setStrength(70); // set some arbitrary strength

    Statistics *generals = Statistics::initializeStatistics(); //initialize local statistics

    for (int i = 0; i < num_locs ; ++i) {
        Location *location_one = reader.jsonLoadLocation(locations_list[i]);
        level_chain.push_back(location_one); //fill location chain
    }
    while(true) {
        if (!hero->isAlive()) break; // quit outer loop
        Location *picked = pickPlace();
        if (picked == nullptr){ //provides quitting capability
            break;
        }
        picked->introduction();
        picked->listCharacters(hero);
    }

    std::cout<<(*generals)<<std::endl;

    //free the resources
    delete hero;
    delete &reader;
}

Location* LevelAssembler::pickPlace(){
    std::cout<<"Where you choose to go?"<<std::endl;
    char selection;
    int selected_num;
    while(true){
        int i = 1;
        //display possible locations
        for (Location *loc: level_chain) {
            std::cout<<i<<") "<<loc->getName()<<std::endl;
            i++;
        }
        std::cin>>selection;
        selected_num = selection - '0'; //convert to 0
        if (selected_num-1 < level_chain.size()) {
            break;
        }

        else if (selection == 'q'){
            return nullptr;
        }
        else{
            std::cout<<"Invalid input, try again"<<std::endl;
        }
    }
    return level_chain[selected_num-1];
}

void LevelAssembler::runLevelAssemblerInstance() {
    if (assemblers_count >= 1){
        std::cout<<"There is already an object of instance Level Assembler"<<std::endl;
    }
    else{
        LevelAssembler();
    }
}

