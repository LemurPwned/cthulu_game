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
    std::string filename;

public:
    FileReader(std::string filename): filename(std::move(filename)) {};

    Location* readLocationDesc();

    Character* readCharacterDesc();

    const std::string &getFilename() const {
        return filename;
    }

    void setFilename(const std::string &filename) {
        FileReader::filename = filename;
    }
};
#endif //CTHULU_GAME_FILEREADER_H
