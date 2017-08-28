#ifndef MODULE_H
#define MODULE_H

//#include "Ship.h"
#include <string>

/*
Module represents anything that can be mounted on a ship, so it must contain all
information relevant to that relationship.
*/

class Module
{
    public:
        Module();
        //Module(Ship* parent);
        //bool isOnline() {return health >= 1.f;};

    protected:
        //Ship* ship;             //The ship that this module is mounted on (maybe should have hooks more specific than ship, if necessary. A weapon shouldn't necessarily need to know what it's mounted in
        //float health;
        //float powerSupplied;
        //int powerRequired;
        //float weight;
        //int sizeClass;
        std::string name;

    private:
};

#endif // MODULE_H
