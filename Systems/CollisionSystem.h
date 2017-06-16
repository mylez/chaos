#ifndef CHAOS_COLLISIONSYSTEM_H
#define CHAOS_COLLISIONSYSTEM_H

#include <Core/System.h>
#include <Core/Component.h>
#include <Core/Vec2d.h>
#include <Core/Graphics.h>
#include <map>


class Entity;
class BoxCollisionComponent;

class CollisionSystem:
    public System
{
private:

    std::map<std::pair<unsigned int, unsigned int>, bool>
        collisionsThisCycle,
        collisionsInProgress;

    bool isIntersecting(Vec2d, Vec2d, Vec2d, Vec2d);

    void trackCollisionThisCycle(Entity *entityA, BoxCollisionComponent *cmpA, Entity *entityB, BoxCollisionComponent *cmpB);

    void trackCollisionInProgress(Entity *entityA, BoxCollisionComponent *cmpA, Entity *entityB, BoxCollisionComponent *cmpB);

    std::pair<unsigned int, unsigned int> makeOrderedPair(unsigned int idA, unsigned int idB);

public:
    Graphics *graphics;

    CollisionSystem()
    { signature = COMPONENT_TRANSFORM | COMPONENT_COLLISION; }

    void update(double timeElapsed, std::vector<Entity *> entities);

    void init(Game *game);
};


#endif //CHAOS_COLLISIONSYSTEM_H
