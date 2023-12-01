#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"

class player : public Entity
{
public:

    bool thrust;
    int dir;
    player();
    void update();
};

#endif