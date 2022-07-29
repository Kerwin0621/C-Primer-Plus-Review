#include<iostream>
#include<string>
#include<time.h>

using namespace std;

struct Student
{
    /* data */
    string name;
    int score;
};


struct Teacher
{
    /* data */
    string name;
    // Create Student instance
    Student stuArray[5];
};

// Assign info function
void allocateSpace(struct Teacher teArray[], int len)
{
    string nameSeed = "ABCDE";


    for (int i=0; i<len; i++)
    {
        teArray[i].name = "Teacher_";
        teArray[i].name += nameSeed[i];

        // Assign info to students in each teacher
        for (int j=0; j<5; j++)
        {
            // Radnom number
            int stu_score = rand()% 101;
            teArray[i].stuArray[j].name = "Student_";
            teArray[i].stuArray[j].name += nameSeed[j];
            teArray[i].stuArray[j].score = stu_score;
        }
    }
}

void printInfo(struct Teacher teArray[], int len)
{
    for (int i=0; i<len; i++)
    {
        cout<<"Teacher name:   "<<teArray[i].name<<"\t"<<endl;
        for (int j=0; j<5; j++)
        {
            cout<<"\tTeacher Students Name:  "<<teArray[i].stuArray[j].name<<"\t"
                <<"Teacher Students Score:  "<<teArray[i].stuArray[j].score<<endl;
        }
    }
}

int main_stru_array()
{
    // Initialize random seed
    srand(time(NULL));
    // Create Teacher instance array
    Teacher teArray[3];
    // Assign info to three teachers and students by the defined functions
    int len = sizeof(teArray) / sizeof(teArray[0]);
    allocateSpace(teArray, len);

    //Print all the teachers and students info

    printInfo(teArray, len);
    return 0;
}