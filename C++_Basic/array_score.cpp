#include<iostream>
#include<string>
#include<array>
using namespace std;

int main_score()
{
    // Store the numbers in 2D arrays
    int score[3][3] = 
    {
        {100, 100, 100},
        {90, 50, 100},
        {60, 70, 80}
    };
    
    string name[3] =  {"Zhang", "Li", "Wang"};
    // Using array class to create string set
    array<string, 3> name{"Zhang", "Li", "Wang"};


    for (int i=0; i<3; i++)
    {
        // The key point is: the array in C++ is grouped in column, the inner loop indicates the column. The outer loop indicates the row.
        int sum = 0;
        for (int j=0; j<3;j++)
        {
            //cout<<score[i][j]<<"\t";
            sum += score[i][j];
        }
        // Output the result with names
        cout<<"The Student:\t"<<name[i]<<"\t has the score in overall:\t"<<sum<<endl;
    } 
    return 0;
}