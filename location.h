//
// Created by Jakub on 06/10/2017.
//

#ifndef CTHULU_GAME_LOCATION_H
#define CTHULU_GAME_LOCATION_H

#include <string>
#include <utility>
#include <vector>

class Location{
private:
    std::string name;
    std::string description;

    int length;
    int width;
    bool status = false;

    std::vector<std::vector<int>> space_grid;
public:
    Location(const std::string &name, int length, int width);

    Location(const std::string &name, const std::string &desc);

    void setLength(int length) {
        Location::length = length;
    }

    void setWidth(int width) {
        Location::width = width;
    }

    bool isStatus() const {
        return status;
    }

    const std::string &getDescription() const {
        return description;
    }

    void setStatus(bool status) {
        Location::status = status;
    }

    void fillSpaceGrid();

    void display();

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        Location::name = name;
    }

    unsigned int getLength() const {
        return length;
    }

    unsigned int getWidth() const {
        return width;
    }

};
#endif //CTHULU_GAME_LOCATION_H
