#include "HasProperties.h"

/**
 *
 * @param name
 * @param value
 */
void HasProperties::setProperty(std::string name, int value)
{
    properties_[name].type = Property::TYPE_INT;
    properties_[name]._int = value;
}


/**
 *
 * @param name
 * @param value
 */
void HasProperties::setProperty(std::string name, double value)
{
    properties_[name].type = Property::TYPE_DOUBLE;
    properties_[name]._double = value;
}


/**
 *
 * @param name
 * @param value
 */
void HasProperties::setProperty(std::string name, std::string value)
{
    properties_[name].type = Property::TYPE_STRING;
    properties_[name]._string = value;
}


/**
 *
 * @param name
 * @return
 */
int HasProperties::getIntProperty(std::string name)
{
    return properties_[name]._int;
}


/**
 *
 * @param name
 * @return
 */
double HasProperties::getDoubleProperties(std::string name)
{
    return properties_[name]._double;
}


/**
 *
 * @param name
 * @return
 */
std::string HasProperties::getStringProperty(std::string name)
{
    return properties_[name]._string;
}











