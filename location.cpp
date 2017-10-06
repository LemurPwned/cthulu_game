//
// Created by Jakub on 06/10/2017.
//

#include <iostream>
#include "location.h"

void Location::fillSpaceGrid() {
    Location::space_grid.resize(getLength(), std::vector<int>(getWidth(), 0));
    for (int i = 0; i < getLength(); ++i) {
        for (int j = 0; j < getWidth(); ++j) {
            if (i == getLength()-1 || i == 0 || j == getWidth()-1 || j == 0){
                Location::space_grid[i][j] = -1; // wall
            }
        }
    }
    setStatus(true);
}

void Location::display(){
    if (isStatus()){
        for (int i = 0; i < getLength(); ++i) {
            for (int j = 0; j < getWidth(); ++j) {
                if (Location::space_grid[i][j] == -1){
                    std::cout<<'*';
                }
                else if (Location::space_grid[i][j] == 0){
                    std::cout<<' ';
                }
            }
            std::cout<<"\n";
        }
    }
    else{
        std::cout<<"Location not defined"<<std::endl;
    }

}

Location::Location(const std::string &name, int length, int width): name(std::move(name)),
                                                                    length(length),
                                                                    width(width) {};

Location::Location(const std::string &name, const std::string &desc) : name(name), description(desc) {
    length = 0;
    width = 0;
}


