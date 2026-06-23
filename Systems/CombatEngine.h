#ifndef COMBATENGINE_H
#define COMBATENGINE_H
#include "../Character/Character.h"
#include "../Enemy/Enemy.h"

class CombatEngine{
    public:
        static void startBattle(Character& player,Enemy& enemy);
        static void playerTurn(Character& player, Enemy& enemy);
        static void enemyTurn(Character& player, Enemy& enemy);
};









#endif