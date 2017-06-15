#ifndef CHAOS_UPDATECOMPONENT_H
#define CHAOS_UPDATECOMPONENT_H

#include <Core/Component.h>
#include <Core/UpdateProcedure.h>

class UpdateComponent:
    public Component
{
public:
    UpdateProcedure *updateProcedure;
    UpdateComponent()
    { label = COMPONENT_UPDATE; }
};


#endif //CHAOS_UPDATECOMPONENT_H
