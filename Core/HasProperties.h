#ifndef CHAOS_HASPROPERTIES_H
#define CHAOS_HASPROPERTIES_H

#include <string>
#include <unordered_map>

class Property
{
public:
    static const int
        TYPE_INT = 1,
        TYPE_DOUBLE = 2,
        TYPE_STRING = 3;

    int type;

    int _int;
    double _double;
    std::string _string;

};


class HasProperties
{
public:
    void setProperty(std::string, int);
    void setProperty(std::string, double);
    void setProperty(std::string, std::string);

    int getIntProperty(std::string name);
    double getDoubleProperties(std::string name);
    std::string getStringProperty(std::string name);

private:
    std::unordered_map<std::string, Property> properties;
};


#endif //CHAOS_HASPROPERTIES_H
