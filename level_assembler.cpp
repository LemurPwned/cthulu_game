//
// Created by lemurpwned on 07/10/17.
//
#include <iostream>
#include "level_assembler.h"
#include "FileReader.h"
#include "Statistics.h"

int LevelAssembler::assemblers_count = 0;

LevelAssembler::LevelAssembler() {
    LevelAssembler::assemblers_count++;
    createLevelChain();
}

void LevelAssembler::gameLoop(Hero *state){
    while(true) {
        if (!state->isAlive()) break; // quit outer loop
        abstractLocation *picked = pickPlace();
        if (picked == nullptr){ //provides quitting capability
            break;
        }
        picked->introduction();
        picked->listCharacters(state);
    }
}

void LevelAssembler::loadGameFiles(FileReader &reader, std::string *list){
    for (int i = 0; i < num_locs ; ++i) {
        abstractLocation *location_one = reader.jsonLoadLocation(list[i]);
        level_chain.push_back(location_one); //fill location chain
    }
}

void LevelAssembler::createLevelChain() {
    std::string content_pack = R"(/home/lemurpwned/repos/cthulu_game)"; //change here to get proper paths
    std::cout<<"GAME FILES PATH: " <<content_pack<<std::endl;
    FileReader reader(content_pack);
    //std::string hero_name = reader.processHeroName();
    std::string hero_name = "A stranger";
    std::string locations_list[] = {R"(/Locations/Tavern)", R"(/Locations/Shipyard)", R"(/Locations/Cave)",
                                    R"(/Locations/Bar)"};
    //initialize hero state
    Hero *hero = Hero::getHeroObject(hero_name); // get static initializer
    if (hero == nullptr) return; //quit if applicable
    hero->setStrength(70); // set some arbitrary strength

    Statistics *generals = Statistics::initializeStatistics(); //initialize local statistics

    loadGameFiles(reader, locations_list); // read game files
    gameLoop(hero); // run the loop

    std::cout<<(*generals)<<std::endl; //print out statistics before rolling credits
    //free the resources
    Hero *soul = Hero::createSoul(hero);
    //used copying constructor to copy some traits into soul

    bonusLevel(reader, soul);
    //finally free everything
    delete soul;
    delete hero;
    delete &reader;
}

void LevelAssembler::bonusLevel(FileReader &reader, Hero *state){
    if (state->getFear_level() < 35){
        level_chain.clear();
        std::string soul_locations_list[] = {R"(/Locations/Valhalla)"};

        std::cout<<"You've died but your soul does not cease to exist..."<<std::endl;
        LevelAssembler::num_locs = 1;
        loadGameFiles(reader, soul_locations_list);
        gameLoop(state);
        std::cout<<"You've ended your journey for good..."<<std::endl;
    }
    else{
        std::cout<<"You have not deserved a proper rest, die now"<<std::endl;
    }

}

abstractLocation* LevelAssembler::pickPlace(){
    std::cout<<"Where you choose to go?"<<std::endl;
    char selection;
    int selected_num;
    while(true){
        int i = 1;
        //display possible locations
        for (abstractLocation *loc: level_chain) {
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

