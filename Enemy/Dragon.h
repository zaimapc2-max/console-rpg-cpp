#ifndef DRAGON_H
#define DRAGON_H
#include "Enemy.h"
#include <string>

class Dragon : public Enemy{
    protected:
    bool usedFire;
    public:
        Dragon(string n,int xr,string ld);
        void attack(Character& target) override;
        void fireBreath(Character& target);
        bool isEnraged();
        void displayStats() override;
        void useSpecialMove(Character& target);

};

#endif