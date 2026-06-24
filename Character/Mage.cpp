#include "Mage.h"

Mage::Mage(string na):Character(na){
    hp = maxHp= 50;
    mana = maxMana = 100;
    spellPower = 20;
}

void Mage::displayStats(){
    Character::displayStats();
    cout<<"-------Mage Info--------"<<endl;
    cout<<"---Spell Power: "<<spellPower<<endl;
    cout<<"============================="<<endl;
}

void Mage::useSpecialMove(Character& target) {
    int choice;

    while (true) {
        cout << "---Press 1 to activate FireBall---" << endl;
        cout << "---Press 2 to activate FreezeBall---" << endl;
        cin >> choice;

        if (choice == 1) {
            fireball(target);
            break;
        }
        else if (choice == 2) {
            freezeball(target);
            break;
        }
        else {
            cout << "Invalid Choice! Please enter 1 or 2." << endl;
        }
    }
}

void Mage::fireball(Character& target){
    if(mana>=20){
        mana -=20;
    }
    else{
        cout<<"---Cannot Use Fireball Spell---"<<endl;
        return;
    }
    int damage = spellPower*2;
    cout<<"Mage "<<name<<" uses FireBall on "<<target.getname()<<endl;
    target.takeDamage(damage);
    cout << target.getname() << " loses " << damage << " health points" << endl;
}


void Mage::freezeball(Character& target){
    if(mana>=10){
        mana -= 10;
    }
    else{
        cout<<"---Cannot Use FreezeBall Spell---"<<endl;
        return;
    }
    int damage = spellPower+5;
    cout<<"Mage "<<name<<" uses FreezeBall on "<<target.getname()<<endl;
    target.takeDamage(damage);
    cout << target.getname() << " loses " << damage << " health points" << endl;
}

void Mage::attack(Character& target){
   cout<< name + " attacks " + target.getname()<<endl;
   cout<<"Attack Power: "<<atkStat<<endl;
   target.takeDamage(atkStat);
   cout<<target.getname() +" loses "<<atkStat<<" health points"<<endl;

}
