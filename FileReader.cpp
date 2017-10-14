//
// Created by Jakub on 06/10/2017.
//

#include "FileReader.h"
#include "opponent.h"
#include "Statistics.h"
#include <fstream>

Location* FileReader::jsonLoadLocation(const std::string &filename){
    Statistics::addLocations_visited();
    std::ifstream stream(getPath() + filename);
    nlohmann::json j;
    stream >> j; //parse stream to json struct
    std::string description_to_write; // string containing whole description
    for (auto &desc_part : j["description"]){
        description_to_write.append(desc_part);
        description_to_write.append("\n");
    }
    Location *location = new Location(j["name"], description_to_write);
    if (!j["teleport"].is_null()) {
        std::string destination = j["teleport"];
        location->setTeleportDestination(destination);
    }
    std::string the_path;
    for (auto &character: j["characters"]) {
        if (character["path"].is_string()) { // make sure path is a string
            the_path = character["path"];
            Character *character_one = jsonLoadCharacter(getPath() + the_path);
            location->addCharacters(character_one);
        }
    }
    return location;
}

Character *FileReader::jsonLoadCharacter(const std::string &filename) {
    Statistics::addCharacters();
    std::ifstream stream(filename);
    nlohmann::json j;
    stream >> j; //parse stream to json struct
    Character *character;
    if (j["type"].is_null()){
        character = new Character(j["name"], j["description"]);
    }
    else if (j["type"] == "mob"){
        character = new Opponent(j["name"], j["description"], j["strength"]);
        //ugh such polymorphism
    }
    std::vector<EventChain*> chain = jsonFormEvent(j["dialog"]);
    character->setChain(chain);
    if (!j["react"].is_null()){ // if there is some reaction to an item, then set it here
        for (auto &reaction : j["react"]){
            // add to character reactions_list
            character->setMax_state(character->getMax_state()+1);
            character->pushReaction(reaction);
        }
    }
    return character;
}

std::vector<EventChain*> FileReader::jsonFormEvent(nlohmann::json dialog_options){
    std::vector<EventChain*> events;
    EventChain* temp_chain;
    bool should_teleport = false;
    int i, id;
    std::string answer, question;
    for (auto &dialog : dialog_options){
        id = dialog["id"];
        temp_chain = new EventChain(id);
        i = 0;
        Event *temp_event;
        for (auto option : dialog["option"]){
            answer = "";
            question = "";
            i++;
            if (option["teleport"].is_boolean()){
                should_teleport = option["teleport"];
            }
            if (option["answer"].is_array()) {
                for (auto &line : option["answer"]) {
                    answer.append(line);
                }
            }
            else{
                answer = option["answer"];
            }
            if (option["question"].is_array()){
                for (auto &line : option["question"]){
                    question.append(line);
                }
            }
            else{
                question = option["question"];
            }

            if ((option["item"].is_null()) && (option["effect"].is_null())){
                // use standard constructor if no item given during the dialogue
                temp_event = new Event(i, "dialog", question, answer);
                temp_event->setTeleport(should_teleport);
            }
            else if (!option["item"].is_null()){
                //if you get item during an event, check here
                std::string possible_item = option["item"];
                Statistics::addItems();
                //this is done to avoid object type ambiguity in Event constructor
                temp_event = new Event(i, "dialog", question, answer, possible_item);
                temp_event->setTeleport(should_teleport);
                if (!option["effect"].is_null()){
                    //set an effect here
                    int effect = option["effect"];
                    temp_event->setEffect(effect);
                }
            }
            else {
                // push if there is an effect
                int effect = option["effect"];
                // again explicit declaration of type, constructor indicator
                temp_event = new Event(i, "dialog", question, answer, effect);
                temp_event->setTeleport(should_teleport);
            }
            Statistics::addEvents();
            temp_chain->pushChain(temp_event);
        }
        events.push_back(temp_chain);
    }
    return events;
}

FileReader::~FileReader(){
    std::cout<<"Closing reading capabilities..."<<std::endl;
};



