#ifndef CHAOS_ENTITY_H
#define CHAOS_ENTITY_H

#import <string>
#import <map>

class Component;

class Entity
{
private:
    std::map<unsigned long, Component*> components_;
public:
    unsigned long signature;
    void addComponent(Component* component);
    Component *getComponent(unsigned long label);
};


#endif //CHAOS_ENTITY_H
