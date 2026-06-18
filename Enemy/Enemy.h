#ifndef ENEMY_H
#define ENEMY_H
#include "Character.h"
using namespace std;

class Enemy:public Character{
    protected:
        int xpReward;
        string lootDrop;
    public:
        Enemy(string na,int xr,string ld);
        virtual void attack(Character& target) = 0;
        int getxpReward();
        string getlootDrop();
        virtual ~Enemy();

};




#endif