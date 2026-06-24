#include <iostream>
#include <ctime>
#include <limits>

#include "Character/Warrior.h"
#include "Character/Mage.h"
#include "Character/Archer.h"

#include "Enemy/Goblin.h"
#include "Enemy/Skeleton.h"
#include "Enemy/Dragon.h"

#include "Systems/CombatEngine.h"
#include "Systems/LevelSystem.h"
#include "Systems/SaveSystem.h"

#include "Systems/Inventory.h"
#include "Systems/Item.h"

using namespace std;

// Reads an int safely. Returns false (and clears/flushes the stream)
// if the user typed something that isn't a number, instead of letting
// cin sit in a fail state and infinite-loop the caller.
bool readInt(int& out)
{
    cin >> out;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }

    return true;
}

int main()
{
    srand(time(0));

    Character* player = nullptr;

    while (player == nullptr)
    {
        int mainChoice;

        cout << "\n===== RPG GAME =====" << endl;
        cout << "1. New Game" << endl;
        cout << "2. Load Game" << endl;
        cout << "3. Game Guide" << endl;
        cout << "4. Exit" << endl;
        cout << "Choice: ";

        if (!readInt(mainChoice))
        {
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        if (mainChoice == 1)
        {
            int classChoice;
            string name;

            cout << "\nChoose Class:\n";
            cout << "1. Warrior\n";
            cout << "2. Mage\n";
            cout << "3. Archer\n";
            cout << "Choice: ";

            if (!readInt(classChoice))
            {
                cout << "Invalid input! Please enter a number.\n";
                continue;
            }

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
            }
        }
        else if (mainChoice == 2)
        {
            string filename;

            cout << "Enter save filename: ";
            cin >> filename;

            player = SaveSystem::loadGame(filename);

            if (player == nullptr)
            {
                cout << "Failed to load save.\n";
            }
        }
        else if (mainChoice == 3)
        {
            bool inGuide = true;

            while (inGuide)
            {
                int guideChoice;

                cout << "\n===== GAME GUIDE =====" << endl;
                cout << "1. View Warrior Info" << endl;
                cout << "2. View Mage Info" << endl;
                cout << "3. View Archer Info" << endl;
                cout << "4. View Goblin Info" << endl;
                cout << "5. View Skeleton Info" << endl;
                cout << "6. View Dragon Info" << endl;
                cout << "7. Back to Main Menu" << endl;
                cout << "Choice: ";

                if (!readInt(guideChoice))
                {
                    cout << "Invalid input! Please enter a number.\n";
                    continue;
                }

                switch (guideChoice)
                {
                case 1:
                    cout << "\n=== WARRIOR ===" << endl;
                    cout << "HP: 100 | Mana: 50 | Attack: 10 | Defence: 5" << endl;
                    cout << "Passive: Rage — builds up every time he takes damage, boosting his next normal attack" << endl;
                    cout << "Special Move: Shield Bash — deals double Attack damage, costs 10 Rage to use" << endl;
                    cout << "Playstyle: Tanky frontline fighter, gets stronger the longer he survives in battle" << endl;
                    break;

                case 2:
                    cout << "\n=== MAGE ===" << endl;
                    cout << "HP: 50 | Mana: 100 | Attack: 10 | Spell Power: 20" << endl;
                    cout << "Spell 1: Fireball — deals heavy damage, costs 20 Mana" << endl;
                    cout << "Spell 2: Freezeball — deals lighter damage, costs 10 Mana" << endl;
                    cout << "Normal Attack: Free (no Mana cost), used as fallback when Mana runs low" << endl;
                    cout << "Playstyle: Fragile but powerful, requires careful Mana management" << endl;
                    break;

                case 3:
                    cout << "\n=== ARCHER ===" << endl;
                    cout << "HP: 100 | Mana: 50 | Attack: 10 | Critical Chance: 30%" << endl;
                    cout << "Passive: Every normal attack has a 30% chance to deal double damage" << endl;
                    cout << "Special Move: Arrow Rain — fires 3 shots, each with its own independent crit chance" << endl;
                    cout << "Playstyle: High-risk, high-reward, rewards lucky crit rolls for burst damage" << endl;
                    break;

                case 4:
                    cout << "\n=== GOBLIN ===" << endl;
                    cout << "HP: 40 | Attack: 6 | Defence: 3" << endl;
                    cout << "XP Reward: 25" << endl;
                    cout << "No special abilities — relies purely on basic attacks" << endl;
                    cout << "Difficulty: Easy, ideal first encounter" << endl;
                    break;

                case 5:
                    cout << "\n=== SKELETON ===" << endl;
                    cout << "HP: 50 | Attack: 8 | Defence: 5" << endl;
                    cout << "XP Reward: 30" << endl;
                    cout << "Passive: Damage Reduction — reduces incoming damage by a flat amount (2) before applying it" << endl;
                    cout << "Difficulty: Moderate, tankier than the Goblin" << endl;
                    break;

                case 6:
                    cout << "\n=== DRAGON (BOSS) ===" << endl;
                    cout << "HP: 200 | Attack: 20 | Defence: 15" << endl;
                    cout << "XP Reward: 100" << endl;
                    cout << "Passive: Enrage — once HP drops below 40%, deals 30% bonus damage on attacks" << endl;
                    cout << "Special Move: Fire Breath — deals damage equal to half the target's current HP, usable only once per battle" << endl;
                    cout << "Difficulty: Boss-tier, the toughest fight in the game" << endl;
                    break;

                case 7:
                    inGuide = false;
                    break;

                default:
                    cout << "Invalid choice!" << endl;
                }
            }
        }
        else if (mainChoice == 4)
        {
            return 0;
        }
        else
        {
            cout << "Invalid choice!" << endl;
        }
    }

    // =========================
    // PLAYER INVENTORY
    // =========================
    Inventory playerInventory;

    playerInventory.addItem(
        new Item("Health Potion", "Potion", 20)
    );

    playerInventory.addItem(
        new Item("Health Potion", "Potion", 20)
    );

    playerInventory.addItem(
        new Item("Iron Sword", "Weapon", 5)
    );

    // =========================
    // GAME LOOP
    // =========================
    bool running = true;

    while (running && player->isAlive())
    {
        int choice;

        cout << "\n===== MENU =====\n";
        cout << "1. Fight Enemy\n";
        cout << "2. View Stats\n";
        cout << "3. Inventory\n";
        cout << "4. Save Game\n";
        cout << "5. Quit\n";
        cout << "Choice: ";

        if (!readInt(choice))
        {
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        switch (choice)
        {
        case 1:
        {
            Enemy* enemy = nullptr;

            // Dragon is a boss: it should be rare, not an equal 1-in-3 pull.
            // Roll 0-99: 45% Goblin, 45% Skeleton, 10% Dragon.
            int randomEnemy = rand() % 100;

            if (randomEnemy < 45)
            {
                enemy = new Goblin(
                    "Sneaky Goblin",
                    25,
                    "Goblin Ear"
                );
            }
            else if (randomEnemy < 90)
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

            CombatEngine::startBattle(*player, *enemy, playerInventory);

            if (!enemy->isAlive())
            {
                LevelSystem::gainXp(
                    *player,
                    enemy->getxpReward()
                );
            }

            delete enemy;
            break;
        }

        case 2:
        {
            player->displayStats();
            break;
        }

        case 3:
        {
            playerInventory.displayInventory();

            int itemChoice;

            cout << "Enter item index to use (-1 to cancel): ";

            if (!readInt(itemChoice))
            {
                cout << "Invalid input! Please enter a number.\n";
                break;
            }

            if (itemChoice != -1)
            {
                playerInventory.useItem(itemChoice, *player);
            }

            break;
        }

        case 4:
        {
            string filename;

            cout << "Enter filename: ";
            cin >> filename;

            SaveSystem::saveGame(*player, filename);
            break;
        }

        case 5:
        {
            running = false;
            break;
        }

        default:
            cout << "Invalid choice!\n";
        }
    }

    delete player;

    cout << "\nThanks for playing!\n";

    return 0;
}