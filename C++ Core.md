# C++ Core



## Memory Model

### Memory Partition Model

When the C++ program is compiling, it will divide the memory into four partitions

1. Coding area: Save the binary code of the functions, managed by operation system
2. Global zone: Save the global variables, static variables and constants
3. Stack area: Automatically allocated and released by the compiler
4. Heap area: Allocated and released by the user, or it will be retrieved by the operation system if the user didn't release it



#### Before the program is running

After the program is compiled, it will become an exe. executable program, before the execution, it is divided into two area

**Coding area**:

1.  Storage the machine inductions executed by CPU
2. The coding area is shared, especially for the program executed frequently, only once piece of code in the memory is fine
3. The coding area is read-only, which is to prevent any accident that modifying its inductions

**Global zone**:

1. Global variables and static variables are storage here
2. Global zone also includes the constant area, string constant and other constant are saved here as well
3. After finishing the programming, the data in this area is released by the operation system

```c++
#include<iostream>
using namespace std;

// Global variables
int glo_a = 10;

// Constant decorate global variable
const int c_g_a = 10;

int main()
{
    // Create local variables
    int a = 10;
    
    // Create static variables
    static int s_a = 10;
    
    // Constant
    // String constant
    cout<< "String const address"<<(int)&"hello world"<<endl;
    // Constant decorate
    // COnstant decorate local variable
    const int c_l_a = 10;
    
    // Check the addres distance betwee the global and local variables
    cout<<(int)&a<<endl;
    cout<<(int)&glo_a<<endl;
}
```

**Summary**

1. Before the execution, C++ are divided into global area and coding area
2. The characters of coding area is shared and read-only
3. The global area includes global variables, static variables and constant
4. The constant area includes global constant and string constant which decorated by const 



#### After the program is executed

**Stack Area**

1. Allocated and released by the compiler, save the parameter value of the function and local variables
2. Don't return the address of local variables, the data developed by the stack area will be released by the compiler

```c++
int *func()
{
    int a = 10; // Local variable, saved in stack area, released automatically by compiler after execution
    return &a; // Return the Local variabel address
}

int main()
{
    int *p = func();
    cout<*p<<endl; //In the first time it can print the correct num, as the compiler save only once
    cout<<*p<<endl; // When second time calling, it is no longer saved 
}
```

**Heap Area**

1. Allocated and released by the user, or it will be retrieved by the operation system if the user didn't release it
2. In C++, generally using new to develop memory

```c++
int *func()
{
  	// Using new keyword, we ncan develop the data into heap area
    int *p = new int (10); // Pointer is local variable as well,located in stack, the data stored by pointer is put in the heap area
    return p;
}

int main()
{
    int *p = func();
    cout<<*p<<endl;
    return 0;
}
```

#### New symbol

Usage: Using new to develop data in heap area.

​			Data in heap area is developed and released by users, when deleting, using symbol "delete"

​			Data created by new, returns the pointer with corresponding data type

Grammar: new data type

 ```c++
 int *func()
 {
     int *p = new int(10);
     return p;
 }
 
 void test01()
 {
     int *p = func();
     cout<<*p<<endl;
     // To release the memory
     delete p;
 }
 
 // Develop array in heap area
 void test02()
 {
     int *arr = new int[10];
     
     for (int i=0; i<10; i++)
     {
         arr[i] = i+10;
     }
     
     for (int i=0; i<10;i++)
     {
         cout<<arr[i]<<endl;
     }
     //Release array in heap area
     delete[] arr;
 }
 
 int main()
 {
     test01();
     test02();
     return 0; 
 }
 ```







## Citation

Usage: Giving the variables another names

Grammar: datatype &new_name = original_name

```c++
#include<iostream>
using namespace std;
int main()
{
    // Define a variable
    int a = 10;
    // Pointer 
    int *p = &a;
    // Citation
    int &b = a;
	// Pring the address, three results are the same
    cout<<&a<<endl;
    cout<<p<<endl; 
    cout<<&b<<endl;

    return 0;
} 
```

**Note**

1. Citation must be initialized
2. After the initialization, the citation is no longer being changed



### Citation as function parameters

Usage: When transferring parameters in functions, we can use citation to  decorate actual parameters by formal parameters.

Benefits: Simplify the pointer for decorating the actual parameters

```c++
void mySwap03(int &a, int &b)
{
    int temp = a;
    a = b;
    b = a;
}

int main()
{
    int a = 10;
    int b = 20;
    
    mySwap03(a,b);  // Foraml p will changed the actual p
    return 0;
}
```



### Citation as function returns

Usage: Citation can be the return value of the functions

Note: Don't return the local variable citation

```c++
int& test01()
{
    int a = 10; // Local variable is stored in the stack area
    return a;
}

// Calling function can be the left value 
int& test02()
{
    static int a = 10; // Static variable, stored in the global area, released by the operation system after code is compiled
    return a;
}

int main()
{
    int &ref = test01();
    
    // test02 case
    test02() = 100; // If the return of a function is a citation, the calling of funciton can be the left value
    
    return 0;
}
```

### Nature of Citation

The nature of Citation in C++ is a pointer constant

```C++
void func(int& ref)
{
    ref = 100;  //  *ref = 100
}

int main()
{
    int a = 10;
    int& ref = a; // Automaticly transferred to int* const ref= &a; The direction of Pointer const cannot be changed, thus the citation cannot be changed in address.
    ref = 20;
    
    
    
}
```

### Const Citation

Usage: Const Citation is designed to decorate formal parameters, to avoid any wrong operations

​			In function formal parameter list, we can add const to decorate formal parameters, to avoid the formal parameters changing actual parameters

```c++
void showValue(const int& val)
{
	cout<<val<<endl;
}
```





## Advanced Function

### Function default parameters

In C++, the formal parameters of the function can be a default value

Grammar: Return_type Function_name (parameter = default_value) {}

```c++
int func(int a, int b, int c = 10)
{
    return a+b+c; 
}
// If some position has the default parameters, then the foramal parameters are supposed to have the default value after that position
// If the call of the function has default parameters, the parameters in statement of the function can not be changed
int main()
{
    int a = 10;
    int b = 10;
    cout<<func(a, b, 10)<<endl;
    return 0;
}
```



### Function placeholder arguments

In C++, the formal parameter list can have placeholder parameters, when calling the function, it is supposed to define that place

Grammar: Return_datatype Function_name (datatype) {}



### Function Overloading

Usage: The name of functions can be the same, increasing the re-use times

Conditions:

1. They are in the same scope
2. The name of those functions are the same
3. The parameters can be different in data_type, numbers, sequences between functions

Note: The return value of the function can not be the condition for function overloading

```c++
void func()
{
    cout<<"Test"<<endl;
}
void func(int a) // Parameters number different
{
    cout<<"Test02"<<endl;
}
```

### Note

```c++
void func(int& a)
{
    cout<<"Test1"<<endl;
}
void func(const int&a)
{
    cout<<"Test2"<<endl;
}
// Parameters types different

// When the function overloading with default parameters
void func2(int a, int b = 10)
{
    cout<<"Test3"<<endl;
}

void func2(int a)
{
    cout<<"Test3"<<endl;
}


int main()
{
    int a = 10;
    func(a);  // This will use the first function
    func(10); // This will use the second function as int& a is illegal. 
    func2(10); // This is wrong, both func2 can work. We should avoid
    
    return 0;
}
```





## Class and Object

Three characterizes in C++ Class and Object: Encapsulation, Inheritance, Polymorphism

### Encapsulation

Usage: 

1. Integrate the attribute and behavior to describe the objects
2. Limiting the authority of the attribute and behavior 

Grammar: class class_name{access_authority: attribute / behavior};

```c++
// PI
const double PI = 3.14;

// Design a Circle class to calculate the perimeter
// Formula: 2*pi*r
class Circle
{
    // Access authority
public:	// Public authority
    
    // Attribute   - Radius
    int m_r;
    
    // Behavior	   - Calculate the perimeter
    double calculateZC()
    {
        return 2*PI*r;
    }
}

int main()
{
    // Create a circle instance
    Circle c1;
    // Assign value
    c1.m_r = 10;
    cout<<"Circle Perimeter"<<c1.calculateZC()<<endl;
    return 0;
}
```

**Note**

Attribute and Behavior are named members in a Class



**Usage 2**

Limiting the authority of the attribute and behavior 

Three types of authority:

1. Public			- both inner and outer class can access  
2. Protected     - Only inner class can access
3. Private          - Only inner class can access

```c++
class Person
{
public:
    // Public
    string name;
protected:
    // Protected
    string car;
private:
    // Private
    int password;
 
public:
    void func()
    {
        name = "Jack";
        string = "Audi";
        password = 123;
    }
}

int main()
{
    // Instance
    Person p1;
    p1.name = "Tom"; // Correct, we can change
    p1.car = "Benze"; // Wrong, only inner class can change
    p1.password = 124; // Wrong, only inner class can change
    return 0;
}
```



#### Difference between struct and class

The only difference is the access authority

1. struct access authority is public as default
2. class access authority is private as default

```c++
class C1
{
    int a; // default as private
}
struct C2
{
    int a; // default as public
}

```



#### Private member attribute

Usage:

1. By setting private member attribute, the user can control the read and write authority
2. For the write authority, we can check dataset is working or not

```c++
class Person
{
public:
    // give the nmae
    void give_name(string name)
    {
        p_name = name;
    }
    // get the name
    void get_name()
    {
        return p_name;
    }
private:
    // Name	-- read & write
    string p_name;
    // Age 	-- read only
    int p_age;
    // Partner	-- write only
    int p_partner;
} 
```



### Object Feature

#### Constructor & Destructor

The initialization and cleaning of the object are two significant problems:

1. An object or a variable without initial status, the result of using it is unknown
2. After calling an object or a variable without releasing in time, which can cause some security problems

To solve that, C++ provides Constructor & Destructor to initialize and clean work. The initialization and cleaning of objects are the processed in force, if the user doesn't provide C & D, the compiler will do it but with NULL achieve.

**Constructor**

Usage: Giving the initial value when creating object and members, it is compiled by the compiler automatically

Grammar: class_name () {}

1. Constructor has no return value and no void
2. The name of function is the same as the class name
3. Constructor can have overload since it can have parameters
4. Compiler will call it automatically and only work once



**Destructor**

Usage: Processing the information cleaning work, it is called before the object deleted by the system automatically

Grammar: ~class_name () {}

1. Destructor has no return value and not void
2. The name of the function is the same as the class name and plus ~
3. Destructor can not overload since it can not have parameters
4. Compiler will call it automatically and only work once

```c++
class Person
{
public:
    // Constructor
    Person()
    {
        cout<<" The calling of the constructor"<<endl;
    }
    // Destructor
    `Person()
    {
        cout<<"The calling of the descructor"<<endl;
    }
}
```





#### Category and call of the constructor

Two categories:

1. Based on the parameters: Args constructor & No-args constructor

   ```c++
   class Person
   {
   public:
       Person()
       {
           cout<<"No-args constructor"<<endl;
       }
       Person(int a)
       {
           cout<<"Args constructor"<<endl;
       }
   }
   ```

   

2. Based on the types: General constructor & Copy constructor

   ```c++
   class Person
   {
   public:
       Person(const Person &p)			// Citation used in calling
       {
           age = p.age;
           cout<<"Copy constructor"<<endl;
       }
   private:
       int age;
   }
   ```

   

Three call methods:

1. Bracket method

   ```c++
   int main()
   {
       Person p1;	//Default constructor call
       Person p2(10); // Args C call
       Person p3(p2); // Copy C call
       // Note: when calling the default constructor, do not add () bracket. This can confuse the compilier as it thought this would be a declaration of a function
       Person p1();
       return 0;
   }
   ```

2. Display method

   ```c++
   int main()
   {
       Person p1;	
       Person p2 = Person(10);	// Args C
       Person p3 = Person(p2);	// Copy C
       Person(10); // Anonymous object, after the compiling, the system will collect it automatically
       // Note: Do not use the copy C to initialize the anonymous object, since comiplier will think Person (p3) = Person p3 which is creating a instance
       Person (p3);
       return 0;
   }
   ```

3. Implicit conversion

   ```c++
   int main()
   {
       Person p4 = 10;
       Person p5 = p4;
       return 0;
   }
   ```

   

#### Copy constructor timing

Three situation we can use copy C:

1. Initializing a new object by a well-created object
2. Transferring value to the function parameters based on the value transferring
3. Return to the local object as value

```c++
class Person
{
public:
    Person()
    {
        cout<<"Constructor"<<endl;
    }
    
    Person(int age)
    {
        m_age = age;
        cout<<"Args C"<<endl;
    }
    
    Person(const Person &p)
    {
        m_age = p.age;
        cout<<"Copy C"<<endl;
    }
    ~Person()
    {
        cout<<"Destructor"<<endl;
    }
private:
    int m_age;
}

// 1. Initializing a new object by a well-created object
void test01()
{
    Person p1(20);
    Person p2(p1);
}

// 2. Transferring value to the function parameters based on the value transferring
void doWork()
{
    
}

void test02()
{
    Person p;
    doWork(p;)
}

// 3. Return to the local object as value
Person doWork2()
{
    Person p1;
    cout<<(int*)&p1<<endl;
    return p1;
}
void test03()
{
    Person p = doWork2();
    cout<<(int*)&p<<endl;
}
```

#### Rules of Constructor

Generally, C++ compiler has three functions for a class at least:

1. Default constructor (no parameters, NULL statement)
2. Default destructor (no parameters, NULL statement)
3. Default copy constructor, to copy the attribute

Rules for calling the constructor:

1. If the user has defined the constructor, C++ will use the defined one, but provide the default copy constructor
2. If the user has defined the copy constructor, C++ will no longer provides any other constructors



#### Deep Copy & Shallow Copy

Deep copy: apply new space in heap area, then perform copy operation

Shallow copy: simple assign value copy operation

```c++
class Person
{
public:
    Person()
    {
        cout<<"No-args C"<<endl;
    }
    Person(int age, int *height)
    {
        p_age = age;
        p_height = new int(height);
        cout<<"Args C"<<endl;
    }
    Person(const Person &p)
    {
        p_age = p.p_age;
        p_height = p.p_height; // Generated by compiler, shallow copy
        // Deep copy
        p_height = new int(*p.p_height);	// Apply a new memory space in heap area
        cout<<"Copy C"<<endl;
    }
    
    ~Person()
    {
        if (m_height != NULL)
        {
            delete m_height;
            m_height = NULL;
        }
        cout<<"Destructor"<<endl;
    }
private:
    int p_age;
    int *p_height;
}
```

The problem of the shallow copy is: the memory space in heap are will be released in repeat. 

To solve it, we use deep copy.



#### Initialize list

Usage: Initialize the attribute

Grammar: constructor(): att1(val1), att2(val2)... {}

```c++
class Person
{
public:
    Person(int a, int b, int c)
    {
        p_a = a;
        p_b = b;
        p_c = c;
    }
    
    // Initialize list
    Person(int a, int b, int c): p_a(a), p_b(b), p_c(c){}
private:
    int p_a;
    int p_b;
    int p_c;
}
```



#### Class object as Class members

The member of a Class can be the object defined by another Class: Object-members

```c++
class Phone
{
public:
    Phone(string pho_name)
    {
        ph_name = pho_name;
    }
    
    string ph_name;
}

class Person
{
public:
    Person(string name, string phone): p_name(name), p_phone(phone)
   	string p_name;
    Phone p_phone;
}
```

Note: 

Construct: When the object (from Class A) is the member in Class B, when creating Class B, it will construct Class A object first then Class B. 

Destruct: The process is opposite with the construct, it will first destruct the Class B, then destruct Class A.



## File Operation



## Reference

1. http://c.biancheng.net/cplus/
2. https://www.runoob.com/cplusplus/cpp-tutorial.html





happy