//
// Created by lemurpwned on 07/10/17.
//

#ifndef CTHULU_GAME_LEVEL_ASSEMBLER_H
#define CTHULU_GAME_LEVEL_ASSEMBLER_H

#include <queue>
#include "location.h"

class LevelAssembler{
private:
    std::queue<Location> level_chain;
public:
    Location getNextLocation();
    void putNextLocation(Location &loc){
        level_chain.push(loc);
    };
    void associateCharacters(Location &loc);
};
#endif //CTHULU_GAME_LEVEL_ASSEMBLER_H
