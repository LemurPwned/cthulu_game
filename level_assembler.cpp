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
    std::string content_pack = R"(/home/lemurpwned/repos/cthulu_game)";
    FileReader reader(content_pack);
    std::string locations_list[] = {R"(/Locations/Tavern)"};
    //std::string characters_list[] = {R"(/Characters/Barman)", R"(/Characters/Common_customer)"};
    int num_locs = 1;
    int num_chars = 2;
    for (int i = 0; i < num_locs ; ++i) {
        Location *location_one = reader.jsonLoadLocation(locations_list[i]);
        location_one->introduction();
        location_one->listCharacters();
    }
}

Location LevelAssembler::getNextLocation() {
    Location to_return = LevelAssembler::level_chain.front();
    LevelAssembler::level_chain.pop();
    return to_return;
}

