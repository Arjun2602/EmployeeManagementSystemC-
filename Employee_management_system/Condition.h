#ifndef CONDITION_H_INCLUDED
#define CONDITION_H_INCLUDED

#include <string>
class Condition
{
private:
    std::string field;
    std::string optr;
    std::string value;
public:
    Condition();
    Condition(std::string field, std::string optr, std::string value);
    std::string getField();
    std::string getOptr();
    std::string getValue();
};

#endif // CONDITION_H_INCLUDED
