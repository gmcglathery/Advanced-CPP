/***************************************************
/   Greg McGlathery
/
/   point.h
/   Header File
/
/**************************************************/

#ifndef point_h
#define point_h
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double PI=3.14159265359;

class point
{
public:
    // Constructor
    point(double initial_x=0.0,double initial_y=0.0);

    // Modifying Member Functions
    void shift(double x_amount, double y_amount);
    void rotate90();
    double translation(double x_amount, double y_amount);
    double scaling(double x_amount, double y_amount);
    double rotation(double rot_amount);
    double shearing(double x_amount, double y_amount);
    void zero();
    void default_val();
    const point operator +(const point &p);
    const point operator -(const point &p);

    //Friend Function for out and in
    friend std::ostream & operator<<(std::ostream & out, const point &point);

    // Constant Member Functions
    double get_x() const {return x;}
    double get_y() const {return y;}

private:
    double x;
    double y;
};

//Nonmember Functions for Point
double dist(const point &p1, const point &p2);
point middle(const point &p1, const point &p2);
int rotations_needed(point p);
bool operator ==(const point &p1, const point &p2);
bool operator !=(const point &p1, const point &p2);
bool operator >(const point &p1,const point &p2);
bool operator <(const point &p1,const point &p2);
bool operator >=(const point &p1,const point &p2);
point distanceTo(const point &p1,const point &p2);

point::point(double initial_x, double initial_y)
{
    //This is the constructor to set default positions
    x=initial_x;
    y=initial_y;
}
void point::shift(double x_amount, double y_amount)
{
    x+=x_amount;
    y+=y_amount;
}
void point::rotate90()
{
    double new_x;
    double new_y;
    new_x=y;    // For a 90-degree clockwise rotation, the new x is the original y
    new_y=-x;   // New y is -1 times original x
    x=new_x;
    y=new_y;
}
int rotations_needed(point p)
{
    int answer;
    answer=0;
    while((p.get_x()<0 || (p.get_y()<0)))
    {
        p.rotate90();
        ++answer;
    }
    return answer;
}
double dist(const point &p1, const point &p2)
{
    //Returns distance between the two points
    double a, b, c_squared;

    //Calculates difference in x and y coordinates
    a=p1.get_x()-p2.get_x(); //Difference in x
    b=p1.get_y()-p2.get_y(); //Difference in y
    //Use Pythagorean Theorem to calc square of distance between points
    c_squared=a*a+b*b;
    return sqrt(c_squared);
}
double point::translation(double x_amount, double y_amount)
{
    x+=x_amount;
    y+=y_amount;
}
double point::scaling(double x_amount, double y_amount)
{
    x*=x_amount;
    y*=y_amount;
}
double point::rotation(double rot_amount)
{
    float rad;
    rad=rot_amount*(PI/180);
    x=cos(rad)*x+sin(rad)*y;
    y=sin(rad)*x-cos(rad)*y;
}
double point::shearing(double x_amount,double y_amount)
{
    x+=x_amount;
    y+=y_amount;
}
point middle(const point &p1,const point &p2)
// Postcondition: The value returned is the point that is halfway between p1 and p2.
{
    double x_midpoint, y_midpoint;
    // Compute the x and y midpoints.
    x_midpoint=(p1.get_x()+p2.get_x())/2;
    y_midpoint=(p1.get_y()+p2.get_y())/2;
    // Construct a new point and return it.
    point midpoint(x_midpoint,y_midpoint);
    return midpoint;
}
void point::zero()
{
    x=0;
    y=0;
}
void default_val(point &p1, point &p2, point &p3, point &p4)
{
    p1.zero();p2.zero();p3.zero();p4.zero();
    p1.shift(2,2);
    p2.shift(2,5);
    p3.shift(4,5);
    p4.shift(4,2);
}
bool operator==(const point &p1,const point &p2)
{
    return
        (p1.get_x()==p2.get_x())&&(p1.get_y()==p2.get_y());
}
bool operator !=(const point &p1, const point &p2)
{
    return
        (p1.get_x()!=p2.get_x()||(p1.get_y()!=p2.get_y()));
}
const point point::operator +(const point &p)
{
    return point(x+p.x,y+p.y);
}
const point point::operator -(const point &p)
{
    return point(x-p.x,y-p.y);
}
ostream &operator<<(ostream &out, const point &point)
{
    out<<"("<<point.x<<","<<point.y<<")";
    return out;
}
bool operator >(const point &p1,const point &p2)
{
    return((p1.get_x()+p1.get_y())>(p2.get_x()+p2.get_y()));
}
bool operator <(const point &p1,const point &p2)
{
    return((p1.get_x()+p1.get_y())<(p2.get_x()+p2.get_y()));
}
bool operator >=(const point &p1,const point &p2)
{
    return(sqrt(pow(p1.get_x(),1)+pow(p1.get_y(),1)))>=(sqrt(pow(p2.get_x(),1)+pow(p2.get_y(),1)));
}
#endif
