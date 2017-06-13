#ifndef CHAOS_GAMESTATE_H
#define CHAOS_GAMESTATE_H

#include <Core/Entity.h>
#include <Core/System.h>

class GameState
{
private:
    std::vector<Entity *> entities_;
    std::vector<System *> systems_;

    std::vector<Entity *> filterBySignature(unsigned long label);

public:
    void update(double timeElapsed);
    void addSystem(System *system);
    void addEntity(Entity *entity);
};


#endif //CHAOS_GAMESTATE_H
