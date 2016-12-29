#include <iostream>
#include "Chaos/Chaos.h""

using namespace std;

int main()
{

    Chaos chaos;

    chaos.assetLibrary.loadTexture("fucker", "level-png/map-tile-32x32.png");

    chaos.loop();
}