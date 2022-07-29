# C++



## C++ in Linux



### GDP Debugger

The GNU debugger 



## Basic Knowldege

Ru-noob: https://www.runoob.com/cplusplus/cpp-tutorial.html



**A simple C++ example**

```c++
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
```

**Single Line Notation** : //

**Multi-Line Notation** : / \* * /



### Variables

Easy to manage the memory space

Grammar:		datatype + variable name = initial value



### Consant

Record the un-modified datatype

Two ways to define a constant:

1. \#define (macro definition)
2. const (statement)

Differences:

1. Type and security check
2. Compiler processing
3. Storage method
4. Domain of definition



### Identifier

Rules:

1. Can not be the key words
2. Only consist of alphabet, numbers, underlines 
3. First character must be alphabet or underlines
4. Captial and lower-case are different



### Sizeof

Queries size of the object or type, display the memory space of this datatype

Gramma: sizeof(datatype / varaibale)



### Floating Decimal

float: 4 byte, 7 decimal   			float f1 = 3.14f

double: 8 byte, 15~16 decimal



### Character

To display the single character

Grammar: char ch = 'a' ;

Note: 

1. To display the character varaibles, only can us '', not ""
2. Only single ch can be in '', not character string

ASCII code of character

std::cout<<(int) ch <<endl;



C style string:

​		char str[] = "hello world"

C++ style string

#include<string>

​		string str1 = "hello world"

### Bool

True -- 1

False -- 0



### Input

int a = 0;

cin >> a;



### Operator

1. Arthmetic operator

   %: module calculation to find the remainder, e.g. 10%3 = 1

   Pre-incrementation & Post-incrementation

   Pre-i : +1 first, then operator

   Post-i: operator first, then +1

   

2. Assign operator

   The value of expression given to the variable. =, +=, *=, /=, %=

3. Comparison operator

   Compare the expression, and return True or False. ==, !=, <, >, <=, >=

4. Logical operator 

​		Return True or Flase according to the value of expression. ! nor, && and, || or.

​		In C++, all the numbers are True except 0



### Flow Structure

**Sequence**, **Choice**, **Loop**

#### Choice

 **If**

1. Single If

   If (conditions) {statements}

2. Multi-lines if

   if (conditions) {statements} else{statements}

3. Multi-conditions if

​		if (conditions 1) {statements} else if (conditions 2){statements} ... else{statements}

### Ternary Operator

Easy format to perform judgement

Grammar: express 1 ? expression 2 : expression 3

Interpratation: if exp1 is True, return exp2; else return exp3

The return result of ternary operator is variable



### Switch

Execute multi-conditions statement

```c++
switch(input)
{
    case Result1: statement; break;
    case Result2: statement; break;
    ...
    default: staement; break;
}
```

The input of switch can only be int or character

switch can not judge interval  



### Loop Structure

**while**

If the condition is True, then do the loop

Grammar: while(condition){statement}



**do...while**

Grammar: do{statement} while {condition}

The difference between while is that do...while will execute the loop statement, then discriminating the loop conditions



**for**

Grammar: for(start; condition; end) {loop statement}



**Nested Loop**



### Jump

**break**

1. in switch statement, stop the case and jump out from switch
2. in loop, stop the current loop
3. in nested loop, jump out from closer loop statement

**continue**

Jump the remaining statements in this loop, and execute the next loop

**goto**

jump the statement without any conditions

goto FLAG;

...

FLAG:

...



### Array

Array is a set where store the same data type element in continuous memory location

Define method:

1. Datatype Name[Length];
2. Datatype Name[Length] = {value1  value2 ...};
3. Datatype Namep[ ] + {value1, value2 ...};

Usage:

1. Calculate the length of the array in the memory
2. Acquire the initial address of the array in the memory. Grammar: &arr[i]



### 2D Array

Define method:

1. Datatype Name\[column][row];
2.    Datatype Name\[column][row] = { {data1, data2}, {data3, data4} };
3. Datatype Nme\[column][row] = {data1, data2, data3, data4};
4. Datatype Name\[][row] = {data1, data2, data3, data4};

Generally we use 2nd define method

Usage:

1. Calculate the length of the array in the memory
2. Acquire the initial address of the array in the memory. Grammar: &arr[i]

```c++
cout<<"2D Array memory use:"<<sizeof(arr)<<endl;
cout<<"2D Array 1st column memory use:"<<sizeof(arr[0])<<endl;
cout<<"2D Array 1st element memory use:"<<sizeof(arr[0][0])<<endl;
cout<<"2D Array column number"<<sizeof(arr)/sizeof(arr[0])<<endl;
cout<<"2D Array row number"<<sizeof(arr[0])/sizeof(arr[0][0])<<endl;
```



### Functions

Function encapsulation to decrease the code repeated

Define steps:

1. Return datatype
2. Function name
3. Parameters input
4. Function statement
5. Return expression

```c++
int add(int num1, int num2)
{
    int sum = num1 + num2;
    return sum
}
```

#### Calling function

function (formal parameter)

{

​	statement;

​	return ...

}

When calling that function

variable = function (actual parameter)

#### Function types

```c++
void test01()
{
    cout<<"This doesnt need parameters and returns";
}

void test02(int a)
{
    cout<<"This function has a formal parameter:"<<a<<endl;
}

int test02()
{
    cout<<"This is test 03"<<endl;
    return 100;
}

int test04(int a)
{
    cout<<"It has formal parameter and return";
    return a
}
```



#### Function declaration

Function declaration can be multi-time, but it statement can only be once

Multi-files steps:

1. Create .h head file
2. Create .cpp source file
3. In the head file write the declaration
4. In the source file write the statement



### Pointer

We can find the memory space by the pointer indirectly

1. The memory number is recorded from 0, it expressed in hexadecimal
2. We can use the pointer variable to save the address

Grammar: Datatype *variable name;

```c++
// 1. Define the pointer
int a = 10;
//  Pointer Grammar
int *p;
// Making the pointer records the address of variable a
p = &a;

// 2. Using the pointer
cout<< p <<endl; // output is the address
cout<<*p <<endl; // output is the value in that address
```

#### Byte space

In 32-bit operation system (x86), pointer occupies 4 bytes

In 64-bit operation system (x64), pointer occupies 8 bytes

#### NULL Pointer & Wild Pointer

在变量声明的时候，如果没有确切的地址可以赋值，为指针变量赋一个 NULL 值是一个良好的编程习惯

NULL pointer indicates the index = 0 space in memory

Usage: Initial pointer variables

Note: the memory of NULL pointer is not asked

0~255 index number of memory are used by the system, thus is not asked

如果所有未使用的指针都被赋予空值，同时避免使用空指针，就可以防止误用一个未初始化的指针。很多时候，未初始化的变量存有一些垃圾值，导致程序难以调试。



Wild pointer indicates the illegal memory space

int *p = int( *) 0x1100

People should avoid to do this



#### Const decorate pointer

Three situations:

1. const decorate pointer -- const pointer

   Direction of the pointer can be changed, but the value of pointer indicates can not be changed

2. const decorate constant -- pointer constant 

   Direction of the pointer can not be changed, but the value of pointer indicates can be changed

3. const decorate pointer & constant

   Direction of the pointer can not be changed, and the value of pointer indicates can not be changed

  ```c++
  int a = 10;
  int b = 10;
  int *p = &a;
  
  // Const decorate pointer
  const int *p = &b ("Corect");
  const int *p = 20 ("Wrong");
  
  // Const decorate constant
  int * const p = 20 ("Correct");
  int * const p = &b ("Wrong");
  
  // Const decorate P&C
  const int * const p = 20 ("Wrong");
  const int * const p = &b ("Wrong")
  ```

 

#### Pointer & Array

Using the pointer to ask the elements in array

```C++
int arr[10] = {1,2,3,4,5,6,7,8,9,0};
int *p = arr; // arr is the first address of the array.
// If we want to find the next element, moving the pointer by 4 byte, thus for int *p
p++;
cout<<*p<<endl; // Second element of array

// All the elements in array
for (int i=0; i<10; i++)
{
    cout<<*p<<endl;
    p++
}
```



#### Pointer & Function

Using the pointer as the formal parameter of the function, for changing the value of actual parameters

```c++
void swap01(int a, int b)
{
    int temp = a;
    a = b;
    b = a;
}

void swap02(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a = 10;
    int b = 20;
    // Value Transferring  -- The results would not change the value of actual a and b
    swap01(a, b);
    
    // Address Transferring
    swap02(&a, &b);
    
    return 0;
}
```



### Structural body

Structures (also called structs) are a way to group several related variables into one place. Each variable in the structure is known as a **member** of the structure.

Unlike an [array](https://www.w3schools.com/cpp/cpp_arrays.asp), a structure can contain many different data types (int, string, bool, etc.).

Create a Structure

```c++
struct MyStructure   // Structure declaration
{
    int myNum;
    string myString;
};

// Assess the structure
myStructure.myNum = 1;
myStructure.myString = "Hello World";
```

#### Structure array

Put the self-defined structure body in array 

Grammar:  struct Name Array_name [Element_num] = {  {}, {}, ..., {} };

 ```c++
 struct Student 
 {
     string name;
     int age;
     int score;
 }
 
 int main()
 {
     Student stuArray[3]
     {
         {"Jack", 18, 100};
         {"Tom", 18, 100};
         {"Jhon", 18, 100};
     }
     
     // Using "." to call the members of the struct
     stuArray[2].name = "Ben";
     stuArray[0].age = 25;
     
     // Using the loop the print the members
     for (int i=0; i<3; i++)
     {
         cout<<stuArray[i].name<<"\t"<<stuArray[i].age<<"\t"<<stuArray[i].score<<endl;
     }
     
 }
 ```

#### Structure pointer

Using pointer to call the members in the structure body

Using operation symbol "->" can visit the structure characterize by structure pointer

```c++
struct Student
{
    string name;
    int age;
    int score;
}

int main()
{
    Student s1 = {"Jack", 18, 100};
    
    // Using pointer to point the struct variables
    student *p = &s;
    
    // Using pointer to visit the data in the struct variables
    cout<<"Name"<<p->name<<"Age"<<p->age<<"Score"<<p->score<<endl;
}
```

#### Structure nesting

Usage: The member of a structure can be another structure

```c++
struct Student
{
    string name;
    int age;
    int score;
};

struct Teacher
{
    string name;
    int id;
    int age;
    Student s1;    
};

int main()
{
    teacher t;
    t.id = 101;
    t.name = "Jerry";
    t.age = 35;
    t.s1.name = "Tom";
    t.s1.age = 18;
    t.s1.score = 100;
}
```

#### Structure as Function parameters

Usage: Transferring the structure in the function as parameters

Two methods for transferring

1. Value Transferring
2. Address Transferring

```c++
struct Student
{
    string name;
    int age;
    int score;
};

// Value transferring
void printStudent1(Student s)
{
    cout<<s.name<<s.age<<s.score<<endl;
}
// Address transferring
void printStudent(Student *s)
{
    cout<<s->name<<s->age<<s->score<<endl;
}

int main()
{
    Student s1;
    s1.name = "jack";
    s1.age = 18;
    s1.score = 100;
    
}
```

#### Structure const

Usage: using const to decorate to avoid any incorrect operations

```c++
struct Student
{
    string name;
    int age;
    int score;
};

// Using pointers, can save the memory space, it will not cpoy and occupy new memory space
void printStudent(const Student *s)
{
    // Once add const, the parameters can not be changed
    cout<<s->name<<s->age<<s->score<<endl;
}
```















happy