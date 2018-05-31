#ifndef CHAOS_RECTRENDERCOMPONENT_H
#define CHAOS_RECTRENDERCOMPONENT_H

#include <Core/Component.h>
#include <Core/Vec2d.h>
#include <Core/Color.h>

class ShapeComponent:
    public Component
{
private:
    Vec2d size;
    Color color;
public:
    ShapeComponent():
        size(Vec2d(1, 1)),
        color(Color(180, 180, 185))
    { label = COMPONENT_SHAPE; }

    /**
     *
     * @param size
     */
    void setSize(Vec2d size)
    {
        this->entity->boundingBox.size = size;
        this->size = size;
    }

    /**
     *
     * @return
     */
    Vec2d getSize()
    {
        return size;
    }

    /**
     *
     * @param color
     */
    void setColor(Color color)
    {
        this->color = color;
    }

    /**
     *
     * @return
     */
    Color getColor()
    {
        return color;
    }

};


#endif //CHAOS_RECTRENDERCOMPONENT_H
