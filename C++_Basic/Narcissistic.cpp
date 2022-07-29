#include<iostream>
#include<cmath>

using namespace std;

int main__nn()
{
    // Narcissistic number
    /* Narcissistic number is a 3 position number, the sum of the 3 power of the number of each position is number itself
       Using do... while to find all the Narcissistic number*/
    
    int num = 100;

    do
    {
        // Find the hundard position
        int h = num / 100; 
        // Find the ten position
        int t = (num % 100) / 10;  
        // Find the one position
        int o = num % 10; 

        if (pow(h,3) + pow(t,3) + pow(o,3) == num)
        {
            cout<<"Narcissistic number: \t"<<num<<endl;
        }

        num++;
    } while (num<1000);
    


    
    return 0;
}