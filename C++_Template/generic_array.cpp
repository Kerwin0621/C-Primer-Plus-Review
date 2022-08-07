#include<iostream>
using namespace std;
#include "MyArray.hpp"
/*
The reuqirements of the generic array:
    1. It can store the build-in data types and the self-defiend data types
    2. It can siave the data in heap area
    3. In its constructor, user can transfer the capacity of the array
    4. Providing its copy-consturctor and operator= to avoid the shallow copy issue
    5. Providing the tail interpolation or tail delete to add or remove elements
    6. Providing the access method for elements by index
    7. It can display thr elements number and the capacity of the array*/

void printIntArray(MyArray<int> &arr)
{
    for (int i=0; i<arr.getSize(); i++)
    {
        cout<<arr[i]<<endl;
    }
}



void test01()
{
    MyArray<int>arr1(5);
    for (int i=0; i<5; i++)
    {
        arr1.Push_back(i);
    }
    //cout<<"Array print"<<endl;
    printIntArray(arr1);

    cout<<"Array Capacity \t"<<arr1.getCapacity()<<endl;
    cout<<"Array Size \t"<<arr1.getSize()<<endl;

    MyArray<int>arr2(arr1);
    cout<<"Array print"<<endl;
    printIntArray(arr2);
    arr2.Pop_back();
    cout<<"--------------"<<endl;
    printIntArray(arr2);
    cout<<"Array Capacity \t"<<arr2.getCapacity()<<endl;
    cout<<"Array Size \t"<<arr2.getSize()<<endl;


}



// Test on the self-defiend data type
class Person
{
public:
    Person(){};
    Person(string name, int age)
    {
        this->m_name = name;
        this->m_age = age;
    }
    string m_name;
    int m_age;
};

// Person data type print
void printPersonArray(MyArray<Person> &arr)
{
    for (int i=0; i<arr.getSize(); i++)
    {
        cout<<"Name \t"<<arr[i].m_name<<"Age \t"<<arr[i].m_age<<endl;
    }
}

void test02()
{
    MyArray<Person>arr(10);
    Person p1("A", 18);
    Person p2("B", 19);
    Person p3("C", 20);
    Person p4("D", 21);
    Person p5("E", 22);

    // Interpolation
    arr.Push_back(p1);
    arr.Push_back(p2);
    arr.Push_back(p3);
    arr.Push_back(p4);
    arr.Push_back(p5);

    // Print array
    printPersonArray(arr);

    // Print the capacity
    cout<<"Capacity is \t"<<arr.getCapacity()<<endl;
    cout<<"Size is \t"<<arr.getSize()<<endl;
}



int main()
{
    test02();
    return 0;
}