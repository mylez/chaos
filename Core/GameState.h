#ifndef CHAOS_GAMESTATE_H
#define CHAOS_GAMESTATE_H

#include <map>
#include <vector>
#include <Core/Entity.h>
#include <Systems/RenderingSystem.h>
#include <Systems/ScriptingSystem.h>
#include <vector>

class Game;

class System;

class Entity;

namespace std
{
    template<>
    struct hash<std::pair<int, int>>
    {
        size_t operator()(const std::pair<int, int> &pt) const
        {
            return std::hash<int>()((pt.first & 0xFFFF) | (0x10000 * pt.second));
        }
    };
}



class GameState
{
private:
    std::vector<System *> systems_;

public:
    Vec2d
        spatialCacheGridSize;

    std::unordered_map<std::pair<int, int>, std::vector<Entity *> >
        spatialCache;

    std::unordered_map<unsigned int, Entity *>
        entities;

    Game *game;

    double timeElapsed;

    /**
     *
     */
    GameState():
        spatialCacheGridSize(Vec2d(320, 320))
    {}

    /**
     *
     * @param game
     */
    void performInit(Game *game);

    /**
     *
     * @param game
     */
    virtual void init()
    {}

    /**
     *
     * @param timeElapsed
     */
    void performUpdate(double timeElapsed);

    /**
     *
     */
    virtual void update()
    {}

    /**
     *
     * @param system
     */
    void addSystem(System *system);

    /**
     *
     * @tparam SystemType
     * @return
     */
    template<typename SystemType>
    SystemType *addSystem()
    {
        SystemType *system = new SystemType;
        system->managed_ = true;
        addSystem(system);
        return system;
    }

    /**
     *
     * @param entity
     */
    void addEntity(Entity *entity);

    /**
     *
     * @param entityId
     */
    void removeEntity(unsigned int entityId);

    /**
     *
     * @param label
     * @return
     */
    std::vector<Entity *> filterEntitiesBySignature(unsigned long label);

    /**
     *
     * @param position
     * @return
     */
    std::vector<Entity *> filterEntitiesByPosition(Vec2d position);

    /**
     *
     * @param name
     * @return
     */
    Entity *findEntityByName(std::string name);

    /**
     *
     */
    void updateSpatialCache();

    /**
     *
     * @tparam ComponentType
     * @return
     */
    template<typename ComponentType>
    Entity *findEntityByComponent()
    {
        for (const auto &e: entities)
        {
            if (e.second->hasComponent<ComponentType>())
            {
                return e.second;
            }
        }
        return nullptr;
    }

    /**
     *
     */
    ~GameState();
};


#endif //CHAOS_GAMESTATE_H
