#include <iostream>
#include <string>

#include "ManagementSystem.h"
using namespace std;
void modules()
{
    cout << "\n1.Show all employee";
    cout << "\n2.Query";
    cout << "\n3.hierarchy";
    cout << "\n4.employees reporting to the given manager";
    cout << "\n5.summary of Department, Designation, ReportingTo";
    cout << "\n6.Exit" << endl;
}
int main()
{
    cout << "\t\tEmployee Management System!!" << endl;
    ManagementSystem m;
    m.storeRecords();
    bool flag = true;
    while(flag)
    {
        modules();
        int choice;
        cin >> choice;
        switch(choice)
        {
        case 1:
            {
                // show employees
                ManagementSystem obj1;
                obj1.showEmployees();
                break;
            }
        case 2:
            {
                // Query
                ManagementSystem obj2;
                obj2.cmd();
                break;
            }
        case 3:
            {
                // hierarchy
                ManagementSystem obj3;
                obj3.hirarchy();
                break;
            }
        case 4:
            {
                // employees reporting to the given manager
                ManagementSystem obj4;
                obj4.reportingManager();
                break;
            }
        case 5:
            {
                // summary of Department, Designation, ReportingTo
                ManagementSystem obj5;
                obj5.ddreportingTo();
                break;
            }
        case 6:
            {
                // exit
                flag = false;
                break;
            }
        default:
            {
                cout << "\nInvalid try!!" << endl;
            }
        }
    }
    return 0;
}
