#ifndef ARCHER_H
#define ARCHER_H
#include <cstdlib>
#include "Character.h"

class Archer : public Character{
    protected:
        int critChance;
    public:
        Archer(string na);
        void attack(Character& target) override;
        void displayStats() override;
        void arrowRain(Character& target);
};



#endif