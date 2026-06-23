#include "Skeleton.h"

Skeleton::Skeleton(string n,int xr,string ld):Enemy(n,xr,ld){
    name = n;
    maxHp = hp = 50;
    atkStat = 8;
    defence = 5;
    xpReward = 30;
    damageReduction = 2;
}

void Skeleton::attack(Character& target){
    cout<< "Skeleton " + name + " attacks " + target.getname()<<endl;
    target.takeDamage(atkStat);
    cout<<target.getname() +" loses "<<atkStat<<" health points"<<endl;
}


void Skeleton::displayStats(){
    Character::displayStats();
}

void Skeleton::takeDamage(int dmg){

    int reduced = dmg - damageReduction;
    if(reduced<0){
        reduced = 0;
    }
    Character::takeDamage(reduced);
    
}