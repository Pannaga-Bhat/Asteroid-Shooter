#include <SFML/Graphics.hpp>
#include <string>
#include "Animation.h"
#include <math.h>

#ifndef ENTITY_H
#define ENTITY_H

extern int W;
extern int H;
extern float DEGTORAD;

using namespace sf;

class Entity{
protected:
    float x, y, dx, dy, R, angle;
    bool life;
    std::string name;
    Animation anim;

public:
    Entity();
    void settings(Animation &a, int X, int Y, float Angle=0, int radius=1);
    virtual void update(){};
    void draw(RenderWindow &app);
    virtual ~Entity(){};

    float getX();
    void setX(float x);
    float getY();
    void setY(float y);
    float getDx();
    void setDx(float dx);
    float getDy();
    void setDy(float dy);
    float getR();
    void setR(float r);
    float getAngle();
    void setAngle(float angle);
    bool getLife();
    void setLife(bool life);
    std::string getName();
    void setName(std::string name);
    Animation getAnim();
    void setAnim(Animation anim);
};

#endif