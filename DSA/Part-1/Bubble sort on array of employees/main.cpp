#include <iostream>

using namespace std;

struct Employee{
    int id;
};

void bubbleSortArrayOfEmployees(Employee* arr, int n);

int main()
{
    /* Implement a bubble sort on an array of Employees */
    int temp, i, j, n = 4;
    Employee arr[n] = {1, 9, 0, 7};
    bubbleSortArrayOfEmployees(arr, n);

    return 0;
}

void bubbleSortArrayOfEmployees(Employee* arr, int n)
{
    // declaring iterators, temp and flag for determining sorted or not.
    int i, j, temp ,flag = 1;


        for(j = 0; j < n-1; j++)
        {
            // swap if not well-sorted
            if(arr[j].id > arr[j+1].id)
            {
                temp            = arr[j].id;
                arr[j].id          = arr[j+1].id;
                arr[j+1].id        = temp;
                flag++;
            }
        }

    if(flag == 1)
    {
        // print and exit if sorted.
        for(int i = 0; i < n; i++)
        {
            cout<<arr[i].id<< " ";
        }
        return;
    }else
    {
        // if not sorted yet call itself again until no swapping is performed at all which means sorted.
        bubbleSortArrayOfEmployees(arr, n);
    }


}
