#include "Dragon.h"

Dragon::Dragon(string n,int xr,string ld):Enemy(n,xr,ld){
    name = n;
    maxHp = hp = 200;
    atkStat = 20;
    defence = 15;
    xpReward = 100;
    usedFire = false;
}

bool Dragon::isEnraged(){
    return hp < (maxHp * 0.4);
}

void Dragon::attack(Character& target){
    cout<< name + " attacks " + target.getname()<<endl;
    int damage = atkStat;
    if(isEnraged()){
        cout<<"Dragon is Enraged!!"<<endl;
        damage = atkStat * 1.3;
        target.takeDamage(damage);
    }
    else{
        target.takeDamage(damage);
    }
    cout<<target.getname() +" loses "<<damage<<" health points"<<endl;
}

void Dragon::displayStats(){
    Character::displayStats();
    cout<<"-------Dragon Info--------"<<endl;
    if(isEnraged()){
        cout<<"---Status: ENRAGED!"<<endl;
    }
    else{
        cout<<"---Status: CALMED!"<<endl;
    }
    cout<<"============================="<<endl;
}

void Dragon::fireBreath(Character& target){
   
    if(usedFire){
        cout<<"Cannot Use Fire Breath Again!!"<<endl;
        return;
    }
    else{
        cout<<"Dragon "<<name<<" uses Fire Breath on "<<target.getname()<<endl;
        int damage = target.gethp() * 0.5;
        target.takeDamage(damage);
        cout<<target.getname() +" loses "<<damage<<" health points"<<endl;
        usedFire = true;
    }

}

