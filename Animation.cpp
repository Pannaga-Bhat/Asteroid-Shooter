#include "Animation.h"

Animation::Animation() {}

Animation::Animation(Texture &t, int x, int y, int w, int h, int count, float Speed)
{
    Frame = 0;
    speed = Speed;

    for (int i = 0; i < count; i++)
        frames.push_back(IntRect(x + i * w, y, w, h));

    sprite.setTexture(t);
    sprite.setOrigin(w / 2, h / 2);
    sprite.setTextureRect(frames[0]);
}

void Animation::update()
{
    Frame += speed;
    int n = frames.size();
    if (Frame >= n)
        Frame -= n;
    if (n > 0)
        sprite.setTextureRect(frames[int(Frame)]);
}

bool Animation::isEnd()
{
    return Frame + speed >= frames.size();
}

void Animation::setSprite(Sprite sprite)
{
    this->sprite = sprite;
}

Sprite Animation::getSprite()
{
    return sprite;
}

void Animation::setSpeed(float speed)
{
    this->speed = speed;
}

float Animation::getSpeed()
{
    return speed;
}

void Animation::setFrame(float frame)
{
    Frame = frame;
}

float Animation::getFrame()
{
    return Frame;
}

void Animation::setFrames(std::vector<IntRect> frames)
{
    this->frames = frames;
}

std::vector<IntRect> Animation::getFrames()
{
    return frames;
}
