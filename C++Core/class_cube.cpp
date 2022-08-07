#include<iostream>

using namespace std;


/*Define a Cube Class
    1. Calculate the Area and Volume of the Cube
    2. Using Global function and member function to compare two cube equal or not*/

class Cube
{
// Create the value assign function and value get function in public for user inputs 
public:
    // Value assign function
    void assign_value(int l, int w, int h)
    {
        c_length = l;
        c_width = w;
        c_height = h;
    }

    // Value get function
    int get_length()
    {
        return c_length;
        // cout<<"The length of the cube is:\t"<<c_length<<endl;
        // cout<<"The width of the cube is:\t"<<c_width<<endl;
        // cout<<"The height of the cube is:\t"<<c_height<<endl;
    }
    int get_width()
    {
        return c_width;
    }
    int get_height()
    {
        return c_height;
    }

    // Calculate the Cube area
    int area_Cube()
    {
        // Make sure the value of the input is validity
        if (c_length<=0 || c_width<=0 || c_height<=0)
        {
            cout<<"Wrong input! Please check the input!"<<endl;
            return 0;
        }
        return (2*c_length*c_height + 2*c_length*c_width + 2*c_height*c_width);
    }

    int volume_Cube()
    {
        // Make sure the value of the input is validity
        if (c_length<=0 || c_width<=0 || c_height<=0)
        {
            cout<<"Wrong input! Please check the input!"<<endl;
            return 0;
        }
        return c_length*c_width*c_height;
    }

    // Member for comparsion
    void compare_cube_ic(Cube &c)
    {
        // The comparsion is between the input Class and the inner-class attribute
        if (c_length == c.get_length() && c_width == c.get_width() && c_height == c.get_height())
        {
            cout<<"These two cube are the same"<<endl;
        }
        else
        {
            cout<<"These two cube are different"<<endl;
        }

    }

// Define the l, w, h as private member info, for avoiding any changes directly    
private:
    int c_length;
    int c_width;
    int c_height;

};



// Global function to compare two cube is equal or not
void compare_cube(Cube &c1, Cube &c2)
{
    if (c1.get_height() == c2.get_height() && c1.get_length() == c2.get_length() && c1.get_width() == c2.get_width())
    {
        cout<<"These two cube are the same"<<endl;
    }
    else
    {
        cout<<"These two cube are different"<<endl;
    }
}



int main()
{
    // Create a instance
    Cube c1;
    c1.assign_value(5,6,7);
    //cout<<"The area of this cube c1 is:\t"<<c1.area_Cube()<<endl;
    //cout<<"The volume of this cube c1 is:\t"<<c1.volume_Cube()<<endl;
    Cube c2;
    c2.assign_value(5,5,7);
    //compare_cube(c1, c2);
    c1.compare_cube_ic(c2);

    return 0;
}