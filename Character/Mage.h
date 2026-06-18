#ifndef MAGE_H
#define MAGE_H
#include "Character.h"

class Mage : public Character{
    protected: 
        int spellPower;
    public:
        Mage();
        void attack(Character& targer) override;
        void displayStats() override;
        void fireball(Character& target);
        void freezeball(Character& target);
};


#endif
