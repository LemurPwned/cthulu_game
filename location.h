//
// Created by lemurpwned on 06/10/2017.
//

#ifndef CTHULU_GAME_LOCATION_H
#define CTHULU_GAME_LOCATION_H

#include <string>
#include <utility>
#include <vector>
#include "character.h"
#include "hero.h"
#include "abstractLocation.h"

class Location: public abstractLocation{
public:
    Location(const std::string &name, const std::string &desc);

    void introduction() override ;

    void teleport(Hero *hero_state);

    void listCharacters(Hero *hero_state) override;

    void listCharacterOptions();
};
#endif //CTHULU_GAME_LOCATION_H
