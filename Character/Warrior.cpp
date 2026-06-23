
#include "Warrior.h"
Warrior::Warrior(string na):Character(na){
    rage = 0;
}

void Warrior::displayStats(){
    Character::displayStats();
    cout<<"-------Warrior Info--------"<<endl;
    cout<<"---Rage: "<<rage<<endl;
    cout<<"============================="<<endl;
}

void Warrior::takeDamage(int dmg){
    Character::takeDamage(dmg);
    rage += dmg/2;
}

void Warrior::attack(Character& target){
   int damage = atkStat + (rage/10);
   cout<< name + " attacks " + target.getname()<<endl;
   cout<<"Attack Power: "<<atkStat<<endl;
   cout<<"Rage: "<<rage<<endl;
   target.takeDamage(damage);
   cout<<target.getname() +" loses "<<damage<<" health points"<<endl;
 
}

void Warrior::shieldBash(Character& target){
    int damage = atkStat * 2;
    if(rage>=10){
        rage -= 10;
    }
    else{
        cout<<"----Cannot Use Sheild Bash Attack----"<<endl;
        return;
    }
    cout<<"Warrior "<<name<<" uses Sheild Bash on "<<target.getname()<<endl;
    target.takeDamage(damage);
    cout<<target.getname() +" loses "<<damage<<" health points"<<endl;
}

