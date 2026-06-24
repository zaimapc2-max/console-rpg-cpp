#include "Archer.h"
#include <cstdlib>

Archer::Archer(string na):Character(na){
    critChance = 30;
}

void Archer::displayStats(){
    Character::displayStats();
    cout<<"-------Archer Info--------"<<endl;
    cout<<"---Chances of Critical (double) Attack: "<< critChance <<endl;
    cout<<"============================="<<endl;
}

void Archer::useSpecialMove(Character& target){
    arrowRain(target);
}


void Archer::attack(Character& target){
   cout<< name + " attacks " + target.getname()<<endl;
   int roll = rand() % 100;
   int dmg;
   if(roll<critChance){
        dmg = atkStat * 2;

   }
   else{
    dmg = atkStat;
   }
   target.takeDamage(dmg);
   cout<<target.getname() +" loses "<<dmg<<" health points"<<endl;

}

void Archer::arrowRain(Character& target){
    cout<<"Archer "<<name<<" used ArrowRain on "<<target.getname()<<endl;
    int t = 0;
    for(int i=0;i<3;i++){
        int dmg;
        int roll = rand() % 100;
            if(roll<critChance){
            dmg = atkStat * 2;
            }
            else{
                dmg = atkStat;
            }
        t +=dmg;
    }
    target.takeDamage(t);
     cout<<target.getname() +" loses "<<t<<" health points"<<endl;

}