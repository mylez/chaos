#ifndef CHAOS_COLLISIONSYSTEM_H
#define CHAOS_COLLISIONSYSTEM_H

#include <Core/System.h>
#include <Core/Component.h>
#include <Core/Vec2d.h>
#include <Core/Graphics.h>
#include <map>
#include <unordered_map>

class Entity;

class BoxCollisionComponent;


/**
 * using std::unordered_map is slightly faster than std::map
 */
namespace std
{
    template<>
    struct hash<std::pair<unsigned int, unsigned int>>
    {
        size_t operator()(const std::pair<unsigned int, unsigned int> &pt) const
        {
            return std::hash<unsigned int>()(pt.first + 0x10000 * pt.second);
        }
    };
}

class CollisionSystem:
    public System
{
private:
    std::unordered_map<std::pair<unsigned int, unsigned int>, bool>
        collisionsThisCycle,
        collisionsInProgress;

    bool isIntersecting(Vec2d posA, Vec2d sizeA, Vec2d posB, Vec2d sizeB);

    void trackCollisionThisCycle(Entity *entityA, BoxCollisionComponent *cmpA, Entity *entityB,
                                 BoxCollisionComponent *cmpB);

    void trackCollisionInProgress(Entity *entityA, BoxCollisionComponent *cmpA, Entity *entityB,
                                  BoxCollisionComponent *cmpB);

    std::pair<unsigned int, unsigned int> makeOrderedPair(unsigned int idA, unsigned int idB);

public:
    Graphics *graphics;

    CollisionSystem()
    { signature = COMPONENT_TRANSFORM | COMPONENT_COLLISION; }

    void update(double timeElapsed, std::vector<Entity *> entities);

    void init();
};


#endif //CHAOS_COLLISIONSYSTEM_H
