#include<iostream>
#include<string>

using namespace std;

// Student Class
class Student
{
    // Acess Authority
public:
    // Attribute
    string name;  // Name
    int ID;   // Student ID

    // Behavior     --1. Assign Name and ID     2. Display the Name and ID
    void assignNI()
    {
        cout<<"Please input the student name:";
        cin>>name;  
        cout<<endl;

        cout<<"Please input the student ID:";
        cin>>ID;
        cout<<endl;
    }

    void dispNI()
    {
        cout<<"The student name is:"<<name<<endl;
        cout<<"The student ID is:"<<ID<<endl;
    }

    // Define attribute by behavior
    void set_Name(string give_name)
    {
        name = give_name;
    }
    void set_ID(int give_ID)
    {
        ID = give_ID;
    }

};

int main()
{
    // Create a student instance
    Student s1;

    // Assign name and ID
    // s1.name = "Jack";
    // s1.ID = 10;
    s1.assignNI();

    // Display the name and ID
    s1.dispNI();

    return 0;
} 