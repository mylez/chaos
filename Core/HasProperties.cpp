#include "HasProperties.h"

/**
 *
 * @param name
 * @param value
 */
void HasProperties::setProperty(std::string name, int value)
{
    this->properties[name].type = Property::TYPE_INT;
    this->properties[name]._int = value;
}


/**
 *
 * @param name
 * @param value
 */
void HasProperties::setProperty(std::string name, double value)
{
    this->properties[name].type = Property::TYPE_DOUBLE;
    this->properties[name]._double = value;
}


/**
 *
 * @param name
 * @param value
 */
void HasProperties::setProperty(std::string name, std::string value)
{
    this->properties[name].type = Property::TYPE_STRING;
    this->properties[name]._string = value;
}


/**
 *
 * @param name
 * @return
 */
int HasProperties::getIntProperty(std::string name)
{
    return this->properties[name]._int;
}


/**
 *
 * @param name
 * @return
 */
double HasProperties::getDoubleProperties(std::string name)
{
    return this->properties[name]._double;
}


/**
 *
 * @param name
 * @return
 */
std::string HasProperties::getStringProperty(std::string name)
{
    return this->properties[name]._string;
}











