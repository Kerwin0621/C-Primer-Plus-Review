#include<iostream>

using namespace std;

class AbstractDrink
{
public:
    virtual void Boil() = 0;
    virtual void Brewup() = 0;
    virtual void Pour() = 0;
    virtual void Seasoning() = 0;

    // Making drinks
    void makeDrink()
    {
        Boil();
        Brewup();
        Pour();
        Seasoning();
    }
};

class Coffee:public AbstractDrink
{
public:
    virtual void Boil()
    {
        cout<<"Evian"<<endl;
    };
    virtual void Brewup()
    {
        cout<<"Coffee"<<endl;
    };
    virtual void Pour()
    {
        cout<<"Pour in Cup"<<endl;
    };

    virtual void Seasoning()
    {
        cout<<"Add suger and milk"<<endl;
    };
};

class Tea:public AbstractDrink
{
public:
    virtual void Boil()
    {
        cout<<"Evian"<<endl;
    };
    virtual void Brewup()
    {
        cout<<"Longjing"<<endl;
    };
    virtual void Pour()
    {
        cout<<"Pour in Cup"<<endl;
    };

    virtual void Seasoning()
    {
        cout<<"Add suger"<<endl;
    };
};

void doDrink(AbstractDrink *abs)
{
    abs->makeDrink();
    delete abs;
}

void test01()
{
    // make coffee
    doDrink(new Coffee);

    cout<<"--------"<<endl;
    doDrink(new Tea);
}

int main()
{
    test01();
    return 0;
}