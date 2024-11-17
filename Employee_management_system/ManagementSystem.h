#ifndef MANAGEMENTSYSTEM_H_INCLUDED
#define MANAGEMENTSYSTEM_H_INCLUDED

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

#include "Employee.h"
#include "Condition.h"

class ManagementSystem
{
public:
    static std::unordered_map<std::string, Employee> employeeList;

    void storeRecords();

    void showEmployees();

    void cmd();

    void initiateEvaluation(std::unordered_map<std::string, Employee>& employeeList, std::vector<Condition>& conditionnList);

    bool validate(Employee& emp, std::vector<Condition>& conditionList);

    bool valid(Employee& e, std::string field, std::string optr, std::string value);

    void hirarchy();

    void getHirarchy(std::vector<std::string>& nameList, std::string& name);

    void reportingManager();

    void ddreportingTo();
};

#endif // MANAGEMENTSYSTEM_H_INCLUDED
