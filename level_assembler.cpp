//
// Created by lemurpwned on 07/10/17.
//

#include <iostream>
#include "level_assembler.h"
#include "FileReader.h"

LevelAssembler::LevelAssembler() {
    createLevelChain();
}

void LevelAssembler::createLevelChain() {
    std::string content_pack = R"(/home/lemurpwned/repos/cthulu_game)"; //change here to get proper paths
    FileReader reader(content_pack);
    std::string locations_list[] = {R"(/Locations/Tavern)", R"(/Locations/Shipyard)"};
    int num_locs = 2;

    //initialize hero state
    Hero *hero = new Hero ("A man");
    for (int i = 0; i < num_locs ; ++i) {
        Location *location_one = reader.jsonLoadLocation(locations_list[i]);
        level_chain.push_back(location_one); //fill location chain
    }
    while(true) {
        Location *picked = pickPlace();
        if (picked == nullptr){ //provides quitting capability
            break;
        }
        picked->introduction();
        picked->listCharacters(hero);
    }
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


