//
// Created by Jakub on 06/10/2017.
//

#ifndef CTHULU_GAME_FILEREADER_H
#define CTHULU_GAME_FILEREADER_H

#include "location.h"
#include <string>
#include <utility>
#include "character.h"
#include "Event.h"
#include "json/json.hpp"
#include "EventChain.h"

class FileReader{
private:
    std::string path = "";

public:
    FileReader() = default;

    explicit FileReader(const std::string folder_path): path(folder_path) {}

    abstractLocation * jsonLoadLocation(const std::string &filename);

    Character* jsonLoadCharacter(const std::string &filename);

    std::string getPath() {
        return path;
    }

    void setPath(std::string &filepath) {
        path = filepath;
    }

    std::vector<EventChain*> jsonFormEvent(nlohmann::json dialog);

    std::string processHeroName();

    ~FileReader();
};
#endif //CTHULU_GAME_FILEREADER_H
