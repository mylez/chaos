#ifndef CHAOS_GAMESTATE_H
#define CHAOS_GAMESTATE_H

#include <map>
#include <vector>
#include <Core/Entity.h>
#include <Systems/RenderingSystem.h>
#include <Systems/ScriptingSystem.h>

class Game;

class System;

class Entity;

class GameState
{
private:
    //std::vector<Entity *> entities_;
    std::vector<System *> systems_;


public:

    std::map<unsigned int, Entity *> entities_;

    RenderingSystem renderingSystem;
    ScriptingSystem updateSystem;

    void performInit(Game *game);

    virtual void init(Game *game)
    {}

    void update(double timeElapsed);

    void addSystem(System *system);

    template<typename SystemType>
    SystemType *addSystem()
    {
        SystemType *system = new SystemType;
        system->managed_ = true;
        addSystem(system);
        return system;
    }

    Entity *findEntity(std::string name);

    void addEntity(Entity *entity);

    void removeEntity(unsigned int entityId);

    std::vector<Entity *> filterEntitiesBySignature(unsigned long label);


    template<typename ComponentType>
    Entity *findEntityWithComponent()
    {
        for (const auto &e: entities_)
        {
            if (e.second->hasComponent<ComponentType>())
            {
                return e.second;
            }
        }
        return nullptr;
    }

    ~GameState();
};


#endif //CHAOS_GAMESTATE_H
