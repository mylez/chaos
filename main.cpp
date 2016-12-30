#include <iostream>
#include "Chaos/Chaos.h"
#include "json/json.h"

using namespace std;

int main()
{

    Json::Value root;
    Json::Reader reader;
    reader.parse(" { \"some\": {\"stupid\":6969 } } ", root);

    std::cout << "is parse success? " << root["some"]["stupid"].asInt() << std::endl;

    Chaos chaos;
    //chaos.loop();
}