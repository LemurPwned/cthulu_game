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

    static int assemblers_count;

    LevelAssembler();
public:
    static void runLevelAssemblerInstance();

    void createLevelChain();

    Location* pickPlace();
};
#endif //CTHULU_GAME_LEVEL_ASSEMBLER_H
