#include "Character.h"

Character::Character(string n){
    name = n;
    hp = maxHp= 100;
    mana = maxMana = 50;
    atkStat = 10;
    defence = 5;
    level = 1;
    xp = 0;
}

bool Character::isAlive(){
    return hp > 0;
}

void Character::displayStats(){
    cout<<"============================="<<endl;
    cout<<"-------Character Info--------"<<endl;
    cout<<"---Name: "<<name<<endl;
    cout<<"---Health Points (hp): "<<hp<<endl;
    cout<<"---Max Health Points: "<<maxHp<<endl;
    cout<<"---Mana: "<<mana<<endl;
    cout<<"---Level: "<<level<<endl;
    cout<<"---Attack: "<<atkStat<<endl;
    cout<<"---Defence: "<<defence<<endl;
    cout<<"---Experience Points (xp): "<<xp<<endl;
    cout<<"============================="<<endl;
}

void Character:: takeDamage(int dmg){
    hp -= dmg;
    if(hp<0){
        hp = 0;
    }
}

int Character::gethp(){ return hp;}
int Character::getmaxHp(){ return maxHp;}
int Character::getmana() {return mana;}
int Character::getmaxMana(){return maxMana;}
int Character::getatkStat(){return atkStat;}
int Character::getdefence(){return defence;}
int Character::getlevel(){return level;}
int Character::getxp(){return xp;}

Character::~Character(){}