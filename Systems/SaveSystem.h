#pragma once

#include <fstream>
#include <string>
#include "SaveSystem.h"
#include "../Character/Warrior.h"
#include "../Character/Mage.h"
#include "../Character/Archer.h"
#include <fstream>
#include <iostream>
using namespace std;


class SaveSystem
{
public:
    static void saveGame(Character& character, string filename);
    static Character* loadGame(string filename);
};