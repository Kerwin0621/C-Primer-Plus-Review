#include<iostream>
#include<string>

using namespace std;

// Hearo structure body
struct Hearo
{
    /* data */
    string name;
    int age;
    string gender;
};


void Bubble_sort(Hearo heArray[], int len)
{
    for (int i=0; i<len; i++)
    {
        for (int j=0; j<len-1-i; j++)
        {
            if (heArray[j].age>heArray[j+1].age)
            {
                int temp = heArray[j].age;
                heArray[j].age = heArray[j+1].age;
                heArray[j+1].age = temp;
            }
        }
    }
}

void printInfo(Hearo heroArray[], int len)
{
    for (int i=0; i<len; i++)
    {
        cout<<"Name:    "<<heroArray[i].name<<"\t"<<"Age:   "<<heroArray[i].age<<"\t"<<"Gender:     "<<heroArray[i].gender<<endl;
    }
}

int main()
{

    // Create Hearo array instance
    Hearo heroArray[5] = 
    {
        {"Jack", 18, "Male"},
        {"Ben", 21, "Male"},
        {"Tom", 15, "Male"},
        {"Li", 35, "Male"},
        {"Linda", 24, "Famale"},
    };

    int len = sizeof(heroArray) / sizeof(heroArray[0]);
    printInfo(heroArray, len);

    // Sort
    Bubble_sort(heroArray, len);
    cout<<"---------------------------------------------------"<<endl;
    printInfo(heroArray, len);

    return 0;
}