//
// Created by Jakub on 06/10/2017.
//

#include "FileReader.h"
#include <fstream>
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
        else{
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
    int line_counter = 0;

    std::string name;
    std::string desc;

    while(std::getline(file, line)){
        if (line_counter%2 == 0){
            name.append(line);
        }
        else if (line_counter%2 == 1){
            desc.append(line);
        }
        line_counter ++;
    }
    return new Character(name, desc);
}