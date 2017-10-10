//
// Created by Jakub on 06/10/2017.
//

#ifndef CTHULU_GAME_FILEREADER_H
#define CTHULU_GAME_FILEREADER_H

#include <string>
#include <utility>
#include "location.h"
#include "character.h"
#include "Event.h"
#include "json/json.hpp"
#include "EventChain.h"

class FileReader{
private:
    std::string path = "";

public:
    FileReader() = default;

    explicit FileReader(std::string folder_path): path(folder_path) {}

    Location* jsonLoadLocation(const std::string &filename);

    Character* jsonLoadCharacter(const std::string &filename);

    const std::string getPath() {
        return path;
    }

    void setPath(const std::string &filepath) {
        path = filepath;
    }

    std::vector<EventChain*> jsonFormEvent(nlohmann::json dialog);
};
#endif //CTHULU_GAME_FILEREADER_H
