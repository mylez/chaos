#include <cstdlib>
#include "PlayerGameObject.h"

PlayerGameObject::PlayerGameObject()
{
    setPosition(rand() % 100, rand() % 100);

    setProperty("name", "Puppy");
}