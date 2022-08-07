// Generic Array
#pragma once
#include <iostream>
using namespace std;


template<class T>
class MyArray
{
public:
    // Constructor with parameters
    MyArray(int capacity)
    {
        this->m_capacity = capacity;
        this->m_size = 0;
        this->pAddress = new T[this->m_capacity];
    }


    // Copy constructor
    MyArray(const MyArray &arr)
    {
        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;
        // Deep copy
        this->pAddress = new T[arr.m_capacity];

        // Copy the arr data
        for (int i=0; i<this->m_size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
    }
    // Operator= to avoid the shallow copy problem a = b = c
    MyArray & operator=(const MyArray &arr)
    {
        // Discriment the original heap area has data or not, if has then release thme
        if (this->pAddress != NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
            this->m_capacity = 0;
            this->m_size = 0;
        }

        // Deep copy
        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;
        this->pAddress = new T[arr.m_capacity];
        for (int i = 0; i< this->m_size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
    }

    // Tail interpolation
    void Push_back(const T &value)
    {
        // Determine the capacity is full or not
        if (this->m_capacity == this->m_size)
        {
            cout<<"The Array is full!!!"<<endl;
            return;
        }
        // If it is not full, add at tail 
        this->pAddress[this->m_size] = value;
        // After add an new element, the size of the Array is updated.
        this->m_size++;
    }
    
    // Tail delete
    void Pop_back()
    {
        // Let the user cannot access the last elemen
        if (this->m_size==0)
        {
            return;
        }
        this->m_size--;
    }

    // Using index to accsss number
    T &operator[](int index)
    {
        return this->pAddress[index];
    }

    // Return the array capacity
    int getCapacity()
    {
        return this->m_capacity;
    }
    // Return Array size
    int getSize()
    {
        return this->m_size;
    }


    // Destructor
    ~MyArray()
    {
        if (this->pAddress != NULL)
        {
            delete[] this->pAddress; // add [] as the target is an array
            this->pAddress = NULL;
        }
    }

private:
    T *pAddress; // Pointer to the real array developed in the heap area
    int m_capacity; // Array capacity
    int m_size;
};