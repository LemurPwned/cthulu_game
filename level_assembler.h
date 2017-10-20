//
// Created by lemurpwned on 07/10/17.
//

#ifndef CTHULU_GAME_LEVEL_ASSEMBLER_H
#define CTHULU_GAME_LEVEL_ASSEMBLER_H

#include <queue>
#include "location.h"
#include "FileReader.h"

class LevelAssembler{
private:
    std::vector<Location*> level_chain;

    static int assemblers_count;

    int num_locs = 3;

    LevelAssembler();
public:
    static void runLevelAssemblerInstance();

    void createLevelChain();

    Location* pickPlace();

    void gameLoop(Hero *hero);

    void loadGameFiles(FileReader &reader, std::string *list);

    void bonusLevel(FileReader &reader, Hero *state);
};
#endif //CTHULU_GAME_LEVEL_ASSEMBLER_H
