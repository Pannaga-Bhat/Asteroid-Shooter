#include "Entity.h"

extern int W = 1200;
extern int H = 800;

float extern DEGTORAD = 0.017453f;

Entity::Entity()
{
    life = 1;
}

void Entity::settings(Animation &a, int X, int Y, float Angle, int radius)
{
    anim = a;
    x = X;
    y = Y;
    angle = Angle;
    R = radius;
}

void Entity::draw(RenderWindow &app)
{
    Sprite tmpAnim = anim.getSprite();
    tmpAnim.setPosition(x, y);
    anim.setSprite(tmpAnim);
    tmpAnim.setRotation(angle + 90);
    anim.setSprite(tmpAnim);
    app.draw(anim.getSprite());
    // delete &tmpAnim;

    CircleShape circle(R);
    circle.setFillColor(Color(255, 0, 0, 170));
    circle.setPosition(x, y);
    circle.setOrigin(R, R);
    //app.draw(circle);
}

float Entity::getX()
{
    return x;
}

void Entity::setX(float x)
{
    this->x = x;
}

float Entity::getY()
{
    return y;
}

void Entity::setY(float y)
{
    this->y = y;
}

float Entity::getDx()
{
    return dx;
}

void Entity::setDx(float dx)
{
    this->dx = dx;
}

float Entity::getDy()
{
    return dy;
}

void Entity::setDy(float dy)
{
    this->dy = dy;
}

float Entity::getR()
{
    return R;
}

void Entity::setR(float r)
{
    R = r;
}

float Entity::getAngle()
{
    return angle;
}

void Entity::setAngle(float angle)
{
    this->angle = angle;
}

bool Entity::getLife()
{
    return life;
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
