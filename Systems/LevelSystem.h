#ifndef LEVELSYSTEM_H
#define LEVELSYSTEM_H

#include "../Character/Character.h"

class LevelSystem {
public:
    static void gainXp(Character& character, int amount);
    static void levelUp(Character& character);
};

#endif