#include<iostream>

using namespace std;

int main_fm()
{
    // There is an array includes 5 objects weights, find the output the heaviest object
    int arr[5] = {300, 500, 200, 400, 250};
    int pix = sizeof(arr)/sizeof(arr[0]);
    int max = 0;
    for (int i=0; i<(pix); i++)
    {
        if (arr[i]>max)
        {
            max = arr[i];
        }
    }
    cout<<max<<endl;


    return 0;
}