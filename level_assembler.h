//
// Created by lemurpwned on 07/10/17.
//

#ifndef CTHULU_GAME_LEVEL_ASSEMBLER_H
#define CTHULU_GAME_LEVEL_ASSEMBLER_H

#include <queue>
#include "location.h"

class LevelAssembler{
private:
    std::vector<Location*> level_chain;
public:
    LevelAssembler();

    void createLevelChain();

    Location* pickPlace();
};
#endif //CTHULU_GAME_LEVEL_ASSEMBLER_H
