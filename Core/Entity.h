#ifndef CHAOS_ENTITY_H
#define CHAOS_ENTITY_H

#include <string>
#include <map>
#include <unordered_map>
#include <iostream>
#include <typeindex>
#include <typeinfo>
#include <Components/TransformComponent.h>
#include <Components/BoundingBoxComponent.h>

class Component;

class Script;

class GameState;

class Entity
{
private:
    static unsigned int nextId_;

public:

    // track parent entity for scene graph traversal
    Entity *parent;

    // track children entities for scene graph traversal
    std::vector<Entity *> children;

    // every entity has a transform by default, so it is
    // created by every entity
    TransformComponent transform;

    // every entity has a bounding box by default, so it is
    // created by every entity
    BoundingBoxComponent boundingBox;

    // the list of components attached to this entity
    std::unordered_map<std::type_index, Component *> components;

    // list of indices where this entity is tracked by
    // the spatial cache
    std::vector<std::pair<int, int> > spatialCacheKeys;

    // memory management - was this entity created on the
    // heap by a core game object?
    bool
            managed_ = false;

    // a 64 bit bit mask of which entities are applied
    unsigned long
        signature;

    // a unique id that refers to this entity
    unsigned int
        id;

    // a non-unique name that can refer to entities
    std::string
        name;

    // a reference to the game state to which this
    // entity belongs
    GameState *gameState;

    Entity():
        signature(0),
        parent(nullptr),
        id(++nextId_)
    {
        addComponent(&transform);
        addComponent(&boundingBox);
    }

    /**
     *
     * @tparam ComponentType
     * @param component
     */
    template<typename ComponentType>
    void addComponent(ComponentType *component)
    {
        std::cout << typeid(ComponentType).name() << "\t" << component << "\t to entity " << id << "\n";
        component->entity = this;
        signature = signature | component->label;
        components[std::type_index(typeid(ComponentType))] = component;
    }

    /**
     *
     * @tparam ComponentType
     * @return
     */
    template<typename ComponentType>
    ComponentType *addComponent()
    {
        ComponentType *component = new ComponentType;
        component->managed_ = true;
        addComponent(component);
        return component;
    }

    /**
     *
     * @tparam ComponentType
     * @return
     */
    template<typename ComponentType>
    ComponentType *getComponent()
    {
        Component *component = components[std::type_index(typeid(ComponentType))];
        return (component == nullptr)
               ? nullptr
               : dynamic_cast<ComponentType *>(component);
    }


    /**
     *
     * @tparam ComponentType
     * @return
     */
    template<typename ComponentType>
    bool hasComponent()
    {
        Component *component = components[std::type_index(typeid(ComponentType))];

        return (component == nullptr)
               ? false
               : dynamic_cast<ComponentType *>(component) != nullptr;
    }

    /**
     *
     * @param x
     * @param y
     * @return
     */
    bool hasSpatialCacheKey(int x, int y)
    {
        return hasSpatialCacheKey(std::pair<int, int>(x, y));
    }

    /**
     *
     * @param key
     * @return
     */
    bool hasSpatialCacheKey(std::pair<int, int> key)
    {
        for (const auto &k: spatialCacheKeys)
        {
            if (k.first == key.first && k.second == key.second)
            {
                return true;
            }
        }
        return false;
    }



    /**
     *
     * @return
     */
    std::vector<Script *> getScripts();
};


#endif //CHAOS_ENTITY_H
