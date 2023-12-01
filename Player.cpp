#include "Player.h"

// Constructor for the player class
player::player()
{
    name = "player";
    dir = 1;
}

// Update function to update the player's position and speed
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

// Setter function to set the thrust state of the player
void player::setThrust(bool thrust)
{
    this->thrust = thrust;
}

// Getter function to get the thrust state of the player
bool player::getThrust()
{
    return thrust;
}

// Setter function to set the direction of the player
void player::setDir(int dir)
{
    this->dir = dir;
}

// Getter function to get the direction of the player
int player::getDir()
{
    return dir;
}
