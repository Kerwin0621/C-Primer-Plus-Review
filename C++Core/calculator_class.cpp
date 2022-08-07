#include<iostream>

using namespace std;

class Calculator
{
public:
    int getResult(string oper)
    {
        if (oper == "+")
        {
            return m_Num1+m_Num2;
        }
        else if (oper == "-")
        {
            return m_Num1 - m_Num2;
        }
        else if (oper == "*")
        {
            return m_Num1 * m_Num2;
        }
        return 0;
    }
    int m_Num1;
    int m_Num2;
};

void test01()
{
    // Create calculator instance
    Calculator c1;
    c1.m_Num1 = 10;
    c1.m_Num2 = 15;
    cout<<c1.getResult("+")<<endl;
}

// -------------------------------------------------------------------------------
// Polymorphism 
class AbsCalculator
{
public:
    virtual int getResult()
    {
        return 0;
    }    
    int m_Num1;
    int m_Num2;
};

class AddCalculator:public AbsCalculator
{
public:
    int getResult()
    {
        return m_Num1 + m_Num2;
    }

};

class SubCalculator:public AbsCalculator
{
public:
    int getResult()
    {
        return m_Num1 - m_Num2;
    }

};

class MulCalculator:public AbsCalculator
{
public:
    int getResult()
    {
        return m_Num1 * m_Num2;
    }

};

class DivCalculator:public AbsCalculator
{
public:
    int getResult()
    {
        return m_Num1 / m_Num2;
    }

};

void test02()
{
    // The condition of adopting polymorphism - Base class pointer or citation to point Derived object
    //Add
    AbsCalculator * abc = new AddCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 10;
    cout<<abc->getResult()<<endl;
    // New grammar will create data in heap area, delete it after using
    delete abc;

    //Subtract
    abc = new SubCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 10;
    cout<<abc->getResult()<<endl;
    delete abc;

    //Multiply
    abc = new MulCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 10;
    cout<<abc->getResult()<<endl;
    delete abc;
    
    //Divide
    abc = new DivCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 10;
    cout<<abc->getResult()<<endl;
    delete abc;
}


int main()
{
    test02();
    return 0;
}