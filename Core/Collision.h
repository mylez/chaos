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

class CollisionEnterProcedure
{
public:
    virtual void onCollisionEnter(Collision collision) = 0;
};


class CollisionExitProcedure
{
public:
    virtual void onCollisionExit(Collision collision) = 0;
};


#endif //CHAOS_COLLISION_H
