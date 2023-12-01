#include "Bullet.h"

// Constructor for the bullet class
bullet::bullet()
{
    name = "bullet";
}

// Update function to update the bullet's position
void bullet::update()
{
    // Calculate the change in x and y coordinates based on the angle
    dx = cos(angle * DEGTORAD) * 6;
    dy = sin(angle * DEGTORAD) * 6;

    // Update the bullet's position
    x += dx;
    y += dy;

    // Check if the bullet is out of bounds and set its life to 0 if it is
    if (x > W || x < 0 || y > H || y < 0)
        life = 0;
}