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
2. After access an object or a variable without releasing in time, which can cause some security problems

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



#### Static Members

static function in a class

Static members includes:

1. Static member variables

   All the object share the same dataset

   Allocating memory space in compiling stage

   Statement in the class, initializing out of the class

   ```c++
   class Person
   {
   public:
       // Statement in the class
       static int p_a;
   private:
       // Static member variable has the access authority as well
       static int p_b;
   }
   // initializing out of the class
   int Person::p_a = 100;
   int Person::p_b = 200;  // Wrong, we cannot access it
   void test02()
   {
       // Static member variable is not belong to a certain object, all the objects share the same dataset
       // Static member variable has two access methods
       //1. Access by the object 
       Person p;
       cout<<p.p_a<<endl;
       //2. Access by the calss name 
       cout<<Person::p_a<<endl;
   }
   ```

   

2. Static member functions

   All the object share the same function

   Static member function can only access static member variables

   ```c++
   class Person
   {
   public:
       static void func()
       {
           p_a = 100; // Correct, static function can access static variable
           p_b = 200; // Wrong, static function cannot access other variable
           cout<<"Static function test"<<endl;
       }
       static int p_a;
       int p_b;
   private:
       static void func2()
       {
           cout<<"Test"<<endl;
       }
   }
   int Person::p_a = 0;
   
   // Access
   void test01()
   {
       // 1. Access by object
       Person p;
       cout<<p.func()<<endl;
       // 2. Access by the class name
       cout<<Person::func()<<endl; 
       
       cout<<Person::func2()<<endl; // Wrong, private cannot be accessed
   }
   ```

   

#### Object Model

The member variable and member function are stored separately

Only non-static member variables are belong to the object of the class

```c++
class Person
{
    int p_a;
    
    static int p_b;
    void func(){}
    static void func2(){}
};
int Person::p_b = 0;
void test01()
{
    Person p;
    // Empty class memory space is: 1, C++ compiler will allocate 1 byte space, for distinguish the position of the objects in the memory space. 
    cout<<"size of p"<<sizeof(p)<<endl;
}

void test02()
{
    Person p;
    // One non-static member variables, mempory space is: 4, allocate memory according to the int
    cout<<"size of p"<<sizeof(p)<<endl;
    // One non-static member variables + One static mv, mempory space is: 4, as static mv is not belonging to the class
    cout<<"size of p"<<sizeof(p)<<endl;
    // One non-static member variables + One static mv + One member function, mempory space is: 4, as member funtion is not belonging to the class
    cout<<"size of p"<<sizeof(p)<<endl;
    // One non-static member variables + One static mv + One member function + One static member funtion, mempory space is: 4, as static member funtion is not belonging to the class
    cout<<"size of p"<<sizeof(p)<<endl;
}
```



#### This pointer

this pointer point to the object to which the called function belongs 

Usage:

1. When the formal parameters and member variable have the same name, we use 'this' to distinguish
2. In the class, when the non-static member function return the object itself, we use return *this

```c++
class Person
{
public:
    Person(int age)
    {
        // this pointer point to the object to which the called function belongs 
        this->age =  age;
    }
    // withou &, it will return a value, which is a new object, but with &, it is not new object.
    Person& PersonAddAge(Person &p)
    {
        this->age += p.age;
        // this point to p2, *this is the p2 itself
        return *this;
    }
    
    int age;
}

void test01()
{
    Person p1(18);
    cout<<p1.age<<endl;
}
void test02()
{
    Person p1(10);
    Person p2(10);
    // Chain programming
    p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);
    cout<<p2.age<<endl;
}
```



#### Empty pointer to call the member function

The empty pointer can call the member function as well, but we should also notice whether 'this' pointer is used or not

```c++
class Person
{
public:
    void showClassName()
    {
        cout<<"This is Person Class"<<endl;
    }
    void showPersonAge()
    {
        // Wrong, since the imported pointer is NULL, to avoid that, we add a discriminant
        if (this == NULL)
        {
            return;
        }
        cout<<"age="<<age<<endl;
    }
    int p_a;
}

void test01()
{
    Person *p = NULL;
    p->showClassName();
    p->showPersonAge();
}
```



#### const decorate member function

**const function**

1. member function + const decorate

2. We cannot modify member attribute in the const function

3. But is wen add mutable when disclaimer the attribute of the member, we can modify the attributes

   ```c++
   class Person 
   {
   public:
       // Once we add const, the 
       void showPerson() const // this is equal to const Person *const this
       {
           // Once we add const, this statement is wrong, as 'this' pointer is a const pointer, the ditection cannot be chagned, but the value of the pointing can be changed.
           this->p_a = 100;
           this->p_b = 100;
       }
       void func(){};
       int p_a;
       // But is we add mutable, we can modify the value in the const member function
       mutable int p_b;
   }

**const object**

1. disclaimer the object + const

2. const object can only call the const function

   ```c++
   void test02()
   {
       const Person p; // add const change to const object
       p.p_a = 100; //wrong, we cannot change the value in const object
       p.p_b = 100; // correct, as p_b defined with mutable
       
       // const object can only call the const function
       p.showPerson();
       p.func(); // wrong, const object cannot access the general member function, as general member function can change the attributes 
   }
   ```

   

### Friend

In the program, sometime we want to use a technique to achieve a special function or class to access the private attribute, this technique is named Friend.

Friend three achievements:

1. Global function as friend

   ```c++
   class Builing
   {
   fridend void good_fri(Building *building);
   public:
       Building()
       {
           m_SittingRoom = "Living Room";
           m_BedRoom = "Bed Room";
       }
   public:
       string m_SittingRoom;
   private:
       string m_BedRoom;
   }
   
   // Global Function
   void good_fri(Building *building)
   {
       cout<<"GOOD friend visiting the:"<<building->m_SittingRoom<<endl;
       cout<<"GOOD friend visiting the:"<<building->m_BedRoom<<endl;
   }
   
   void test01()
   {
       Building building;
       good_fri(&building);
   }
   ```

2. Class as friend

   ```c++
   class Builing
   {
   public:
       Building();
   public:
       string m_SittingRoom;
   private:
       string m_BedRoom;
   };
   // Function statement out of the class
   Building::Building()
   {
       m_SittingRoom = "Living Room";
       m_BedRoom = "Bed Room";
   }
   
   class Good_fri
   {
   public:
       Good_fri();
       void visit();   // Visit functon to call the attributes of the Builidng class
       Building *building;
   };
   Good_fri::Good_fri()
   {
       // Create building object
       m_building = new Building;
   }
   Good_fri::visit()
   {
       cout<<"Good friend are calling:"<<building->m_SittingRoom<<endl;
       cout<<"Good friend are calling:"<<building->m_BedRoom<<endl;
   }
   
   void test01()
   {
       Good_fri gg;
       gg.visit();
   }
   ```

   

3. Member function as friend

   ```c++
   class Building;
   class Good_fri
   {
   public:
       good_fri(); // Constructor - to initialize the status.
       void visit();
       void visit2();
   private:
       Building *building
   };
   
   class Building
   {
   fridend void Good_gri::visit();
   public:
       Building();
   public:
       string m_SittingRoom;
   private:
       string m_BedRoom;
   }
   
   Building::Building()
   {
       this->m_SittingRoom = "Living Room";
       this->m_BedRoom = "Bed Room";
   }
   
   Good_fri::good_fri()
   {
       building = new Building; // Need to check the usage of 'new'
   }
   
   void Good_fri::visit()
   {
       cout<<"Good friend visiting:"<<building->m_SittingRoom<<endl;
       cout<<"Good friend visiting:"<<building->m_BedRoom<<endl;
   }
   
   void Good_fri::visit2()
   {
       cout<<"Good friend visiting:"<<building->m_SittingRoom<<endl;
       //cout<<"Good friend visiting:"<<building->m_BedRoom<<endl;
   }
   
   void test01()
   {
       Good_fri gg;
       gg.visit();
       gg.visit2();
   }
   ```

   

### Operator Overload

#### + operator overload

1. Using member function to overload +

   ```c++
   class Person
   {
   public:
       // 1. Using member function to overload +
       Person operator+(Person &p)
       {
           Person temp;
           temp.m_A = this->m_A + p.m_A;
           temp.m_B = this->m_B + p.m_B;
           return temp;
       }
       int m_A;
       int m_B;
   };
   
   
   // Function overload
   Person operator+(Person &p1, int num)
   {
       Person temp;
       temp.m_A = p1.m_A + num;
       temp.m_B = p1.m_B + num;
       return temp;
   }
   
   void test01()
   {
       Person p1;
       p1.m_A = 10;
       p1.m_B = 10;
       Person p2;
       p2.m_A = 10;
       p2.m_B = 10;
       
       Person p3 = p1 + p2; // 1. Person p3 = p1.operator+(p2)	   | 2. Person p3 = operator+(p1,p2)
       
       // Function overload
       Person p4 = p1 + 100;
   }
   ```

2. Using global function to overload + 

   ```c++
   Person operator+(Person &p1, Person &p2)
   {
       Person temp;
       temp.m_A = p1.m_A + p2.m_A;
       temp.m_B = p1.m_B + p2.m_B;
       return temp;
   }
   ```



#### Shifting Operator

**Left Shifting Operator**

Usage: output the self-defined type of data

```c++
class Person
{
friend: ostream & operator<<(ostream &cout, Person &p);
public:
    Person(int a, int b)
    {
        m_A = a;
        m_B = b;
    }
private:
    // Generally it is not recommend using Member functon to overload, p.operator<<(cout), in the result the cout would be in RHS.
    int m_A;
    int m_B;
};

// Using global function to overload left shifting operator
ostream & operator<<(ostream &cout, Person &p) // The reason for using citation is that it is not necessary to create a new parameters, only one parameter in this program
{
    cout<<"m_A="<<p.m_A<<"m_B="<<p.m_B;
    return cout
}

void test01()
{
    Person p(10,10);
    //p.m_A = 10;
    //p.m_B = 10;
    cout<<p<<endl; // chain programming logic
}
```



#### Increment Operator Overload

Usage: Achieve int data type by overload increment operator

```c++
class MyInteger
{
fridend: ostream & operator<<(ostream &cout, MyInteger myint);    
public:
    MyInteger(){
        m_Num = 0;
    }
    // Overload Pre-increment
    MyInteger & operator++() // The reason of using citation is to operatre on one target
    {
    	// Plus first
        m_NUm++;
        // Then return the value
        return *this;
    }
    // Overload Post-increment
    MyInteger & operator++(int) // int is a Placeholder parameter for distinguishing the pre and post
    {
        // Record the result first
        MyInteger temp = *this;
        // Then plus 1
        m_Num++
        // Return the record result
        return temp;
    }
    
private:
    int m_Num;
};
// Overload left shifting operator
ostream & operator<<(ostream &cout, MyInteger myint)
{
    cout<<myint.m_Num;
    return cout;
}

void test01()
{
    MyInteger myint;
    cout<<myint<<endl;  // We need overload <<
}

int main()
{
    test01()
}
```



#### Assignment operator overload

C++ compiler will add four function at least for a class:

1. Default constructor function (no parameters, empty statement)
2. Default destructor function (no parameters, empty statement)
3. Default copy constructor function to perform value copy
4. Assign operator = to perform value copy

If the attribute in the class points to the heap are, then the assigning operation will face the deep and shallow copy problems

```c++
class Person
{
public:
    // Constructor to initlize value
    Person(int age)
    {
        // Create age data in heap area
        m_Age = new int(age);
    }
    // Operator = overload
    Person & operator=(Person &p)
    {
        // Cheack the pointer release
        if (m_Age != NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }
        // However, the defalut '=' is shallow copy, if the user release the heap area data, it will be released twice can cause error. Thus, we need to provide deep copy
        m_Age = p.m_Age;
        
        // Deep copy, by using pointer for address description and use new to create in heap area.
        m_Age = new int(*p.m_Age);
        
        return *this;   // We don't want to create new variable in terms of memory address       
    }
    
    // Destructor to release the data in heap area
    ~Person()
    {
        if (m_Age != NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }
    }
    // Age pointer (Why using pointer?)
    int *m_Age;
    
};

// Target we want is to equalize two Person instance, thus we need overload the operator =
void test01()
{
    Person p1(10);
    Person p2;
    p2 = p1;
    
    // But if we want to use continous '='
    Person p3;
    p3 = p2 = p1;  // We need to check the return data type
}
```

#### Relational operator overloading

Usage: Compare two self-defined objects

```c++
class Person
{
public:
    Person(string name, int age)
    {
        m_Nae = name;
        m_Age = age;
    }
    // Overload '=='
    void operator==(Person &p)
    {
        if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
        {
            return true;
        }
        return false;
    }
    // Overload '!='
    void operator!=(Person &p)
    {
        if (this->m_Name != p.m_Name || this->m_Age != p.m_Age)
        {
            return true;
        }
        return false;
    }
    string m_Name;
    int m_Age;
};

void test01()
{
    Person p1("Tom", 18);
    Person p2("Tom", 18);
    
    if (p1 == p2)
    {
        cout<<"P1 = P2"<<endl;
    }
    else
    {
        cout<<"P1 not = P2"<<endl;
    }
    
    if (p1 != p2)
    {
        cout<<"P1 not = P2"<<endl;
    }
}
```

#### Function call operator overloading

Also called functors

```c++
class MyPrint
{
public:
    // Function call operator overloading
    void operator()(string test)
    {
        cout<<test<<endl;
    }
};
void MyPrint02()
{
    MyPring myPrint;
    myPring("hello world"); // Functor
    MyPring02("hello world");
}

void test01()
{
    MyPring myPring;
    myPrint("hello world");
}

class MyAdd
{
public:
    int operator()(int num1, int num2)
    {
        return num1 + num2;
    }
}

void test02()
{
    MyAdd myadd;
    int ret = myadd(100, 100);
    cout<<"ret="<<ret<<endl;
    // Anonymous object
    cout<<MyAdd()(100,100)<<endl;
}
```



### Inheritance

Usage: Decreasing the repeated code

Grammar: class sub_class : inheritance_approach Father_class

Sub_class also named as Derived class

Father class also named as Base class



#### Inheritance_approach

Three approaches:

<img src="../Downloads/C++_Inheritance.webp" alt="C++_Inheritance" style="zoom:50%;" />

For quick understanding, we can regard that the inheritance approaches are describing the sub-class data type not from the base class approach.

1. Public inheritance

   ```c++
   // Base class
   class Base1
   {
    public:
       int m_A;
   protected:
       int m_B;
   private:
       int m_C;
   };
   
   // Derived class
   class Son1:public Base1
   {
   public:
       void func()
       {
           m_A = 10; // Public authority member can be accessed
           m_B = 10; // Protected authority member is sitll protected in derived class
           m_C = 10; // Wrong ! Proviate member cannot be accessed
       }
   }
   
   void test01()
   {
       Son1 s1;
       s1.m_A = 100;
       s1.m_B = 100; // Wrong! Protected can not be accessed when out of the class
   }
   ```

2. Protect inheritance

   ```c++
   // Base class
   class Base2
   {
    public:
       int m_A;
   protected:
       int m_B;
   private:
       int m_C;
   };
   
   // Derived class
   class Son2:protected Base2
   {
   public:
       void func()
       {
           m_A = 100; // Changed to protected in sub_class
           m_B = 100; // Changed to protected in sub_class
           m_C = 100; // Wrong! Private member cannot be accessed
       }
   };
   
   void test02()
   {
       Son2 s2;
       s2.m_A = 100; // Wrong! In Son2, m_A changed to protected authority, thus cannot be accessed when out of the class
   }

3. Private inheritance

   ```c++
   // Base class
   class Base3
   {
    public:
       int m_A;
   protected:
       int m_B;
   private:
       int m_C;
   };
   
   // Derived class
   class Son3:private Base3
   {
   public:
       void func()
       {
           m_A = 100; // Changed to privated in sub_class
           m_B = 100; // Changed to privated in sub_class
           m_C = 100; // Wrong! Private member cannot be accessed
       }
   };
   
   void test03()
   {
       Son3 s3;
       s3.m_A = 100; // Wrong, m_A changed to privated in Son3
   }
   ```

#### Object Model in Inheritance

The members inherited from the Base class, which of them belongs to sub_class objects?

```c++
// Base class
class Base
{
 public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

class Son:public Base
{
public:
    int m_D;
}

void test01()
{
    cout<<"size of Son"<<sizeof(Son)<<endl; // The answer is 16, int(A+B+C+D)
    /* Conclusion:
       1. All the non-static member attribute will be inherited by Son class
       2. The private member attribute is inherited as well, but it is hided, thus we cannot access*/   
}
// Check the inheritance in terminal
By moving to the current route
c1 /d1 reportSingleClassLayoutSon "xxx.cpp"
```

#### The sequence of (con/de) structor in inheritance

After the Son class inherit Base class, when create object in Son class, it will call the structor function in Base class

```c++
class Base
{
public:
  Base()
  {
      cout<<"Base constructor "<<end;''
  }
  ~Base()
  {
      cout<<"Base destructor "<<endl;
  }    
};

class Son:public Base
{
public:
  Son()
  {
      cout<<"Son constructor "<<end;''
  }
  ~Son()
  {
      cout<<"Son destructor "<<endl;
  }        
};

void test01()
{
    Son s1;
}

/* Results:
	1. Base constructor
	2. Son constructor
	3. Son destructor
	4. Base destructor
*/
```

#### Members with the same name in inheritance

If the Son class and the Base class has the member with the same name?

1. Access the same name member in Son class, just do it
2. Access the same name member in Base class, add the scope

```c++
class Base
{
public:
    Base()
    {
        m_A = 100;
    }
    
    void func()
    {
        cout<<"Base-func() calling"<<endl;
    }
    // If, another function
    void func(int a)
    {
        cout<<"Base-func(int a) calling"<<endl;
    }
    
    int m_A;
};

class Son:public Base
{
public:
    Son()
    {
        m_A = 200;
    }
    void func()
    {
        cout<<"Son-func() calling"<<endl;
    }
    int m_A;
}

void test01()
{
    Son s1;
    cout<<s1.m_A<<endl;  // Just do it
    cout<<s1.Base::m_A<<endl;
}

void test02()
{
    Son s2;
    s2.func(); // Just do it - Son class function
    s2.Base::func();
    s2.func(100); // Wrong! If the member function in Son class has the same name with its Base class, that member function will hite all the function with the same name in the Base class
    s2.Bash::func(100); // Correct
}
```

#### Static member in inheritance

If the static member has the same name with the non-static member:

1. Access the same name member in Son class, just do it
2. Access the same name member in Base class, add the scope

```c++
class Base
{
public:
    static int m_A;  
    static void func();
};
int Base::m_A = 100;
void Base::func()
{
    cout<<"Base - func"<<endl;
}

class Son:public Base
{
public:
    static int m_A;
    static void func();
};
int Son::m_A = 200;
void Son::func()
{
    cout<<"Son - func"<<endl;
}

// Static member attribute with the same name
void test01()
{
    // Access by object
    Son s;
    cout<<"Son m_A"<<s.m_A<<endl;
    cout<<"Base m_A"<<s.Base::m_A<<endl;
    // Access by class name
    cout<<"Son m_A"<<Son::m_A<<endl;
    cout<<"Base m_A"<<Son::Base::m_A<<endl;
    // The first colon is accessing by class name, the 2nd colon is the scope of the Base class
}

void test02()
{
    // Access by object
    Son s;
    s.func();
    s.Base::func();
    // Access by class name
    Son::func();
    Son::Base::func();
    // If the static member function in Son class has the same name with its Base class, that member function will hite all the function with the same name in the Base class
}
```

#### Multi-inheritance grammar

class Son_class : Inherit_approach Base 1, Inherit_approach Base 2

Multi-inheritance can cause same name members, we need to add scope to distinguish

IT IS NOT RECOMMENDED !!!

```c++
class Base1
{
public:
    int m_A;  
};
class Base2
{
public:
    int m_A;  
};
class Son::public Base1, public Base2
{
    
}
```

#### Diamond Inheritance

Concepts:

1. Two derived class inherit the same Base class
2. A new class inherit those two derived class 

```c++
class Animal
{
public:
    int m_Age;
};
// Adopt virtual inheritance can solve it

class Sheep:virtual public Animal
{
    
};
class Camel:virtual public Animal
{
    
};
class Alpaca:public Sheep, public Camel
{
    
};

void test01()
{
    Alpaca a;
    a.Sheep::m_Age = 10;
    a.Alpaca::m_Age = 10;
    a.m_Age;
    // But only one piece of data is enough
    
}
```



### Polymorphism

#### Basic Grammar

Two types of polymorphism:

1. Static polymorphism: function overload and operator overload are static polymorphism, function name reuse
2. Dynamic polymorphism: Derived class and virtual function

The difference between the static and dynamic polymorphism:

1. Function address in static polymorphism binding early - determine the function address when compiling
2. Function address in dynamic polymorphism binding later - determine the function address when running

Polymorphism conditions:

1. Inheritance relationship
2. Derived class re-write the virtual function in Base class

How to use:

1. Using the pointer or citation in Base class to execute Derived class

```c++
class Animal
{
public:
    // If we add virtual, it changed to dynamic polymorphism, the function addree is binding later
    virtual void speak()
    {
        cout<<"Animal speaking"<<endl;
    }
};
class Cat:public Animal
{
public:
    void speak()
    {
        cout<<"Miao"<<endl;
    }
};

// Function for speaking
void doSpeak(Animal &animal)
{
    animal.speak();
}
void test01()
{
    Cat cat;
    doSpeak(cat); // The result is "Animal speaking", because the is static polymorphism, the function address is binding early. 
}
```

#### Basic Concepts

```c++
class Animal
{
public:
    virtual void speak()
    {
        cout<<"Animal speaking"<<endl;
    }
}

void test01()
{
    cout<<sizeof(Animal)<<endl; // The result will be 1
    cout<<sizeof(Animal)<<endl; // But if we add virtual function, the results will be 4, because it includes a vfptr, and this pointer will point to a vftable, this vftable include the address of the function, thus it is 4
};
```

The inner structure of Animal

vfptr: virtual function pointer

#### Pure virtual function

In polymorphism, generally the statement of the virtual function in Base class is meaningless, it is more important in Derived class

Therefore we can change the virtual function to Pure virtual function

Grammar: virtual return_type function_name (parameter list) = 0;

If a class has the Pure virtual function, this class is named abstract class

The characteristics of the Abstract class:

1. Can not be instance of object
2. The derived class must re-write the Pure virtual function, otherwise it is Abstract class as well.

```c++
class Base
{
public:
    virtual void func() = 0;
};
class Derived:public Base
{
public:
    virtual void func()
    {
        cout<<"Func calling"<<endl;
    };
};

void test01()
{
    Base *base = new Derived;
    base->func();
}
```

#### Virtual Destructor & Pure virtual Destructor

In polymorphism, if the attribute of the Derived class is created in heap area, when the pointer is released it cannot tough the Donstructor code in Derived class

Solutions: Change the constructor function in Base class as virtual Donstructor or pure vd

Identical points between VD and PVD:

1. Solve the pointer in Base class to release the objects in Derived class
2. Need detailed statement in functions

Difference:

1. If it is PVD, this class is Abstract class, cannot create instance object

```c++
class Animal
{
public:
    Animal()
    {
        cout<<"Animal constructor calling"<<endl;
    }
    // The pointer in Base class cannot tough the code in Derived class, thus we need VC
    virtual ~Animal() = 0;
    
};
Animal::~Animal()
{
    cout<,"Animal destructor calling"<<endl;
}

class Cat:public Animal
{
public:
    Cat(string name)
    {
        cout<<"Cat constructor calling"<<endl;
        m_Name = new string(name);
    }
    virtual void Speak()
    {
        cout<<*m_Name<<"Miao"<<endl;
    }
    ~Cat()
    {
        cout<<"Cat destrucotr calling"<<endl;
        if (this->m_NAME != Null)
        {
            delete m_Name;
            m_Name = NULL;
        }
    }
    string *m_Name; // Create data in heap area
}
void test01()
{
    Animal *animal = new Cat("Tom");
    animal -> Speak();
    delete animal;
}
```









## Reference

1. http://c.biancheng.net/cplus/
2. https://www.runoob.com/cplusplus/cpp-tutorial.html





happy