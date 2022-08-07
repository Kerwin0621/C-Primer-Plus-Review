#include<iostream>

using namespace std;

// Component class
class AbsCPU
{
public:
    virtual void calculate() = 0;
};

class AbsVideoCard
{
public:
    virtual void display() = 0;
};

class AbsMemory
{
public:
    virtual void storage() = 0;
};


class Computer
{
public:
    Computer(AbsCPU * cpu, AbsVideoCard * vc, AbsMemory * memory)
    {
        m_cpu = cpu;
        m_vc = vc;
        m_memory = memory;
    }

    // Working function
    void work()
    {
        m_cpu->calculate();
        m_vc->display();
        m_memory->storage();
    }
    // Destructor to release the components of the computer
    ~Computer()
    {
        if (m_cpu!= NULL)
        {
            delete m_cpu;
            m_cpu = NULL;
        }
        if (m_vc!= NULL)
        {
            delete m_vc;
            m_vc = NULL;
        }
        if (m_memory!= NULL)
        {
            delete m_memory;
            m_memory = NULL;
        }
    }

private:
    AbsCPU * m_cpu;
    AbsVideoCard * m_vc;
    AbsMemory * m_memory;

};

// Brand instance
// Intel
class IntelCPU:public AbsCPU
{
public:
    virtual void calculate()
    {
        cout<<"Intel CPU start working"<<endl;
    }

};
class IntelVC:public AbsVideoCard
{
public:
    virtual void display()
    {
        cout<<"Intel Video Card start working"<<endl;
    }
};

class IntelMemory:public AbsMemory
{
public:
    virtual void storage()
    {
        cout<<"Intel Memory start working"<<endl;
    }
};

// Lenovo ... same staff can copy&paste

// Assemble computers
void test01()
{
    // The components of the first computers
    AbsCPU * intelCpu = new IntelCPU;
    AbsVideoCard * intelVC = new IntelVC;
    AbsMemory *intelMemory = new IntelMemory;

    // Create the first computer
    Computer * intel_com = new Computer(intelCpu, intelVC, intelMemory);
    intel_com ->work();
    delete intel_com;
}


int main()
{

    test01();
    return 0;
}