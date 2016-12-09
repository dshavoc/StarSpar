#ifndef SOLAR_H
#define SOLAR_H

#include "Entity.h"

class Solar : public Entity
{
    public:
        Solar(float x, float y, float r, float gravity);
        virtual ~Solar();

        //Administrative
        void draw(int);
        void update(int, std::vector<Solar*> solars);

        float getGravity() {return gravity;}

    protected:
        float gravity;  // G*M

    private:
};

#endif // SOLAR_H
