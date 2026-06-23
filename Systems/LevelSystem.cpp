#include "LevelSystem.h"

void LevelSystem::gainXp(Character& character,int amount){
    character.addXp(amount);
    cout<<amount<<" XP was gained!!"<<endl;
    if(character.getxp() >= character.getlevel() * 100){
        levelUp(character);
    }
}

void LevelSystem::levelUp(Character& character){
    character.levelUpStats();
    cout<<"---===LEVEL UP ↑↑↑---==="<<endl;
    cout<<"---CURRENT LEVEL: "<<character.getlevel()<<endl;
}