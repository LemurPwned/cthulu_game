//
// Created by Jakub on 06/10/2017.
//

#include "FileReader.h"
#include "json/json.hpp"
#include <fstream>

Location* FileReader::jsonLoadLocation(const std::string &filename){
    std::ifstream stream(getPath() + filename);
    nlohmann::json j;
    stream >> j; //parse stream to json struct
    Location *location = new Location(j["name"], j["description"]);
    std::string the_path;
    for (auto character: j["characters"]) {
        if (character["path"].is_string()){
            the_path = character["path"];
            Character *character_one = jsonLoadCharacter(getPath() + the_path);
            location->addCharacters(character_one);
        }
    }
    return location;
}

Character *FileReader::jsonLoadCharacter(const std::string &filename) {
    std::ifstream stream(filename);
    nlohmann::json j;
    stream >> j; //parse stream to json struct
    Character *character = new Character(j["name"], j["description"]);
    nlohmann::json options = j;
    for (auto iterator : j["dialog"]){
        character->pushDialog(iterator["question"]); //put into ordered vectors
        character->pushAnswers(iterator["answer"]);
    }
    return character;
}

