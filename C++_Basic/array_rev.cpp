#include<iostream>
using namespace std;

int main_rev()
{
    // Reverse the array elements display
    /*
    1. Declear a array inlcuding 5 elements
    2. Then reverse the array
    */
    
    int arr[5] = {1,2,3,4,5};
    int start = 0;
    int end = sizeof(arr)/sizeof(arr[0])-1;
    
    // while (start<end)
    // {
    //     int temp = arr[start];
    //     arr[start] = arr[end];
    //     arr[end] = temp;

    //     start++;
    //     end--;   
    // }

    for (int i=0; i<end; i++)
    {
        int temp = arr[i];
        arr[i] = arr[end];
        arr[end] = temp;
        end--;
    }

    for (int i=0; i<5; i++)
    {
        cout<<arr[i]<<endl;
    }


    return 0;
}