#include "CombatEngine.h"


void CombatEngine::playerTurn(Character& player,Enemy& enemy){
    player.attack(enemy);
}


void CombatEngine::enemyTurn(Character& player, Enemy& enemy)
{
    int chance = rand() % 100;

    if (chance < 30)      // 30% special attack chance
    {
        enemy.useSpecialMove(player);
    }
    else
    {
        enemy.attack(player);
    }
}

void CombatEngine::startBattle(Character& player,Enemy& enemy){
    cout<<"---===BATTLE STARTS===---"<<endl;
    cout<<"---Current Player: "<<player.getname()<<endl;
    cout<<"---Current Enemy: "<<enemy.getname()<<endl;
    while(player.isAlive() && enemy.isAlive()){
        cout<<player.getname()<<"'s turn "<<endl;
        playerTurn(player,enemy);
        if(!enemy.isAlive()){
            cout<<"---===CONGRATULATIONS!!! "<<player.getname()<<" WON THE MATCH!!!===---"<<endl;
            player.displayStats();
            break;
        }
        enemyTurn(player,enemy);
        if(!player.isAlive()){
            cout<<"---===UNFORTUNATELY!!! "<<enemy.getname()<<" WON THE MATCH!!!===---"<<endl;
            enemy.displayStats();
            break;
        }
    }
}