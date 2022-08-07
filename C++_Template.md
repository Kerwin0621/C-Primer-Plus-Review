# Template

Templates are the foundation of generic programming, which is writing code in a way that is independent of any particular type.

## Conception

Template usage: Constructing the universal mould, increasing the code reusability

Template is a framework only, cannot be implemented directly



## Function Template

Usage: Constructing a generic function, the return type and formal parameters type cannot be determined, represented them by a virtual data type/

Grammar: 

```c++
template<typename T>
statement
```

template -- Declaration of creating template

Type name -- Indicating the symbol is a kind of data type, can be substituted by class

T -- generic data type, can be replaced by any Capital letters

```c++
template<typename T>
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

void test01()
{
    int a = 10;
    int b = 20;
    // 1. Automatical datatype interference
    mySwap(a, b);
    // 2. Display the specified data type
    mySwap<int>(a,b); 
}
```

NOTE: 'a' and 'b' can only be the same data type

```c++
template<class T>
void func()
{
    cout<<"func calling"<<endl;
}

void test02()
{
    func<int>();
}
```

### Difference between the general function and function template

1. General function calling can happen the automatic data type transfer (Implicit type conversion)
2. Function template calling, if adopting automatic data type transfer (not implicit type conversion happened)
3. If adopting display the specified type (implicit type conversion can happen)

```c++
// General function
int myAdd(int a, int b)
{
    return a+b;
}

template<class T>
T myAdd02(T a, T b)
{
    return a+b;
}


void test01()
{
    int a = 10;
    int b = 20;
    char c = 'c';
    cout<<myAdd(a, c)<<endl; 
    // Answer is 109 where 'c' = 99, general function will perform the implicit type conversion
    
    cout<<myAdd02(a,c)<<endl; // Wrong, ADP in templete cannot ITC
    cout<<myAdd02<int>(a,c)<<endl; // Correct
}
```

### Calling Rules

1. If the template and general function can achieve the same target, general function will be the priority
2. User can use empty template parameter list to mandatory call the function template
3. Function template can be overloaded
4. If the function template can create better matching, template will be the priority

```c++
void myPrint(int a, int b)
{
    cout<<"General function calling"<<endl;
}

template<typename T>
void myPrint(T a, T b)
{
    cout<<"Template calling"<<endl;
}

template<typename T>
void myPrint(T a, T b)
{
    cout<<"Overload Template calling"<<endl;
}

void test01()
{
    int a = 10;
    int b = 20;
    myPrint(a, b); // Rule 1, it will call the general function
    myPrint<>(a,b); // Rule 2, mandatory call the template
    myPrint(a,b,30); // Rule 3, template overload
    
    char c1 = 'a';
    char c2 = 'b';
    myPrint(c1, c2); // Rule 4, better matching, calling the template
}
```

### Limitation

```c++
class Person 
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    string m_Name;
    int m_Age;
};

// General function template
template<class T>
bool myCompare(T &a, T &b)
{
    if (a == b)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

// Reification template
template<> bool myCompare(Person &p1, Person &p2)
{
    if (p1.m_Name == p2.m_Name && p1.m_Age == p2.m_Age)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void test01()
{
    int a = 10;
    int b = 20;
    // Build-in data type can call the general function template
    bool ret = myCompare(a,b);
    if (ret)
    {
        cout<<"Equal"<<endl;
    }
    else
    {
        cout<<"Non-equal"<<endl;
    }
}

void test02()
{
    Person p1("Tom", 10);
    Person p2("Tom", 10);
    bool ret = myCompare(p1, p2);
    if (ret)
    {
        cout<<"Equal"<<endl;
    }
    else
    {
        cout<<"Non-equal"<<endl;
    }
}
```

## Class Template

Usage: Build a generic class, the data type of the member in this class cannot be determined, represented by a virtual class

Grammar:

```c++
template<typename T>
class
```

Example:

```c++
template<class NameType, class AgeType>
class Person
{
public:
    Person(NameType name, AgeType age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    void showPerson()
    {
        cout<<"Name"<<this->m_Name<<"Age"<<this->m_Age<<endl;
    }
    
    NameType = m_Name;
    AgeType = m_Age;
};

void test01()
{
    Person<string, int> p1("Tom", 18);
    p1.showPerson();
}
```

### Difference between the class template and function template

1. Class template does not have the automatic data type interference
2. Class template in parameter list can have the default parameters

```c++
template<class NameType, class AgeType = int> // Defulat parameter data type
class Person
{
public:
    Person(NameType name, AgeType age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    void showPerson()
    {
        cout<<"Name"<<this->m_Name<<"Age"<<this->m_Age<<endl;
    }
    
    NameType = m_Name;
    AgeType = m_Age;
};

void test01()
{
    Person p("Tom", 18); // Wrong! Class template cannot perform automatic data type interference
    Person<string, int> p1("Tom", 18);
    p1.showPerson();
}

void test02()
{
    Person<string> p1("Tom", 18);
}
```

### Member function creating time in class template

The difference between the member function in class template and generic class:

1. Member function in generic class can be created in the initial stage
2. Member function in class template can only be created when calling

```c++
class Person1
{
public:
    void showPerson1()
    {
        cout<<"Person1 show"<<endl;
    }
};

class Person2
{
public:
    void showPerson2()
    {
        cout<<"Person2 show"<<endl;
    }
};

template<class T>
class MyClass
{
public:
    T obj;
    // Member function
    void func1()
    {
        obj.showPerson1();
    }
    void func2()
    {
        obj.showPerson2();
    }
}

void test01()
{
    MyClass<Person1>m;
    m.func1();
    m.func2(); // Wrong! The instance is Person1 data type, cannot calling func2
}
```



### Class template object as function parameters

Three transferring methods:

1. Determining transferring data type -- Shown the object data type
2. Parameter template - Transferring the templatized parameters in the object 
3. Class template - Transferring the templatized class

```c++
template<class T1, class T2>
class Person
{
public:
    Person(T1 name, T2 age)
    {
        this->m_name = name;
        this-m_Age = age;
    }
    void showPerson()
    {
        cout<<"Person1 show"<<endl;
    }
    T1 m_name;
    T2 m_age;
};
// 1. Determining transferring data type
void printPerson1(Person<string,int>&p)
{
    p.showPerson();
}

void test01()
{
    Person<string,int>p("Tom", 18);
    printPerson1(p);
}

// 2. Parameter template 
template<class T1, class T2>
void printPerson2(Person<T1,T2>&p)
{
    p.showPerson();
    cout<<"T1 data type is"<<typeid(T1).name()<<endl;  // Print the data type
    cout<<"T2 data type is"<<typeid(T2).name()<<endl;
}
void test02()
{
    Person<string,int>p("Jack", 28);
    printPerson2(p);
}

// 3. Templized class
template<class T>
void printPerson3(T &p)
{
    p.shoPerson();
}
void test03()
{
    Person<string,int>p("Jerry", 25);
    printPerson3(p);
}
```



### Class template with inheritance

1. When the Derived class inherit from the Base class which is a template, in the declaration of the Derived class the data type of the T in Base class should be determined
2. If not determined, the compiler cannot allocate memory 
3. If user wants to flexible specified the data type T in Base class, the derived class should be class template as well

```c++
template<class T>
class Base
{
    T m;
};
class Son :public Base {} // Wrong ! The data type T should be determined when inheritance happended
class Son :public Base<int>
{
    
};

template<class T1, class T2>
class Son2 :public Base<T>
{
public:
    Son2()
    {
        cout<<typeid(T1).name()<<endl;
        cout<<typeid(T2).name()<<endl;
    }
    T1 obj;
};
void test02()
{
    Son2<int, char>S2;
}
```

### Function statement out of class in Class template

```c++
template<class T1, class T2>
class Person
{
public:
    Person(T1 name, T2 age)
    {
        this->m_name = name;
        this->m_age = age;
    }
    void showPerson()
    {
        cout<<this->m_name<<endl;
        cout<<this->m_age<<endl;
    }
    T1 m_name;
    T2 m_age;
}

// Constructor function statement
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
    this->m_name = name;
    this->m_age = age;
}
// Member function statement
template<class T1, class T2>
void Person<T1, T2>::showPerson()
{
   cout<<this->m_name<<endl;
   cout<<this->m_age<<endl; 
}
```

### Class template by files

The member function in class template is created in calling phase, which causes the sub-file cannot be linked when it is written

Solutions:

1. Include .cpp source file
2. Put the declaration and statement in a same file, change the postfix as .hpp 

### Class template and friend

Global function statement in class: Declaration friend in class 

Global function statement out of class: Let the compiler know in advance of the existence of global functions. 

```c++
// Global function to print the info in Person
//  Let the compiler know in advance of the existence of global functions. 
template<class T1, class T2>
class Person;

template<class T1, class T2>
void printPerson2(Person<T1, T2>p)
{
    cout<<p.m_name<<p.m_age<<endl;
}


template<class T1, class T2>
class Person
{
    // Global function statement in the class
    friend void printPerson(Person<T1, T2> p)
     {
         cout<<p.m_name<<p.m_age<<endl;
     }
    // Global function statement out of the class
    // Let the compiler know in advance of the existence of global functions. 
    friend void printPerson<>(Person<T1, T2> p);
public:
    Person(T1 name, T2 age)
    {
        this->m_name = name;
        this->m_age = age;
    }
private;
    T1 m_name;
    T2 m_age;
};

// Statement out of the class, should be moved in the front of the code
template<class T1, class T2>
void printPerson2(Person<T1, T2>p)
{
    cout<<p.m_name<<p.m_age<<endl;
}

void test01()
{
    Person<string, int>p("Tom", 20);
}

void test02()
{
    Person<string, int>p("Jerry", 20);
    printPerson2(p);
}
```

