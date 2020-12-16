/*******************************************
Greg McGlathery
CS 372
Throttle
*******************************************/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

ifstream infile;
ofstream outfile;

class throttle
{
public:
    //constructors
    throttle();
    throttle(int);
    throttle(int,int);
    //Methods
    void shift(int);
    void shut_off();
    int get_pos();
    int get_top_pos();
    double flow();
    bool is_on();
private:
    int position, top_position;
};
int main()
{
    outfile.open("results.txt");

    throttle car;
    throttle truck(30);
    throttle shuttle(20,6);

    //Shut_off method demonstration
    outfile<<"Starting position: "<<car.get_pos()<<" Max top position: "<<car.get_top_pos()<<endl;
    outfile<<"Testing shut_off method"<<endl;
    car.shift(4);
    outfile<<"Throttle currently at: "<<car.get_pos()<<endl;
    outfile<<"Calling shut_off"<<endl;
    car.shut_off();
    outfile<<"Checking position...."<<endl;
    outfile<<"Throttle is now at: "<<car.get_pos()<<endl;
    outfile<<"Verifying shut_off..."<<endl;
    car.shut_off();
    outfile<<"Position is now: "<<car.get_pos()<<endl;
    //Shift method demonstration
    outfile<<"Testing shift method"<<endl;
    car.shift(4);
    outfile<<"Throttle currently at: "<<car.get_pos()<<endl;
    car.shift(2);
    outfile<<"Shift +2, throttle at: "<<car.get_pos()<<endl;
    car.shift(-3);
    outfile<<"Shift -3, throttle at: "<<car.get_pos()<<endl;
    car.shift(5);
    outfile<<"Shift +5, throttle should not exceed 6: "<<car.get_pos()<<endl;
    car.shift(-9);
    outfile<<"Shift -9, throttle should not be negative: "<<car.get_pos()<<endl;

    //Truck Testing
    outfile<<"\nLet's test the truck..."<<endl;
    outfile<<"Truck starting position: "<<truck.get_pos()<<" Truck Max Throttle: "<<truck.get_top_pos()<<endl;
    outfile<<"Attempting to set truck throttle to 31; max is 30"<<endl;
    truck.shift(31);
    outfile<<"Truck throttle should not exceed 30: "<<truck.get_pos()<<endl;
    truck.shift(-40);
    outfile<<"Shift truck throttle -40; position is now: "<<truck.get_pos()<<endl;
    outfile<<"Shifting truck +15"<<endl;
    truck.shift(15);
    outfile<<"Truck is now at: "<<truck.get_pos()<<endl;
    truck.shut_off();
    outfile<<"Shutting truck off; position is now: "<<truck.get_pos()<<endl;

    //Testing van
    outfile<<"\nLet's play with the shuttle."<<endl;
    outfile<<"Shuttle position: "<<shuttle.get_pos()<<endl;
    outfile<<"Displaying shuttles top position: "<<shuttle.get_top_pos()<<endl;
    shuttle.shift(13);
    outfile<<"Shifting shuttle +13...\n"<<"Shuttle is now at: "<<shuttle.get_pos()<<endl;

    return 0;
}
throttle::throttle()
{
    position=0;top_position=6;
}
throttle::throttle(int top)
{
    top_position=top;
    position=0;
}
throttle::throttle(int top, int pos)
{
    top_position=top;position=pos;
}
void throttle::shut_off()
{
    position=0;
}
bool throttle::is_on()
{
    if(position)
    {
        return true;
    }
    else
        return false;
}
int throttle::get_pos()
{
    return position;
}
int throttle::get_top_pos()
{
    return top_position;
}
void throttle::shift(int x)
{
    position+=x;
    if(position>top_position)
    {
        position=top_position;
    }
    if(position<0)
    {
        position=0;
    }
}
double throttle::flow()
{
    if(!position)
    {
        return 0;
    }
    return double(position)/top_position;
}
