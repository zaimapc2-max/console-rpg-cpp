#ifndef SKELETON_H
#define SKELETON_H
#include "Enemy.h"
#include <string>

class Skeleton : public Enemy{
    int damageReduction;
    public:
        Skeleton(string n,int xr,string ld);
        void attack(Character& target) override;
        void displayStats() override;
        void takeDamage(int dmg) override;
};

#endif