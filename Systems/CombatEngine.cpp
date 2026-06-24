#include "CombatEngine.h"
#include <thread>
#include <chrono>

void CombatEngine::playerTurn(Character& player,Enemy& enemy,Inventory& inventory)
{
    cout << "\n=== Your Turn ===" << endl;
    cout << "1. Attack" << endl;
    cout << "2. Special Move" << endl;
    cout << "3. Use Item" << endl;
    cout << "Choice: ";

    int choice;
    cin >> choice;

    if (choice == 1)
    {
        player.attack(enemy);
    }
    else if (choice == 2)
    {
        player.useSpecialMove(enemy);
    }
    else if (choice == 3)
    {
        inventory.displayInventory();

        int itemChoice;

        cout << "Enter item index: ";
        cin >> itemChoice;

        inventory.useItem(itemChoice, player);
    }
    else
    {
        cout << "Invalid choice! Turn skipped." << endl;
    }
}

void CombatEngine::enemyTurn(Character& player,Enemy& enemy)
{
    int chance = rand() % 100;

    if (chance < 30)
    {
        enemy.useSpecialMove(player);
    }
    else
    {
        enemy.attack(player);
    }
}

void CombatEngine::startBattle(Character& player,Enemy& enemy,Inventory& inventory)
{
    cout << "---===BATTLE STARTS===---" << endl;
    cout << "---Current Player: "
         << player.getname() << endl;

    cout << "---Current Enemy: "
         << enemy.getname() << endl;

    while (player.isAlive() && enemy.isAlive())
    {
        cout << player.getname()
             << "'s turn" << endl;

        this_thread::sleep_for(
            chrono::milliseconds(800)
        );

        playerTurn(player,
                   enemy,
                   inventory);

        if (!enemy.isAlive())
        {
            cout << "---===CONGRATULATIONS!!! "
                 << player.getname()
                 << " WON THE MATCH!!!===---"
                 << endl << endl;

            cout << "*★*★*★*★*★*" << endl;
            cout << " VICTORY! " << endl;
            cout << "*★*★*★*★*★*" << endl;

            player.displayStats();
            break;
        }

        enemyTurn(player, enemy);

        if (!player.isAlive())
        {
            cout << "---===UNFORTUNATELY!!! "
                 << enemy.getname()
                 << " WON THE MATCH!!!===---"
                 << endl;

            enemy.displayStats();
            break;
        }
    }
}