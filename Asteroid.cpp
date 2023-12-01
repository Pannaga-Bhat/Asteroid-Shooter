#include "Asteroid.h"

// Constructor for the asteroid class
asteroid::asteroid()
{
    dx = rand() % 8 - 4; // Set a random value for dx between -4 and 4
    dy = rand() % 8 - 4; // Set a random value for dy between -4 and 4
    name = "asteroid"; // Set the name of the asteroid
}

// Update the position of the asteroid
void asteroid::update()
{
    x += dx; // Update the x position by adding dx
    y += dy; // Update the y position by adding dy

    // Wrap around the screen if the asteroid goes out of bounds
    if (x > W)
        x = 0;
    if (x < 0)
        x = W;
    if (y > H)
        y = 0;
    if (y < 0)
        y = H;
}
