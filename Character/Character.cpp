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

void Character::heal(int amount){
    hp = hp + amount;
    if(hp>maxHp){
        hp = maxHp;
    }
}

void Character::useSpecialMove(Character& target){
    cout<<"No Special Move Available!!"<<endl;
}



int Character::gethp(){ return hp;}
int Character::getmaxHp(){ return maxHp;}
int Character::getmana() {return mana;}
int Character::getmaxMana(){return maxMana;}
int Character::getatkStat(){return atkStat;}
int Character::getdefence(){return defence;}
int Character::getlevel(){return level;}
int Character::getxp(){return xp;}
string Character::getname(){return name;}

Character::~Character(){}

void Character::addXp(int amount)
{
    xp += amount;
}

void Character::levelUpStats()
{
    level++;

    atkStat += 5;
    defence += 3;
    maxHp += 20;

    hp = maxHp; // fully heal on level up
}

void Character::setHp(int hp)
{
    this->hp = hp;
}

void Character::setMaxMana(int maxMana)
{
    this->maxMana = maxMana;
}


void Character::setMaxHp(int maxHp)
{
    this->maxHp = maxHp;
}

void Character::setMana(int mana)
{
    this->mana = mana;
}

void Character::setAttack(int attack)
{
    this->atkStat = attack;
}

void Character::setDefence(int defence)
{
    this->defence = defence;
}

void Character::setLevel(int level)
{
    this->level = level;
}

void Character::setXp(int xp)
{
    this->xp = xp;
}

void Character::boostAttack(int amount){
    atkStat = atkStat + amount;
}



