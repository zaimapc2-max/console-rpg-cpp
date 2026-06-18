#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <string>
using namespace std;

class Character{
    protected:
        string name;
        int hp,maxHp,mana,maxMana,atkStat,defence,level,xp;
    public:
        Character(string n);   //constructor

        //getters
        int gethp();
        int getmaxHp();
        int getmana();
        int getmaxMana();
        int getatkStat();
        int getdefence();
        int getlevel();
        int getxp();
        string getname();

        //virtual destructor
        virtual ~Character();

        //pure virtual
        virtual void attack(Character& target)= 0;

        //virtual
        virtual void takeDamage(int dmg);
        virtual bool isAlive();
        virtual void displayStats();

};



#endif