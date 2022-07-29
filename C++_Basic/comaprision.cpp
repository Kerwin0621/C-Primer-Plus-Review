// Compare three objects weight, by inputing the value
#include<iostream>
#include<string>
using namespace std;

int main_ABC()
{
    int A = 0;
    int B = 0;
    int C = 0;
    //Input three objects weight
    cout<<"Please input the weight of A \t";   cin>>A;     cout<<"The weight of A is:"<<A<<endl;
    cout<<"Please input the weight of B \t";   cin>>B;     cout<<"The weight of B is:"<<B<<endl;
    cout<<"Please input the weight of C \t";   cin>>C;     cout<<"The weight of C is:"<<C<<endl;

    // Compare which object is the heaviest
    if (A>B)
    {
        if (A>C)
        {
            if (B>C)
            {
                cout<<"A>B>C"<<endl;
            }
            else
            {
                cout<<"A>C>B"<<endl;
            }
        }
        cout<<"C>A>B"<<endl;
    }
    else if (B>C)
    {
        if (A>C)
        {
            cout<<"B>A>C"<<endl;
        }
        else
        {
            cout<<"B>C>A"<<endl;
        }
    }
    else 
    {
        cout<<"C>B>A"<<endl;
    }

    return 0;
}

// Firsrt analysis the mathematical model. Three number for comparsion, there are total 2*3 =6 results. 