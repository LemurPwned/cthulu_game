//
// Created by Jakub on 06/10/2017.
//

#include "FileReader.h"
#include <fstream>

Location* FileReader::jsonLoadLocation(const std::string &filename){
    std::ifstream stream(getPath() + filename);
    nlohmann::json j;
    stream >> j; //parse stream to json struct
    Location *location = new Location(j["name"], j["description"]);
    std::string the_path;
    for (auto character: j["characters"]) {
        if (character["path"].is_string()){ // make sure path is a string
            the_path = character["path"];
            Character *character_one = jsonLoadCharacter(getPath() + the_path);
            location->addCharacters(character_one);
        }
    }
    return location;
}

Character *FileReader::jsonLoadCharacter(const std::string &filename) {
    std::string filename2 = R"(/home/lemurpwned/repos/cthulu_game/Characters/Captain)";
    std::ifstream stream(filename);
    nlohmann::json j;
    stream >> j; //parse stream to json struct
    Character *character = new Character(j["name"], j["description"]);
    nlohmann::json options = j;

    std::vector<EventChain*> chain = jsonFormEvent(j["dialog"]);
    character->setChain(chain);
    if (!j["react"].is_null()){ // if there is some reaction to an item, then set it here
        character->setReactive(j["react"]);
        character->setMax_state(character->getMax_state()+1);
    }
    return character;
}

std::vector<EventChain*> FileReader::jsonFormEvent(nlohmann::json dialog_options){
    std::vector<EventChain*> events;
    EventChain* temp_chain;
    int i, id;
    for (auto dialog : dialog_options){
        id = dialog["id"];
        temp_chain = new EventChain(id);
        i = 0;
        Event *temp_event;
        for (auto option : dialog["option"]){
            i++;
            if (option["item"].is_null()){ // use standard constructor if no item given during the dialogue
                temp_event = new Event(i, "dialog", option["question"], option["answer"]);
            }
            else{
                //if you get item during an event, check here
                temp_event = new Event(i, "dialog", option["question"], option["answer"], option["item"]);
            }
            temp_chain->pushChain(temp_event);
        }
        events.push_back(temp_chain);
    }
    return events;
}



