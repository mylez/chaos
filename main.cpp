#include <iostream>
#include "Chaos/Chaos.h"

int main()
{
    using namespace std;

    // Json::Value root;
    // Json::Reader reader;
    // std::ifstream fyle("/Users/miles/Desktop/test.json");
    // reader.parse(fyle, root);
    // root["height"] == 5

    Chaos chaos;
    chaos.loop();
}