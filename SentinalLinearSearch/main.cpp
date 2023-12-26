#include <iostream>
using namespace std;

int sentinal_Search(int arr[], int target, int sizeA);

int main()
{
    int countArr = 7, elements[countArr] = {4, 5, 6, 8, 9, 2};

    cout<<sentinal_Search(elements, -9, countArr);

    return 0;
}

int sentinal_Search(int arr[], int target, int sizeA)
{
    arr[sizeA-1] = target;

    int i = 0;
    while(i < sizeA)
    {
        if( arr[i] == target && i != (sizeA-1) )
        {
            return i;
        }
        i++;
    }
    return -1;
}
