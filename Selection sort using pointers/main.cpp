#include <iostream>

using namespace std;

void selectionSortIntegers(int n, int *arr);
void printArr(int n, int *arr);

int main()
{
    int n = 6;
    int arr[n] = {4, 7, 1, 90, 6, 2};
    int* ptr = arr;

    selectionSortIntegers(n, ptr);
    printArr(n, ptr);

    return 0;
}

void selectionSortIntegers(int n, int *arr)
{
    int temp, minIndex;

    for(int i = 0; i < n; i++)
    {
        minIndex = i;
        for(int j = i; j < n; j++)
        {
            if(*(arr+j) < *(arr+minIndex))
            {
                minIndex = j;
            }
        }

        temp            = *(arr+i);
        *(arr+i)        = *(arr+minIndex);
        *(arr+minIndex) = temp;
    }
}


void printArr(int n, int *arr)
{
    for(int i = 0; i < n; i++)
    {
        cout<<*(arr+i)<< " ";
    }
}
