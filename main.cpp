#include <iostream>
#include <ctime>

#include "Character/Warrior.h"
#include "Character/Mage.h"
#include "Character/Archer.h"

#include "Enemy/Goblin.h"
#include "Enemy/Skeleton.h"
#include "Enemy/Dragon.h"

#include "Systems/CombatEngine.h"
#include "Systems/LevelSystem.h"
#include "Systems/SaveSystem.h"

using namespace std;

int main()
{
    srand(time(0));

    Character* player = nullptr;

    int mainChoice;

    cout << "===== RPG GAME =====" << endl;
    cout << "1. New Game" << endl;
    cout << "2. Load Game" << endl;
    cout << "3. Exit" << endl;
    cout << "Choice: ";
    cin >> mainChoice;

    if (mainChoice == 1)
    {
        int classChoice;
        string name;

        cout << "\nChoose Class:\n";
        cout << "1. Warrior\n";
        cout << "2. Mage\n";
        cout << "3. Archer\n";
        cout << "Choice: ";
        cin >> classChoice;

        cout << "Enter character name: ";
        cin >> name;

        switch (classChoice)
        {
        case 1:
            player = new Warrior(name);
            break;

        case 2:
            player = new Mage(name);
            break;

        case 3:
            player = new Archer(name);
            break;

        default:
            cout << "Invalid class!\n";
            return 0;
        }
    }

    // LOAD GAME
    else if (mainChoice == 2)
    {
        string filename;

        cout << "Enter save filename: ";
        cin >> filename;

        player = SaveSystem::loadGame(filename);

        if (player == nullptr)
        {
            return 0;
        }
    }

    else
    {
        return 0;
    }

    // GAME LOOP
    bool running = true;

    while (running && player->isAlive())
    {
        int choice;

        cout << "\n===== MENU =====\n";
        cout << "1. Fight Enemy\n";
        cout << "2. View Stats\n";
        cout << "3. Save Game\n";
        cout << "4. Quit\n";
        cout << "Choice: ";
        cin >> choice;

                switch (choice)
                {
                case 1:
                {
                    Enemy* enemy = nullptr;

                    int randomEnemy = rand() % 3;

                if (randomEnemy == 0)
        {
            enemy = new Goblin(
                "Sneaky Goblin",
                25,
                "Goblin Ear"
            );
        }
        else if (randomEnemy == 1)
        {
            enemy = new Skeleton(
                "Ancient Skeleton",
                50,
                "Bone Fragment"
            );
        }
        else
        {
            enemy = new Dragon(
                "Fire Dragon",
                100,
                "Dragon Scale"
            );
        }

            CombatEngine::startBattle(*player, *enemy);

            if (!enemy->isAlive())
            {
                LevelSystem::gainXp(*player,enemy->getxpReward());
            }

            delete enemy;
            break;
        }

        case 2:
            player->displayStats();
            break;

        case 3:
        {
            string filename;

            cout << "Enter filename: ";
            cin >> filename;

            SaveSystem::saveGame(*player, filename);
            break;
        }

        case 4:
            running = false;
            break;

        default:
            cout << "Invalid choice!\n";
        }
    }

    delete player;

    cout << "\nThanks for playing!\n";

    return 0;
}