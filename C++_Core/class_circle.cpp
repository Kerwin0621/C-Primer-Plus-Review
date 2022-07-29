#include<iostream>
#include<math.h>

using namespace std;

/*Design a circle class and a point class
Calculate the relationship between the point and the circle*/

/*The relationship between the point and a circle:
1. Point is out of the circle   (D>R)
2. Point is on the circle       (D=R)
3. Point is in the circle       (D<R)

Where:
    R is the radius of the circle
    D is the Eulidean distance = srqt( (x1-x2)^2 + (y1-y2)^2 )
*/


class Circle
{
public:
    // Define the function to assign the value of to define a circle
    void assign_x(int x)
    {
        x_c = x;
    }
    void assign_y(int y)
    {
        y_c = y;
    }
    void assign_r(int r)
    {
        r_c = r;
    }

    // Define the function to get the value of the circle
    int get_x()
    {
        return x_c;
    }
    int get_y()
    {
        return y_c;
    }
    int get_r()
    {
        return r_c;
    }

private:
    // Define the coordinate of the circle
    int x_c;
    int y_c;
    /* In another way, we can consider that using the Point class to define the centre points of the circle
    Point Center;*/
    // Define the radius of the circle
    int r_c;
    
};


class Point
{
public:
    // Define the function to assign the value of to define a point
    void assign_x(int x)
    {
        x_p = x;
    }
    void assign_y(int y)
    {
        y_p = y;
    }

    // Define the function to get the value of the point
    int get_x()
    {
        return x_p;
    }
    int get_y()
    {
        return y_p;
    }    

private:
    // Define the coordinate of the circle
    int x_p;
    int y_p;
};


// Create a global function to calculate the relationship between the point and circle
void point_circle(Circle &c1, Point &p1)            // Why we need the pointer? Review the recordings
{
    int x;
    x = c1.get_x() - p1.get_x();
    int y;
    y = c1.get_y() - p1.get_y();

    double dis = sqrt(x*x + y*y);
    if (dis>c1.get_r())
    {
        cout<<"The point is out of the circle"<<endl;
    }
    else if (dis == c1.get_r())
    {
        cout<<"The point is on the circle"<<endl;
    }
    else
    {
        cout<<"The point is in the circle"<<endl;
    }
    
}



int main()
{
    // Create a circle instance
    Circle c1;
    c1.assign_x(0);
    c1.assign_y(0);
    c1.assign_r(5);

    // Create a point instance
    Point p1;
    p1.assign_x(0);
    p1.assign_y(5);

    // Define the relationship
    point_circle(c1, p1);

    return 0;
}