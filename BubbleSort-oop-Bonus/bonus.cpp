#include <iostream>

using namespace std;

struct Employee{
    int id;
};

class Bonus
{
    protected:
        virtual void performBubbleSort(string opt = "ASC") = 0;     // abstract method
};


class Option : public Bonus
{
    public:

        /* Default Constructor */
        Option()
        {
            /* Default order is Ascending */
            performBubbleSort();
        }

        /* Parameterized Constructor */
        Option(string _opt)
        {
            int temp, i, j, n = 3;
            Employee arr[3] = {40, 8, 9};

            for(i = 0; i < n-1; i++)
            {
                for(j = 0; j < n-1; j++)
                {
                    if(arr[j].id < arr[j+1].id)
                    {
                        temp            = arr[j].id;
                        arr[j].id          = arr[j+1].id;
                        arr[j+1].id        = temp;
                    }
                }
            }

            for(int i = 0; i < n; i++)
            {
                cout<<arr[i].id<< " ";
            }
           cout<<endl;
        }

        void performBubbleSort(string opt = "ASC")
        {
            int temp, i, j, n = 3;
            Employee arr[3] = {40, 8, 9};

            for(i = 0; i < n-1; i++)
            {
                for(j = 0; j < n-1; j++)
                {
                    if(arr[j].id > arr[j+1].id)
                    {
                        temp            = arr[j].id;
                        arr[j].id          = arr[j+1].id;
                        arr[j+1].id        = temp;
                    }
                }
            }

            for(int i = 0; i < n; i++)
            {
                cout<<arr[i].id<< " ";
            }
            cout<<endl;
        }
};

int main()
{

    /*  Implement a bubble sort on an array of Employees
        regarding the ability to choose between ascending and descending order
        without using switch case or if condition */

    Option o1;           // ASC
    Option o2("DESC");  // DESC

    return 0;
}
