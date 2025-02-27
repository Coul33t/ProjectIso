#ifndef _PROJECTISO_STATS_H_
#define _PROJECTISO_STATS_H_

#include <string>

struct Stats {
    int max_hp, current_hp;
    int max_ressource, current_ressource;
    int defence, dodge, resistance, faith, speed, movement;
    int attack, ranged, magic;

    std::string ressource_name;

    Stats() = default;
    Stats(int hp, int rsc, int def, int dge, int res, in fth, int spd, int mov): 
        max_hp(hp), current_hp(hp), max_ressource(res), current_ressource(rsc), defence(def), dodge(dge), 
        resistance(res), faith(fth), speed(spd), movement(mov) {}
}

#endif