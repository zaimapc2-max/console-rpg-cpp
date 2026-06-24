#include "SaveSystem.h"


void SaveSystem::saveGame(Character& character, string filename)
{
    ofstream outFile(filename);

    if (!outFile)
    {
        cout << "Error opening file!" << endl;
        return;
    }

    // Save character type
    if (dynamic_cast<Warrior*>(&character))
    {
        outFile << "Warrior" << endl;
    }
    else if (dynamic_cast<Mage*>(&character))
    {
        outFile << "Mage" << endl;
    }
    else if (dynamic_cast<Archer*>(&character))
    {
        outFile << "Archer" << endl;
    }

    // Save stats
    outFile << character.getname() << endl;
    outFile << character.gethp() << endl;
    outFile << character.getmaxHp() << endl;
    outFile << character.getmana() << endl;
    outFile << character.getmaxMana() << endl;
    outFile << character.getatkStat() << endl;
    outFile << character.getdefence() << endl;
    outFile << character.getlevel() << endl;
    outFile << character.getxp() << endl;

    outFile.close();

    cout << "Game saved successfully!" << endl;
}

Character* SaveSystem::loadGame(string filename)
{
    ifstream inFile(filename);

    if (!inFile)
    {
        cout << "Error opening save file!" << endl;
        return nullptr;
    }

    string type;
    string name;

    int hp;
    int maxHp;
    int mana;
    int maxMana;
    int attack;
    int defence;
    int level;
    int xp;

    getline(inFile, type);
    getline(inFile, name);

    inFile >> hp;
    inFile >> maxHp;
    inFile >> mana;
    inFile >> maxMana;
    inFile >> attack;
    inFile >> defence;
    inFile >> level;
    inFile >> xp;

    Character* player = nullptr;

    if (type == "Warrior")
    {
        player = new Warrior(name);
    }
    else if (type == "Mage")
    {
        player = new Mage(name);
    }
    else if (type == "Archer")
    {
        player = new Archer(name);
    }
    else
    {
        cout << "Invalid character type in save file!" << endl;
        return nullptr;
    }

    // Restore saved stats
    player->setHp(hp);
    player->setMaxHp(maxHp);
    player->setMana(mana);
    player->setMaxMana(maxMana);
    player->setAttack(attack);
    player->setDefence(defence);
    player->setLevel(level);
    player->setXp(xp);

    inFile.close();

    cout << "Game loaded successfully!" << endl;

    return player;
}