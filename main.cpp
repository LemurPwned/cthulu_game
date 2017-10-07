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

    std::string loc_filename = R"(/home/lemurpwned/repos/cthulu_game/Locations/Location1)";
    FileReader fileReader(loc_filename);
    Location *loc = fileReader.readLocationDesc();
    std::cout<<loc->getName()<<"\n"<<loc->getDescription()<<std::endl;

    std::string char_filename = R"(/home/lemurpwned/repos/cthulu_game/Characters/Bartender)";
    fileReader.setFilename(char_filename);
    Character *cha = fileReader.readCharacterDesc();
    cha->introduction();

    return 0;
}