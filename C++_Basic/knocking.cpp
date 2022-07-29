#include<iostream>

using namespace std;

int main_kd()
{
    //Knocking desk, from 1 to 100, if a number has 7 in o, t or the times of 7, we print Knocking desk, the remaining numbers print out
    int t;  int o;

    for (int i = 1; i<=100; i++)
    {
        //Find the ten position of a number
        t = i / 10;
        o = i % 10;

        if (t == 7 || o == 7 || i%7==0)
        {
            cout<<"Knocking Desk"<<endl;
        }
        else
        {
            cout<<i<<endl;
        }

    }

    return 0;
}