//
// Created by lemurpwned on 07/10/17.
//

#include <iostream>
#include "level_assembler.h"

Location LevelAssembler::getNextLocation() {
    Location to_return = LevelAssembler::level_chain.front();
    LevelAssembler::level_chain.pop();
    return to_return;
}