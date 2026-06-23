#ifndef WARRIOR_H
#define WARRIOR_H
#include "Character.h"
using namespace std;

class Warrior : public Character{
    protected:
            int rage;
    public:
        Warrior(string na);
        void attack(Character& target) override;
        void displayStats() override;
        void takeDamage(int dmg) override;
        void shieldBash(Character& target);
};

#endif