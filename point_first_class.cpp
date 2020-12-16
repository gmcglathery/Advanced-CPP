/***************************************************
/   Greg McGlathery
/
/   Point Class First: Various Methods Testing
/
/**************************************************/

#include <iostream>
#include <fstream>
#include "point.h"

using namespace std;

ofstream outfile;

int main()
{
    outfile.open("results.txt");

    point p1;point p2;point p3;point p4;

    //Testing Points for accuracy
    //Testing Shift
    outfile<<"~Testing Shift Method~\n"<<endl;
    p1.shift(3,4);
    outfile<<"\tX Coord: "<<p1.get_x()<<" Y Coord: "<<p1.get_y()<<endl;

    //Testing Rotation
    outfile<<"\n~Testing Rotate 90 Method~\n"<<endl;
    p1.rotate90();
    outfile<<"\tX Coord: "<<p1.get_x()<<" Y Coord: "<<p1.get_y()<<endl;

    //Testing Rotations Needed
    outfile<<"\nAmount of rotations needed to move point x = "<<p1.get_x()<<" and y = "<<p1.get_y()<<" to Quadrant I: "<<rotations_needed(p1)<<endl;

    //Testing Distance Between Points
    outfile<<"\n~Testing Distance Method~\n"<<endl;
    p2.shift(9,15);
    outfile<<"\tCreating a second point to test distance between...."<<" second point coordinates are: ("<<p2.get_x()<<","<<p2.get_y()<<")."<<endl;
    outfile<<"\n\tThe distance between points ("<<p1.get_x()<<","<<p1.get_y()<<") and ("<<p2.get_x()<<","<<p2.get_y()<<") is: "<<dist(p1,p2)<<endl;

    //Testing Middle Point Method
    outfile<<"\n~Testing Middle Point Method~\n"<<endl;
    point mid=middle(p1,p2);
    outfile<<"\tThe middle point between points ("<<p1.get_x()<<","<<p1.get_y()<<") and ("<<p2.get_x()<<","<<p2.get_y()<<") is: ("<<mid.get_x()<<","<<mid.get_y()<<")."<<endl;

    //Testing Translation Method
    outfile<<"\n~Testing Translation Method~\n"<<endl;
    outfile<<"\tStarting Coords: ("<<p1.get_x()<<","<<p1.get_y()<<"). "<<"Translate values (2,4). "<<endl;
    p1.translation(2,4);
    outfile<<"\tNew coordinates are: ("<<p1.get_x()<<","<<p1.get_y()<<")."<<endl;

    //Testing Scaling Method
    outfile<<"\n~Testing Scaling Method~"<<endl;
    outfile<<"\tStarting Coords: ("<<p1.get_x()<<","<<p1.get_y()<<"). "<<"Scale values (6,4). "<<endl;
    p1.scaling(6,4);
    outfile<<"\tNew coordinates are: ("<<p1.get_x()<<","<<p1.get_y()<<")."<<endl;

    //Testing Rotation Method
    outfile<<"\n~Testing Rotation Method~\n"<<endl;
    outfile<<"\tStarting Coords: ("<<p1.get_x()<<","<<p1.get_y()<<"). "<<"Rotate values 180. "<<endl;
    p1.rotation(180);
    outfile<<"\tNew coordinates are: ("<<p1.get_x()<<","<<p1.get_y()<<")."<<endl;

    //Testing Shearing Method
    outfile<<"\n~Testing Shearing Method~\n"<<endl;
    outfile<<"\tStarting Coords: ("<<p1.get_x()<<","<<p1.get_y()<<"). "<<"Shear values (0,4). "<<endl;
    p1.shearing(0,4);
    outfile<<"\tNew coordinates are: ("<<p1.get_x()<<","<<p1.get_y()<<")."<<endl;
    p1.zero();p2.zero();

    outfile<<"\nSetting up coordinates for box."<<endl;
    p1.shift(2,2);
    p2.shift(2,5);
    p3.shift(4,5);
    p4.shift(4,2);
    outfile<<"\nPoint 1: ("<<p1.get_x()<<","<<p1.get_y()<<") Point 2: ("<<p2.get_x()<<","<<p2.get_y()<<") Point 3: ("<<p3.get_x()<<","<<p3.get_y()<<") Point 4: ("<<p4.get_x()<<","<<p4.get_y()<<")"<<endl;

    outfile<<"\nTranslating by x=2 and y=1"<<endl;
    p1.translation(2,1);
    p2.translation(2,1);
    p3.translation(2,1);
    p4.translation(2,1);
    outfile<<"\nPoints after translation: "<<endl;
    outfile<<"\n\tPoint 1: ("<<p1.get_x()<<","<<p1.get_y()<<") Point 2: ("<<p2.get_x()<<","<<p2.get_y()<<") Point 3: ("<<p3.get_x()<<","<<p3.get_y()<<") Point 4: ("<<p4.get_x()<<","<<p4.get_y()<<")"<<endl;

    outfile<<"\nScaling by x=2 and y=0.5"<<endl;
    p1.scaling(2,0.5);
    p2.scaling(2,0.5);
    p3.scaling(2,0.5);
    p4.scaling(2,0.5);
    outfile<<"\nPoints after scaling: "<<endl;
    outfile<<"\n\tPoint 1: ("<<p1.get_x()<<","<<p1.get_y()<<") Point 2: ("<<p2.get_x()<<","<<p2.get_y()<<") Point 3: ("<<p3.get_x()<<","<<p3.get_y()<<") Point 4: ("<<p4.get_x()<<","<<p4.get_y()<<")"<<endl;

    outfile<<"\nRotating box by 30 degrees..."<<endl;
    default_val(p1,p2,p3,p4);
    p1.rotation(30);
    p2.rotation(30);
    p3.rotation(30);
    p4.rotation(30);
    outfile<<"\nPoints after rotation: "<<endl;
    outfile<<"\n\tPoint 1: ("<<p1.get_x()<<","<<p1.get_y()<<") Point 2: ("<<p2.get_x()<<","<<p2.get_y()<<") Point 3: ("<<p3.get_x()<<","<<p3.get_y()<<") Point 4: ("<<p4.get_x()<<","<<p4.get_y()<<")"<<endl;

    outfile<<"\nRotating an additional 60 degrees..."<<endl;
    p1.rotation(60);
    p2.rotation(60);
    p3.rotation(60);
    p4.rotation(60);
    outfile<<"\n\tPoint 1: ("<<p1.get_x()<<","<<p1.get_y()<<") Point 2: ("<<p2.get_x()<<","<<p2.get_y()<<") Point 3: ("<<p3.get_x()<<","<<p3.get_y()<<") Point 4: ("<<p4.get_x()<<","<<p4.get_y()<<")"<<endl;

    outfile<<"\nShearing default points by x=1.5"<<endl;
    default_val(p1,p2,p3,p4);
    p1.shearing(1.5,0);
    p2.shearing(1.5,0);
    p3.shearing(1.5,0);
    p4.shearing(1.5,0);
    outfile<<"\n\tPoint 1: ("<<p1.get_x()<<","<<p1.get_y()<<") Point 2: ("<<p2.get_x()<<","<<p2.get_y()<<") Point 3: ("<<p3.get_x()<<","<<p3.get_y()<<") Point 4: ("<<p4.get_x()<<","<<p4.get_y()<<")"<<endl;

    outfile<<"\nShearing default points by y=1.7"<<endl;
    default_val(p1,p2,p3,p4);
    p1.shearing(0,1.7);
    p2.shearing(0,1.7);
    p3.shearing(0,1.7);
    p4.shearing(0,1.7);
    outfile<<"\n\tPoint 1: ("<<p1.get_x()<<","<<p1.get_y()<<") Point 2: ("<<p2.get_x()<<","<<p2.get_y()<<") Point 3: ("<<p3.get_x()<<","<<p3.get_y()<<") Point 4: ("<<p4.get_x()<<","<<p4.get_y()<<")"<<endl;

    outfile.close();
    return 0;
}
