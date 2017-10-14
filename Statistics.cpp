//
// Created by lemurpwned on 14/10/17.
//

#include "Statistics.h"
//zero all statistics
int Statistics::statistics_count = 0;
int Statistics::characters = 0;
int Statistics::locations_visited = 0;
int Statistics::damage_dealt = 0;
int Statistics::damaged_received = 0;
int Statistics::items_received = 0;
int Statistics::items = 0;
int Statistics::enemies_defeated = 0;
int Statistics::events = 0;

Statistics *Statistics::initializeStatistics() {
    std::cout<<"Initializing an object no:"<<statistics_count<<std::endl;
    statistics_count++;
    return new Statistics();
}

int Statistics::operator[](const std::string &kind) {
    if (kind == "damage_dealt"){
        return damage_dealt;
    }
    else if (kind == "damage_received"){
        return damaged_received;
    }
    else if (kind == "characters"){
        return characters;
    }
    else if (kind == "locations"){
        return locations_visited;
    }
    else if (kind == "items"){
        return items;
    }
    else if (kind == "items_received"){
        return items_received;
    }
    else if (kind == "events"){
        return events;
    }
    else{
        std::cout<<"Invalid input...\n";
        return -1;
    }
}


