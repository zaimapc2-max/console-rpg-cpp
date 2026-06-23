#ifndef GOBLIN_H
#define GOBLIN_H
#include "Enemy.h"
#include <string>

class Goblin : public Enemy{
    public:
        Goblin(string n,int xr,string ld);
        void attack(Character& target) override;
        void displayStats() override;
};

#endif