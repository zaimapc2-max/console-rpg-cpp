#include "Goblin.h"

Goblin::Goblin(string n,int xr,string ld):Enemy(n,xr,ld){
    name = n;
    maxHp = hp = 40;
    atkStat = 6;
    defence = 3;
    xpReward = 25;
}

void Goblin::attack(Character& target){
    cout<< "Goblin " + name + " attacks " + target.getname()<<endl;
    target.takeDamage(atkStat);
    cout<<target.getname() +" loses "<<atkStat<<" health points"<<endl;
}

void Goblin::useSpecialMove(Character& target){
    cout<<"---NO SPECIAL MOVE---"<<endl;
    attack(target);
}

void Goblin::displayStats(){
    Character::displayStats();
}