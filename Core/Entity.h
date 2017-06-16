#ifndef CHAOS_ENTITY_H
#define CHAOS_ENTITY_H

#include <string>
#include <map>
#include <unordered_map>
#include <iostream>
#include <typeindex>
#include <typeinfo>
#include <Components/TransformComponent.h>

class Component;

class Script;

class GameState;


class Entity
{
private:
    static unsigned int nextId_;

public:
    std::map<std::type_index, Component *> components_;

    TransformComponent transform;

    unsigned long
        signature = 0;

    unsigned int
        id = 0;

    std::string
        name;

    GameState *gameState;

    Entity()
    {
        id = ++nextId_;
        addComponent(&transform);
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
        components_[std::type_index(typeid(ComponentType))] = component;
    }


    /**
     *
     * @tparam ComponentType
     * @return
     */
    template<typename ComponentType>
    ComponentType *getComponent()
    {
        Component *component = components_[std::type_index(typeid(ComponentType))];
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
        Component *component = components_[std::type_index(typeid(ComponentType))];

        return (component == nullptr)
               ? false
               : dynamic_cast<ComponentType *>(component) != nullptr;
    }

    std::vector<Script *> getScripts();

    virtual void destroy();
};


#endif //CHAOS_ENTITY_H
