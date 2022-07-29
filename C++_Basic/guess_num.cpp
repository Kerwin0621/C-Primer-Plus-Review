#include<iostream>
#include<string>
#include<time.h>

using namespace std;

int main_guess()
{
    srand(time(NULL));
    // Generate random number
    int r = 0;
    r = rand() % 100 + 1; // Generate number between 1 and 100
    // Build the loop
    while (1)
    {
        // Ask user to input a number
        cout<<"Please input a number \t";
        int x;
        cin>>x;

        //Compare the input and the random number
        if (x>r)
        {
            cout<<"The number you guess is greater than the correct"<<endl;
        }
        else if (x<r)
        {
            cout<<"The number you guess is less than the correct"<<endl;
        }
        
        else
        {
            cout<<"Your guess is correct"<<endl;
            break;
        }

    }

    return 0;
}