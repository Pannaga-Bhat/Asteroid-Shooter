#include "Animation.h"

// Default constructor
Animation::Animation() {}

// Parameterized constructor
Animation::Animation(Texture &t, int x, int y, int w, int h, int count, float Speed)
{
    Frame = 0;
    speed = Speed;

    // Generate frames based on the given parameters
    for (int i = 0; i < count; i++)
        frames.push_back(IntRect(x + i * w, y, w, h));

    sprite.setTexture(t);
    sprite.setOrigin(w / 2, h / 2);
    sprite.setTextureRect(frames[0]);
}

// Update the animation frame
void Animation::update()
{
    Frame += speed;
    int n = frames.size();
    if (Frame >= n)
        Frame -= n;
    if (n > 0)
        sprite.setTextureRect(frames[int(Frame)]);
}

// Check if the animation has reached the end
bool Animation::isEnd()
{
    return Frame + speed >= frames.size();
}

// Set the sprite of the animation
void Animation::setSprite(Sprite sprite)
{
    this->sprite = sprite;
}

// Get the sprite of the animation
Sprite Animation::getSprite()
{
    return sprite;
}

// Set the speed of the animation
void Animation::setSpeed(float speed)
{
    this->speed = speed;
}

// Get the speed of the animation
float Animation::getSpeed()
{
    return speed;
}

// Set the current frame of the animation
void Animation::setFrame(float frame)
{
    Frame = frame;
}

// Get the current frame of the animation
float Animation::getFrame()
{
    return Frame;
}

// Set the frames of the animation
void Animation::setFrames(std::vector<IntRect> frames)
{
    this->frames = frames;
}

// Get the frames of the animation
std::vector<IntRect> Animation::getFrames()
{
    return frames;
}
