#include "Entity.h"
#include "Component.h"
#include <iostream>

void Entity::addComponent(Component *component) {
    std::cout << "adding component: " << component->label << std::endl;
    component->entity = this;
    signature = signature | component->label;
    components_[component->label] = component;
}

Component *Entity::getComponent(unsigned long label) {
    return components_[label];
}
