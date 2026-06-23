#ifndef INVENTORY_H
#define INVENTORY_H
#include "Item.h"
#include <iostream>
#include <string>
using namespace std;

class Inventory {
protected:
    Item* items[10];
    int itemCount;

public:
    Inventory();
    void addItem(Item* newItem);
    void useItem(int index, Character& target);
    void displayInventory();
};


#endif
