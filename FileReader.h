//
// Created by Jakub on 06/10/2017.
//

#ifndef CTHULU_GAME_FILEREADER_H
#define CTHULU_GAME_FILEREADER_H

#include <string>
#include <utility>
#include "location.h"
#include "character.h"

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
        FileReader::path = filepath;
    }
};
#endif //CTHULU_GAME_FILEREADER_H
