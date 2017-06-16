#ifndef CHAOS_SCRIPT_H
#define CHAOS_SCRIPT_H

class Game;
class Entity;

class Script
{
private:
    static unsigned int nextId_;

public:
    Script()
    {
        id = ++nextId_;
    }

    unsigned int id;

    virtual void update(Game *game, Entity *entity, double timeElapsed) = 0;
};


#endif //CHAOS_SCRIPT_H
