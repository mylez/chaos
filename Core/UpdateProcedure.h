#ifndef CHAOS_UPDATEPROCEDURE_H
#define CHAOS_UPDATEPROCEDURE_H

class Game;
class Entity;

class UpdateProcedure
{
public:
    virtual void update(Game *game, Entity *entity, double timeElapsed) = 0;
};


#endif //CHAOS_UPDATEPROCEDURE_H
