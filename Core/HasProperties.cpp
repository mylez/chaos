//
// Created by Miles on 12/28/16.
//

#include "HasProperties.h"

void HasProperties::setProperty(std::string name, int value)
{
    this->properties[name].type = Property::TYPE_INT;
    this->properties[name]._int = value;
}

void HasProperties::setProperty(std::string name, double value)
{
    this->properties[name].type = Property::TYPE_DOUBLE;
    this->properties[name]._double = value;
}

void HasProperties::setProperty(std::string name, std::string value)
{
    this->properties[name].type = Property::TYPE_STRING;
    this->properties[name]._string = value;
}

int HasProperties::getIntProperty(std::string name)
{
    return this->properties[name]._int;
}

double HasProperties::getDoubleProperties(std::string name)
{
    return this->properties[name]._double;
}

std::string HasProperties::getStringProperty(std::string name)
{
    return this->properties[name]._string;
}











