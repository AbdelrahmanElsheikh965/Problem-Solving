#include <iostream>
#include <string.h>

using namespace std;


class Pointer
{
    //
};

/*
	Duplication/Repetition is way too much bad in programming.
	So, according to DRY principle: 
	
    TODO: Make a blueprint class that have a compare function.
    TODO: Create some classes that inherit from 'Pointer' base class
            implementing compare() with different data types depending on className that indicates data type.
    TODO: Make a new generic function that performs searching mechanism & takes an implementation from 'Pointer'.
    TODO: In main create different objects from different classes and pass to the generic function.
*/


class Employee
{
    public:
        int id;
        string name;
        double salary;
};

int linearSearchByName(Employee emps[], string target, int sizeA)
{
    int i = 0;
    while(i < sizeA)
    {
        if(emps[i++].name == target)
            return i;
    }
    return -1;
}

int linearSearchById(Employee emps[], int target, int sizeA)
{
    int i = 0;
    while(i < sizeA)
    {
        if(emps[i++].id == target)
            return i;
    }
    return -1;
}

int linearSearchBySalary(Employee emps[], double target, int sizeA)
{
    int i = 0;
    while(i < sizeA)
    {
        if(emps[i++].salary == target)
            return i;
    }
    return -1;
}

int main()
{
    int rows = 4;

    Employee emps[rows] = {{87, "ali", 25000}, {99, "taha", 35000}, {3, "mohsen", 40000}, {65, "zakaria", 50000}};

    cout<<"Index of Name-(taha) : "     << linearSearchByName(emps, "taha", rows)<<endl;
    cout<<"Index of Id-(99) : "         << linearSearchById(emps, 99, rows)<<endl;
    cout<<"Index of Salary-(35000) : "  << linearSearchBySalary(emps, 35000, rows)<<endl;

    return 0;
}
