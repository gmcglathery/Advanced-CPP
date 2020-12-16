/*******************************************
Greg McGlathery
CS 372
Overload Methods
*******************************************/

#include <iostream>
#include <fstream>
#include "point.h"

using namespace std;

ofstream outfile;

int main()
{
    outfile.open("results.txt");

    //Creating point objects for testing
    point p1;point p2;point p3;point p4;

    //Putting data in objects.
    p1.shift(2,4);
    p2.shift(2,4);

    //Testing if points are equal.  Points were set the same so results should show that they are equal
    outfile<<"The == test will be run with points (2,4) and (2,4).\n\tRunning test."<<endl;
    if(p1==p2)
        outfile<<"\tThe points of p1 and p2 are equal."<<endl;
    else
        outfile<<"\tThe points of p1 and p2 are not equal."<<endl;

    //Testing == with values set up to return false
    outfile<<"\nTo test == for false conditions we will be shifting p1 by (1,1) to make the points (3,5) and (2,4).\n\tRunning test."<<endl;
    p1.shift(1,1);
    if(p1==p2)
        outfile<<"\tThe points of p1 and p2 are equal."<<endl;
    else
        outfile<<"\tThe points of p1 and p2 are not equal."<<endl;

    //Testing != with values to return true
    p1.zero();p2.zero(); // Zeroing points
    p1.shift(2,2);p2.shift(2,4); //Unequal points
    outfile<<"\nTesting != with points at (2,2) and (2,4).\n\tRunning test."<<endl;
    if(p1!=p2)
        outfile<<"\tThese points are not equal."<<endl;
    else
        outfile<<"\tThese points are equal."<<endl;

    //Testing != with values to return false
    p1.shift(0,2); //To make points p1 and p2 equal
    outfile<<"\nTesting != with points at (2,4) and (2,4).\n\tRunning test."<<endl;
    if(p1!=p2)
        outfile<<"\tThese points are not equal."<<endl;
    else
        outfile<<"\tThese points are equal."<<endl;

    //Testing + operator overload
    p1.zero();p2.zero();
    p1.shift(2,2);p2.shift(2,2);
    outfile<<"\nTesting + operator overload with points (2,2) and (2,2)."<<endl;
    p3=p1.operator+(p2);
    outfile<<"\tNew points: ("<<p3.get_x()<<","<<p3.get_y()<<")."<<endl;

    //Testing - operator overload
    p1.zero();p2.zero();
    p1.shift(2,4);p2.shift(4,2);
    outfile<<"\nTesting - operator overload with points (2,4) and (4,2)."<<endl;
    p4=p1.operator-(p2);
    outfile<<"\tNew points: ("<<p4.get_x()<<","<<p4.get_y()<<")."<<endl;

    //Testing << operator overload
    outfile<<"Testing << overload now at points (6,4)."<<endl;
    p1.zero();
    p1.shift(6,4);
    outfile<<"\tCoordinates with << overload: "<<p1<<endl;

    //Testing > operator overload
    outfile<<"\nTesting > operator overload to determine which point is closer to (0,0)."<<endl;
    outfile<<"\tUsing points (1,4) and (7,0)."<<endl;
    p1.zero();p2.zero();
    p1.shift(1,4);p2.shift(7,0);

    if(p1>p2)
        outfile<<"\n\t"<<p1<<" is further away from the origin."<<endl;
    else
        outfile<<"\t"<<p2<<" is further away from the origin."<<endl;

    //Testing < operator overload
    outfile<<"\nTesting < operator overload to determine which point is closer to (0,0)."<<endl;
    outfile<<"\tUsing points (4,4) and (7,3).";
    p1.zero();p2.zero();
    p1.shift(4,4);p2.shift(7,3);

    if(p1<p2)
        outfile<<"\n\t"<<p2<<" is further away from the origin."<<endl;
    else
        outfile<<"\t"<<p1<<" is further away from the origin."<<endl;

    //Testing >= operator overload
    outfile<<"\nTesting >= operator overload to determine if one point is further from (0,0) than the other."<<endl;
    outfile<<"\tUsing points (4,4) and (4,4). ";
    p2.zero();p1.zero();
    p2.shift(4,4);p1.shift(4,4);

    if(p1>=p2)
        outfile<<"\n\t"<<p1<<" is greater distance or equal from the origin."<<endl;
    else
        outfile<<"\n\t"<<p2<<" is greater distance or equal from the origin."<<endl;

    //Testing >= operator overload with different metrics
    outfile<<"\nTesting >= operator overload to determine if one point is further from (0,0) than the other."<<endl;
    outfile<<"\tUsing points (4,9) and (2,4). ";
    p2.zero();p1.zero();
    p2.shift(4,9);p1.shift(2,4);

    if(p1>=p2)
        outfile<<"\n\t"<<p1<<" is greater distance or equal from the origin."<<endl;
    else
        outfile<<"\n\t"<<p2<<" is greater distance or equal from the origin."<<endl;

    outfile.close();
    return 0;
}
