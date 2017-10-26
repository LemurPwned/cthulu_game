//
// Created by lemurpwned on 26/10/17.
//

#ifndef CTHULU_GAME_ABSTRACTLOCATION_H
#define CTHULU_GAME_ABSTRACTLOCATION_H

#include <string>
#include "hero.h"
#include "character.h"

class abstractLocation {
private:
    std::string name;
    std::string description;
protected:
    std::vector<Character*> characters;
    std::string teleport_dest;

public:
    abstractLocation() = default;

    abstractLocation(const std::string &name, const std::string &description):
            name(name), description(description){};

    virtual void listCharacters(Hero *hero) = 0;

    virtual void introduction() = 0;

    void setTeleportDestination(std::string &teleport_destination){
        abstractLocation::teleport_dest = teleport_destination;
    }

    void addCharacters(Character *character){
        characters.push_back(character);
    }

    void setName(std::string &name){
        abstractLocation::name = name;
    }

    void setDescription(std::string &description){
        abstractLocation::description = description;
    }

    std::string getName(){
        return name;
    }

    std::string getDescription(){
        return description;
    }


};
#endif //CTHULU_GAME_ABSTRACTLOCATION_H
