#include "ManagementSystem.h"

// static data members

std::unordered_map<std::string, Employee> ManagementSystem::employeeList;

//**************************************
// store employee record in employees

void ManagementSystem::storeRecords()
{
    employeeList["Alice"] = Employee(1,"Alice",28,"SoftwareEngineer","IT","Bob");
    employeeList["Bob"] = Employee(2,"Bob",35,"TeamLead","IT","Charlie");
    employeeList["Charlie"] = Employee(3,"Charlie",42,"Manager","IT","Diana");
    employeeList["Diana"] = Employee(4,"Diana",45,"SeniorManager","IT","Edward");
    employeeList["Edward"] = Employee(5,"Edward",50,"Director","Management","NULL");
    employeeList["Fiona"] = Employee(6,"Fiona",29,"DataAnalyst","Analytics","Grace");
    employeeList["Grace"] = Employee(7,"Grace",34,"AnalyticsLead","Analytics","Harry");
    employeeList["Harry"] = Employee(8,"Harry",30,"HRExecutive","Human Resource","Iris");
    employeeList["Iris"] = Employee(9,"Iris",40,"HRManager","HumanResource","Jack");
    employeeList["Jack"] = Employee(10,"Jack",32,"Marketing Lead","Marketing","NULL");
}

// show employees - print
void ManagementSystem::showEmployees()
{
    std::cout << "id   name   age   designation   department   reportingTo" << std::endl;
    for(auto it = employeeList.begin(); it != employeeList.end(); it++)
    {
        Employee e = it->second;
        std::cout << e.getId() << "  " << e.getName() << "   " << e.getAge() << "   " << e.getDesignation() << "   " << e.getDepartment() << "   " << e.getReportingTo() << std::endl;

    }
}

// name age designation department reportingTo
//  >, <, !=, ==
// ‘startswith’, ‘contains’, ‘endswith’, ‘notcontains’, ‘equals’ ‘notequals’.
bool ManagementSystem::valid(Employee& e, std::string field, std::string optr, std::string value)
{
    if(field == "age")
    {
        int val = std::stoi(value);
        if(optr == ">")
        {
            return e.getAge() > val;
        }else if(optr == "<")
        {
            return e.getAge() < val;
        }else if(optr == "!=")
        {
            return e.getAge() != val;
        }else if(optr == "==")
        {
            return e.getAge() == val;
        }
    }else if(field == "name")
    {
        if(optr == "startswith")
        {
            return e.getName().find(value) == 0;
        }else if(optr == "endswith")
        {
            return e.getName().rfind(value) == e.getName().length() - value.length();
        }else if(optr == "contains")
        {
            return e.getName().find(value) != std::string::npos;
        }else if(optr == "notcontains")
        {
            return e.getName().find(value) == std::string::npos;
        }else if(optr == "equals")
        {
            return e.getName() == value;
        }else if(optr == "notequals")
        {
            return e.getName() != value;
        }
    }else if(field == "designation")
    {
        if(optr == "startswith")
        {
            return e.getDesignation().find(value) == 0;
        }else if(optr == "endswith")
        {
            return e.getDesignation().rfind(value) == e.getDesignation().length() - value.length();
        }else if(optr == "contains")
        {
            return e.getDesignation().find(value) != std::string::npos;
        }else if(optr == "notcontains")
        {
            return e.getDesignation().find(value) == std::string::npos;
        }else if(optr == "equals")
        {
            return e.getDesignation() == value;
        }else if(optr == "notequals")
        {
            return e.getDesignation() != value;
        }
    }else if(field == "department")
    {
        if(optr == "startswith")
        {
            return e.getDepartment().find(value) == 0;
        }else if(optr == "endswith")
        {
            return e.getDepartment().rfind(value) == e.getDepartment().length() - value.length();
        }else if(optr == "contains")
        {
            return e.getDepartment().find(value) != std::string::npos;
        }else if(optr == "notcontains")
        {
            return e.getDepartment().find(value) == std::string::npos;
        }else if(optr == "equals")
        {
            return e.getDepartment() == value;
        }else if(optr == "notequals")
        {
            return e.getDepartment() != value;
        }
    }else if(field == "reportingTo")
    {
        if(optr == "startswith")
        {
            return e.getReportingTo().find(value) == 0;
        }else if(optr == "endswith")
        {
            return e.getReportingTo().rfind(value) == e.getReportingTo().length() - value.length();
        }else if(optr == "contains")
        {
            return e.getReportingTo().find(value) != std::string::npos;
        }else if(optr == "notcontains")
        {
            return e.getReportingTo().find(value) == std::string::npos;
        }else if(optr == "equals")
        {
            return e.getReportingTo() == value;
        }else if(optr == "notequals")
        {
            return e.getReportingTo() != value;
        }
    }
}

bool ManagementSystem::validate(Employee& e, std::vector<Condition>& conditionList)
{
    for(auto& c : conditionList)
    {
        std::string field = c.getField();
        std::string optr = c.getOptr();
        std::string value = c.getValue();
        if(!valid(e, field, optr, value))
        {
            return false;
        }
    }
    return true;
}

void ManagementSystem::initiateEvaluation(std::unordered_map<std::string,Employee>& employeeList, std::vector<Condition>& conditionList)
{
    for(auto& e : employeeList)
    {
        Employee emp = e.second;
        if(validate(emp, conditionList))
        {
            std::cout << emp.getId() << "  " << emp.getName() << "   " << emp.getAge() << "   " << emp.getDesignation() << "   " << emp.getDepartment() << "   " << emp.getReportingTo() << std::endl;
        }
    }
}

// command promt
void ManagementSystem::cmd()
{
    std::vector<Condition> conditionnList;
    std::string field;
    std::string optr;
    std::string value;
    std::string after;
    while(true)
    {
        std::cin >> field;
        std::cin >> optr;
        std::cin >> value;
        std::cin >> after;
        if(after == "AND" || after == "and")
        {
            conditionnList.push_back(Condition(field,optr,value));
        }else if(after == "end" || after == "END")
        {
            conditionnList.push_back(Condition(field,optr,value));
            break;
        }
    }
    initiateEvaluation(employeeList, conditionnList);
    /*
    for(auto& condition : conditionnList)
    {
        std::cout << condition.getField() << " " << condition.getOptr() << " " << condition.getValue() << std::endl;
    }
    */
}

void ManagementSystem::getHirarchy(std::vector<std::string>& nameList, std::string& name)
{
    for(auto& x : employeeList)
    {
        Employee e = x.second;
        if(e.getReportingTo() == name)
        {
            std::string nam = e.getName();
            nameList.push_back(nam);
            getHirarchy(nameList, nam);
        }
    }
}

void ManagementSystem::hirarchy()
{
    for(auto& e : employeeList)
    {
        Employee emp = e.second;
        if(emp.getReportingTo() == "NULL")
        {
            std::vector<std::string> nameList;
            std::string nam = emp.getName();
            nameList.push_back(nam);
            getHirarchy(nameList, nam);

            int n = nameList.size();
            for(int i = n-1; i >= 0; i--)
            {
                if(i != 0)
                {
                    std::cout << nameList[i] << "->";
                }else
                {
                    std::cout << nameList[i];
                }
            }
            std::cout << std::endl;
            nameList.clear();
        }
    }
}

void ManagementSystem::reportingManager()
{
    std::cout << "Employee\tReportingManager" << std::endl;
    for(auto& a : employeeList)
    {
        Employee e = a.second;
        std::cout << e.getName() << "\t\t"<< e.getReportingTo() << std::endl;
    }
}

void ManagementSystem::ddreportingTo()
{
    std::cout << "Department Designation ReportingTo" << std::endl;
    for(auto& a : employeeList)
    {
        Employee e = a.second;
        std::cout << e.getDepartment() << "\t\t\t" << e.getDesignation() << "\t\t\t" << e.getReportingTo() << std::endl;
    }
}


