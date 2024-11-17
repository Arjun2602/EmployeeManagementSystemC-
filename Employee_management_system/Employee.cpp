#include "Employee.h"

Employee::Employee()
:id(0),name(""),age(0),designation(""),department(""),reportingTo("")
{
}
Employee::Employee(int id, std::string name, int age, std::string designation, std::string department, std::string reportingTo)
{
    this->id = id;
    this->name = name;
    this->age = age;
    this->designation = designation;
    this->department = department;
    this->reportingTo = reportingTo;
}

int Employee::getId()
{
        return id;
}
std::string Employee::getName()
{
    return name;
}
int Employee::getAge()
{
    return age;
}
std::string Employee::getDesignation()
{
    return designation;
}
std::string Employee::getDepartment()
{
    return department;
}
std::string Employee::getReportingTo()
{
    return reportingTo;
}
