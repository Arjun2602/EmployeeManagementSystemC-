#include "Condition.h"

Condition::Condition()
:field(""),optr(""),value("")
{

}
Condition::Condition(std::string field, std::string optr, std::string value)
{
    this->field = field;
    this->optr = optr;
    this->value = value;
}
std::string Condition::getField()
{
    return field;
}
std::string Condition::getOptr()
{
    return optr;
}
std::string Condition::getValue()
{
    return value;
}
