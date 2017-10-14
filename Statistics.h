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

    static void addDamage_dealt() {
        Statistics::damage_dealt++;
    }

    static void addDamaged_received() {
        Statistics::damaged_received++;
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

    int operator [] (const std::string &kind);

    friend std::ostream &operator<< (std::ostream &output, Statistics &stat){
        output <<"Player's statistics:\n";
        output <<"Items collected: "<<items_received<<" out of "<<items<<std::endl;
        output <<"Damage dealt: "<<damage_dealt<<std::endl;
        output <<"Damage received: "<<damaged_received<<std::endl;
        output <<"Locations: "<<locations_visited<<std::endl;
        output <<"Enemies defeated: "<<enemies_defeated<<std::endl;
        //more stats if needed
        return output;
    }

};
#endif //CTHULU_GAME_STATISTICS_H
