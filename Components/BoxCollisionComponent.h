#ifndef CHAOS_BOXCOLLISIONCOMPONENT_H
#define CHAOS_BOXCOLLISIONCOMPONENT_H

#include <Core/Component.h>
#include <Core/Collision.h>
#include <Core/Vec2d.h>

class CollisionComponent:
    public Component
{
public:
    bool
        debugDraw = false;

    std::vector<unsigned short>
        collisionLayers,
        targetLayers;

    CollisionComponent()
    { label = COMPONENT_COLLISION; }

};

class BoxCollisionComponent:
    public CollisionComponent
{
    Vec2d
        size = Vec2d(1, 1),
        center = Vec2d(0, 0);

public:
    Vec2d getSize()
    {
        return size;
    }

    void setSize(Vec2d size)
    {
        this->size = size;
    }

    Vec2d getCenter()
    {
        return center;
    }

    void setCenter(Vec2d center)
    {
        this->center = center;
    }
};


#endif //CHAOS_BOXCOLLISIONCOMPONENT_H
