#include <iostream>

using namespace std;

void BS(int arr[], int start, int finish, int target, int found);

int main()
{
    int  n = 6, found = 0;
  //-----------------------------------------{0, 1, 2, 3, 4, 5};
    int target, start, finish, mid, arr[n] = {3, 4, 6, 7, 9, 10};
    target = 7;

    start   = 0;
    finish  = n-1;

    BS(arr, start, finish, target, found);

    return 0;
}


void BS(int arr[], int start, int finish, int target, int found)
{
    int mid  = (start + finish) / 2;

    // base case
    if(found == 1)
    {
        cout<<"Found! at index : "<<mid<<endl;
        return;
    }


    if(arr[mid] != target)
    {
       if(target < arr[mid])
        {
            finish  = mid-1;
            BS(arr, start, finish, target, found);

        }else if(target > arr[mid])
        {
            start  = mid+1;
            BS(arr, start, finish, target, found);
        }
    }else
        {
            found = 1;
            BS(arr, start, finish, target, found);
        }

}
