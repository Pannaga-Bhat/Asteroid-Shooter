#include "Entity.h"

extern int W = 1200; // Width of the window
extern int H = 800; // Height of the window

float extern DEGTORAD = 0.017453f; // Conversion factor from degrees to radians

Entity::Entity()
{
    life = 1; // Initialize life to 1
}

void Entity::settings(Animation &a, int X, int Y, float Angle, int radius)
{
    anim = a; // Set the animation
    x = X; // Set the x-coordinate
    y = Y; // Set the y-coordinate
    angle = Angle; // Set the angle
    R = radius; // Set the radius
}

void Entity::draw(RenderWindow &app)
{
    Sprite tmpAnim = anim.getSprite(); // Get the sprite from the animation
    tmpAnim.setPosition(x, y); // Set the position of the sprite
    anim.setSprite(tmpAnim); // Set the sprite in the animation
    tmpAnim.setRotation(angle + 90); // Set the rotation of the sprite
    anim.setSprite(tmpAnim); // Set the sprite in the animation
    app.draw(anim.getSprite()); // Draw the sprite on the window

    CircleShape circle(R); // Create a circle shape with radius R
    circle.setFillColor(Color(255, 0, 0, 170)); // Set the fill color of the circle
    circle.setPosition(x, y); // Set the position of the circle
    circle.setOrigin(R, R); // Set the origin of the circle
}

float Entity::getX()
{
    return x; // Return the x-coordinate
}

void Entity::setX(float x)
{
    this->x = x; // Set the x-coordinate
}

float Entity::getY()
{
    return y; // Return the y-coordinate
}

void Entity::setY(float y)
{
    this->y = y; // Set the y-coordinate
}

float Entity::getDx()
{
    return dx; // Return the x-velocity
}

void Entity::setDx(float dx)
{
    this->dx = dx; // Set the x-velocity
}

float Entity::getDy()
{
    return dy; // Return the y-velocity
}

void Entity::setDy(float dy)
{
    this->dy = dy; // Set the y-velocity
}

float Entity::getR()
{
    return R; // Return the radius
}

void Entity::setR(float r)
{
    R = r; // Set the radius
}

float Entity::getAngle()
{
    return angle; // Return the angle
}

void Entity::setAngle(float angle)
{
    this->angle = angle; // Set the angle
}

bool Entity::getLife()
{
    return life; // Return the life status
}

void Entity::setLife(bool life)
{
    this->life = life;
}

std::string Entity::getName()
{
    return name;
}

void Entity::setName(std::string name)
{
    this->name = name;
}

Animation Entity::getAnim()
{
    return anim;
}

void Entity::setAnim(Animation anim)
{
    this->anim = anim;
}
