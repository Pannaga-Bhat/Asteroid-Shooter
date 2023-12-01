#include "Player.h"

player::player()
{
    name = "player";
    dir = 1;
}

void player::update()
{
    if (thrust)
    {
        dx += cos(angle * DEGTORAD) * 0.2;
        dy += sin(angle * DEGTORAD) * 0.2;
    }
    else
    {
        dx *= 0.95;
        dy *= 0.95;
    }

    int maxSpeed = 15;
    float speed = sqrt(dx * dx + dy * dy);
    if (speed > maxSpeed)
    {
        dx *= maxSpeed / speed;
        dy *= maxSpeed / speed;
    }

    x += dx * dir;
    y += dy * dir;

    if (x > W)
        x = 0;
    if (x < 0)
        x = W;
    if (y > H)
        y = 0;
    if (y < 0)
        y = H;
}

void player::setThrust(bool thrust)
{
    this->thrust = thrust;
}

bool player::getThrust()
{
    return thrust;
}

void player::setDir(int dir)
{
    this->dir = dir;
}

int player::getDir()
{
    return dir;
}

// player::~player()
// {
// }