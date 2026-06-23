#include "Item.h"

Item::Item(string n,string t,int v){
    name = n;
    type = t;
    value = v;
}

string Item::getname(){return name;}
string Item::gettype(){return type;}

void Item::use(Character& target){
    if(type == "Potion"){
        target.heal(value);
        cout<<target.getname()<<" healed!!"<<endl;
    }
    else if(type == "Weapon"){
        target.boostAttack(value);
        cout<<target.getname()<<" attack boosted!!"<<endl;
    }
}