#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include <string>

class Employee
{
private:
    int id;
    std::string name;
    int age;
    std::string designation;
    std::string department;
    std::string reportingTo;
public:
    Employee();
    Employee(int id, std::string name, int age, std::string designation, std::string department, std::string reportingTo);

    int getId();
    std::string getName();
    int getAge();
    std::string getDesignation();
    std::string getDepartment();
    std::string getReportingTo();

};


#endif // EMPLOYEE_H_INCLUDED
