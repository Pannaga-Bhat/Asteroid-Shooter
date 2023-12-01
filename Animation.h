#ifndef ANIMATION_H
#define ANIMATION_H
#include <SFML/Graphics.hpp>
using namespace sf;

class Animation
{
private:
    float Frame, speed;
    Sprite sprite;
    std::vector<IntRect> frames;
public:

    Animation();
    Animation(Texture &t, int x, int y, int w, int h, int count, float Speed);
    void update();
    bool isEnd();
    // Generate definitions for getters and setters
    Sprite getSprite();
    void setSprite(Sprite sprite);
    float getFrame();
    void setFrame(float frame);
    float getSpeed();
    void setSpeed(float speed);
    std::vector<IntRect> getFrames();
    void setFrames(std::vector<IntRect> frames);
};

#endif