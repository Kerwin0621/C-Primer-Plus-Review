#include<iostream>

using namespace std;
// Note: arr is the initial address of that array, if we want the whole array, we need used pointer or arr[]

// Bubble Sort for ascending order
void BubbleSort(int arr[], int len)
{
    for (int i=0; i<len-1; i++)
    {
        for (int j=0; j<(len-1-i); j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void PrintArray(int *arr, int len)
{
    for (int i=0; i<len-1; i++)
    {
        cout<<arr[i]<<endl;
    }
}

int main_ap()
{
    // Encapsulate a function, using bubble sort to ascending order of an int array

    // Define an Array
    int arr[] = {4,2,8,0,5,7,1,3,9};
    // Calculate the length of array
    int len = sizeof(arr)/sizeof(arr[0]);

    cout<<"Before the Re-SORT:"<<endl;;
    // for(int i=0; i<len-1; i++)
    // {
    //     cout<<arr[i]<<endl;
    // }
    PrintArray(arr, len);

    BubbleSort(arr, len);

    cout<<"After the Re-SORT:"<<endl;;
    // for(int j=0; j<len-1; j++)
    // {
    //     cout<<arr[j]<<endl;
    // }
    PrintArray(arr, len);

    return 0;
}