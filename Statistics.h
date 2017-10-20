//
// Created by lemurpwned on 14/10/17.
//

#ifndef CTHULU_GAME_STATISTICS_H
#define CTHULU_GAME_STATISTICS_H

#include <iostream>
#include <vector>

class Statistics {
private:
    static int locations_visited;
    static int characters;
    static int damage_dealt;
    static int damaged_received;
    static int items_received;
    static int events;
    static int items;
    static int enemies_defeated;

    static int statistics_count;

    Statistics() = default;

public:
    static Statistics* initializeStatistics();

    static void addLocations_visited() {
        Statistics::locations_visited++;
    }

    static void addCharacters() {
        Statistics::characters++;
    }

    static void addEvents(){
        Statistics::events ++;
    }

    static void addDamage_dealt(int dmg) {
        Statistics::damage_dealt += dmg;
    }

    static void addDamaged_received(int dmg) {
        Statistics::damaged_received += dmg;
    }

    static void addItems_received() {
        Statistics::items_received++;
    }

    static void addItems(){
        items++;
    }

    static void addEnemies_defeated(){
        enemies_defeated++;
    }

    int operator [](const std::string &kind);

    friend std::ostream &operator<< (std::ostream &output, Statistics &stat);

};
#endif //CTHULU_GAME_STATISTICS_H
