#include "Inventory.h"

Inventory::Inventory(){
    itemCount=0;
}

void Inventory::addItem(Item* newItem) {
    if (itemCount < 10) {
        items[itemCount] = newItem;
        itemCount++;
    }
    else {
        cout << "Inventory is full!" << endl;
    }
}

void Inventory::useItem(int index, Character& target) {
    if (index >= 0 && index < itemCount) {
        items[index]->use(target);
    }
    else {
        cout << "Invalid item index!" << endl;
    }
}

void Inventory::displayInventory() {
    if (itemCount == 0) {
        cout << "Inventory is empty!" << endl;
        return;
    }

    for (int i = 0; i < itemCount; i++) {
        cout << i << ". " << items[i]->getname() << endl;
    }
}

