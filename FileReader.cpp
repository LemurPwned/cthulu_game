//
// Created by Jakub on 06/10/2017.
//

#include "FileReader.h"
#include <fstream>
#include <cstdlib>
#include <sstream>

Location* FileReader::readLocationDesc() {
    const std::string name_prefix = "Name:";
    const std::string desc_prefix = "Desc:";
    std::ifstream file;
    file.open(getFilename());
    if (!file){
        std::cout<<"There was an error while opening file"<<std::endl;
        exit(-1);
    }
    std::string line;

    std::string name;
    std::string desc;
    bool attribute = true;
    while (std::getline(file, line)){
        if (attribute){
            name.append(line);
            attribute = false;
        }
        else if (!attribute){
            desc.append(line);
        }
    }

    return new Location(name, desc);
}

Character* FileReader::readCharacterDesc() {
    std::ifstream file;
    file.open(getFilename());
    if (!file){
        std::cout<<"There was an error while opening file"<<std::endl;
        exit(-1);
    }
    std::string line;

    return new Character("RANDOM");
}