#include <iostream>

using namespace std;

// {2, 3, 4, 6, 7, 9}

int main()
{
    int  n = 6;
  //-----------------------------------------{0, 1, 2, 3, 4, 5};
    int target, start, finish, mid, arr[n] = {3, 4, 6, 7, 9, 10};
    target = 9;
    int found = 0;

    start   = 0;
    finish  = n-1;


    while(found != 1)
    {
        if(target == arr[n-1])
        {
            cout<<"Found! at index : "<<n-1;
            found = 1;
        }

        mid  = (start + finish) / 2;

        if(arr[mid] != target)
        {
           if(target < arr[mid])
            {
                finish  = mid;

            }else if(target > arr[mid])
            {
                start  = mid;
            }
        }else
        {
            cout<<"Found! at index : "<<mid<<endl;
            found = 1;
        }
    }


    return 0;
}
