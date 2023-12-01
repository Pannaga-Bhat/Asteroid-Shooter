#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"

class player : public Entity
{
private:
    bool thrust;
    int dir;

public:
    player();
    void update();
    // Generate definitions for getters and setters
    bool getThrust();
    void setThrust(bool thrust);
    int getDir();
    void setDir(int dir);
};

#endif