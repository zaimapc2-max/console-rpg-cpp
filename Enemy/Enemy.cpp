#include "Enemy.h"

Enemy::Enemy(string na,int xr,string ld):Character(na),xpReward(xr),lootDrop(ld){
    mana = maxMana = 0;
}

void Enemy::useSpecialMove(Character& target){
   cout<<"No Special Moves!!"<<endl;
}

string Enemy::getlootDrop() {return lootDrop;}
int Enemy::getxpReward() {return xpReward;}

Enemy::~Enemy(){}

