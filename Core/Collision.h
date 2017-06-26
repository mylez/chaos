#ifndef CHAOS_COLLISION_H
#define CHAOS_COLLISION_H

class Entity;

class Collision
{
public:
    Entity
        *entityA,
        *entityB;

    Collision(Entity *entityA, Entity *entityB):
        entityA(entityA),
        entityB(entityB)
    {}
};


#endif //CHAOS_COLLISION_H
