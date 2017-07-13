#ifndef CHAOS_SPRITECOMPONENT_H
#define CHAOS_SPRITECOMPONENT_H

#include <Core/Component.h>
#include <Core/Sprite.h>

class SpriteComponent:
    public Component
{
    double
        deltaTime,
        frameRate;

    int frameCount,
        currentFrame;

public:
    Sprite sprite;
    SpriteComponent():
        deltaTime(0),
        currentFrame(0),
        frameCount(1),
        frameRate(1. / 60.)
    { label = COMPONENT_SPRITE; }


    /**
     *
     */
    void startAnimation()
    {
        deltaTime = 0;
    }


    /**
     *
     * @param timeElapsed
     */
    void updateAnimation(double timeElapsed)
    {
        deltaTime += timeElapsed;
        currentFrame = (int)(deltaTime / frameRate) % (frameCount);
    }


    /**
     *
     * @return
     */
    Sprite getSprite()
    {
        Sprite s = sprite;
        s.setFrame(currentFrame);
        return s;
    }


    /**
     *
     * @param n
     */
    void setFrameCount(int n)
    {
        frameCount = n;
    }


    /**
     *
     * @param fr
     */
    void setFrameRate(double fr)
    {
        frameRate = fr;
    }
};


#endif //CHAOS_SPRITECOMPONENT_H
