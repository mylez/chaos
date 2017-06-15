#ifndef CHAOS_ENTITY_H
#define CHAOS_ENTITY_H

#include <string>
#include <map>
#include <iostream>
#include <typeindex>
#include <typeinfo>
#include <Components/TransformComponent.h>

class Component;

class GameState;

unsigned int genEntityId();

class Entity
{
private:

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
        addComponent(&transform);
        id = genEntityId();
    }

    /**
     *
     * @tparam ComponentType
     * @param component
     */
    template<typename ComponentType>
    void addComponent(ComponentType *component)
    {
        std::cout << "the thing! " << component << "\n";

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

    virtual void destroy();
};


#endif //CHAOS_ENTITY_H
