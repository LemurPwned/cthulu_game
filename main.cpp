#include <iostream>
#include "character.h"
#include "location.h"
#include "hero.h"
#include "FileReader.h"

int main() {
    Character hero ("Weird guy");
    hero.setHp(-10);
    //hero.introduction();

    Hero other_hero("Stupid guy, really", 30, 20);
    //other_hero.introduction();
    Location someLocation("Weird location", 15, 70);
    someLocation.fillSpaceGrid();
    //someLocation.display();

    std::string filename = R"(C:\Users\Jakub\Desktop\Locations.txt)";
    FileReader fileReader(filename);
    Location *loc = fileReader.readLocationDesc();
    std::cout<<loc->getName()<<"\n"<<loc->getDescription()<<std::endl;
    return 0;
}