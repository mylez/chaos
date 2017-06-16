#ifndef CHAOS_GAMESTATE_H
#define CHAOS_GAMESTATE_H

#include <map>
#include <vector>
#include <Systems/RenderingSystem.h>
#include <Systems/ScriptingSystem.h>

class Game;
class System;
class Entity;

class GameState
{
private:
    std::map<unsigned int, Entity*> entities_;

    //std::vector<Entity *> entities_;
    std::vector<System *> systems_;
    std::vector<Entity *> filterBySignature(unsigned long label);

public:

    RenderingSystem renderingSystem;
    ScriptingSystem    updateSystem;

    void performInit(Game *game);

    virtual void init(Game *game) {}

    void update(double timeElapsed);

    void addSystem(System *system);

    void addEntity(Entity *entity);

    void removeEntity(unsigned int entityId);
};


#endif //CHAOS_GAMESTATE_H
