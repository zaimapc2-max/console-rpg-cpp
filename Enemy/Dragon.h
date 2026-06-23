#ifndef DRAGON_H
#define DRAGON_H
#include "Enemy.h"
#include <string>

class Dragon : public Enemy{
    public:
        Dragon(string n);
        void attack(Character& target) override;
        void fireBreath(Character& target);
        bool isEnraged();
        void displayStats() override;
};

#endif