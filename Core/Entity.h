#ifndef CHAOS_ENTITY_H
#define CHAOS_ENTITY_H

#import <string>
#import <map>
#import <iostream>
#import <typeindex>
#import <typeinfo>

class Component;

class Entity
{
private:
    std::map<std::type_index, Component *> components_;
public:

    unsigned long signature;


    /**
     *
     * @tparam ComponentType
     * @param component
     */
    template<typename ComponentType>
    void addComponent(ComponentType *component)
    {
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
};


#endif //CHAOS_ENTITY_H
