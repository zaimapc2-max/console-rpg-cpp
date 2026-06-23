#ifndef ITEM_H
#define ITEM_H
#include "../Character/Character.h"
#include "../Enemy/Enemy.h"
#include <iostream>
#include <string>
using namespace std;

class Item{
    protected:
        string name,type;
        int value;
    public:
        Item(string n,string t,int v);
        void use(Character& target);
        string gettype();
        string getname();
};


#endif

