#include<iostream>

using namespace std;

/* Create a generic function for sort arrays
   1. Descending Order
   2. Selection Sort
   3. Test char Array and int Array*/

// Swap func template
template<class T>
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}


// Selection Sort template
template<class T>
void Selection_Sort(T arr[], int len)
{
    for (int i=0; i<len; i++)
    {
        // Assume the ith index is the largest
        int max = i;
        for (int j = i+1; j<len; j++)
        {
            // if the ith index is smaller than the jth index number, change the index
            if (arr[max]<arr[j])
            {
                max = j;
            }
        }
        mySwap(arr[max], arr[i]);
        // if (max != i)
        // {
        //     // Swap max and i
        //     mySwap(arr[max], arr[i]);
        // }
    }
}

// Pring Array template
template<class T>
void printArray(T arr[], int len)
{
    for (int i=0; i<len; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}



void test01()
{
    // Test char array
    char charArr[] = "badcfe";
    int char_len = sizeof(charArr) / sizeof(char);
    Selection_Sort(charArr, char_len);
    printArray(charArr, char_len);

}

void test02()
{
    // Test int
    int intArr[] = {7,5,1,3,9,2,4,6,8};
    int num = sizeof(intArr) / sizeof(int);
    Selection_Sort(intArr, num);
    printArray(intArr, num);

}

int main()
{
    test01();
    test02();
    return 0;
}