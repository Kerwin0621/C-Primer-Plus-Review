#include<iostream>
using namespace std;

int main_bubble()
{
    int arr[9] = {4,2,8,0,5,7,1,3,9};
    int end = sizeof(arr)/sizeof(arr[0]) -1;

    for (int i=0; i<end; i++)
    {
        for (int j=0; j<end-i; j++)
        {
            if (arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    for (int k=0; k<end; k++)
    {
        cout<<arr[k]<<endl;
    }
    
    return 0;

}