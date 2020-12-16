/*******************************************
Greg McGlathery
CS 372
Statistician
*******************************************/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

ifstream infile;
ofstream outfile;

class statistics{
    public:
        //Constructor
        statistics()
        {
            sum=0;length=0;
        }
        //Methods
        void initstat();
        void add(double);
        void largest(double);
        void smallest(double);
        double getAverage();
        double getSmallest();
        double getLargest();
        double getSum();
        double getLength();
    private:
        double sum,lNum,smNum,lgNum;
        int length;
};
int main()
{
    infile.open("stat1.txt");
    if(!infile)
    {
        outfile<<"Error opening file";
        return 0;
    }
    outfile.open("results.txt");
    //Declaration
    statistics stat1,stat2;
    //Filling data for statistician 1
    stat1.initstat();
    stat1.add(5.5);
    stat1.add(6.6);
    stat1.add(8.8);
    stat1.add(-3.4);
    stat1.add(-0.5);
    stat1.add(4.7);
    stat1.add(9.1);
    //Reporting data
    outfile<<"The sum for statistician 1 is: "<<stat1.getSum()<<endl;
    outfile<<"The length of statistician 1 is: "<<stat1.getLength()<<endl;
    outfile<<"The average of statistician 1 is: "<<stat1.getAverage()<<endl;
    //Empty Data for statistician 2
    stat2.initstat();
    outfile<<"The sum for empty set statistician 2 is: "<<stat2.getSum()<<endl;
    outfile<<"The length of empty set statistician 2 is: "<<stat2.getLength()<<endl;
    outfile<<"The average of empty set statistician 2 is: "<<stat2.getAverage()<<endl;
    //Populated Data for statistician 2
    stat2.add(103);
    stat2.add(821);
    stat2.add(871);
    stat2.add(487);
    stat2.add(312);
    stat2.add(245);
    stat2.add(224);
    stat2.add(623);
    stat2.add(424);
    stat2.add(432);
    outfile<<"The sum for populated statistician 2 is: "<<stat2.getSum()<<endl;
    outfile<<"The length of populated statistician 2 is: "<<stat2.getLength()<<endl;
    outfile<<"The average of populated statistician 2 is: "<<stat2.getAverage()<<endl;
    //Erasing statistician 2 and printing
    stat2.initstat();
    outfile<<"The sum for erased statistician 2 is: "<<stat2.getSum()<<endl;
    outfile<<"The length of erased statistician 2 is: "<<stat2.getLength()<<endl;
    outfile<<"The average of erased statistician 2 is: "<<stat2.getAverage()<<endl;
    //Again populating statistician 2
    stat2.add(9.3);
    stat2.add(-6.3);
    stat2.add(8.2);
    stat2.add(7.2);
    stat2.add(8.2);
    stat2.add(8.8);
    stat2.add(7.2);
    stat2.add(-3.2);
    stat2.add(7.6);
    stat2.add(9.3);
    outfile<<"The sum for statistician 2 is: "<<stat2.getSum()<<endl;
    outfile<<"The length of statistician 2 is: "<<stat2.getLength()<<endl;
    outfile<<"The average of statistician 2 is: "<<stat2.getAverage()<<endl;
    //Printing out lowest/highest and average.. I think this is what you are asking for?
    outfile<<"The average is: "<<stat2.getAverage()<<" from "<<stat2.getSmallest()<<" to "<<stat2.getLargest()<<endl;

}
//Methods
void statistics::add(double num)
{
    length++;
    sum+=num;
    lNum=num;
    smallest(num);
    largest(num);
}
void statistics::initstat()
{
    length=0;
    sum=0;
}
void statistics::smallest(double num)
{
    if(length!=0)
    {
        if(num<smNum||length==1)
        {
            smNum=num;
        }
    }
}
void statistics::largest(double num)
{
    if(length!=0)
    {
        if(num>lgNum)
        {
            lgNum=num;
        }
    }
}
double statistics::getAverage()
{
    float avg=0;
    if(sum!=0)
    {
        avg=sum/length;
    }
    return avg;
}
double statistics::getSmallest()
{
    return smNum;
}
double statistics::getLargest()
{
    return lgNum;
}
double statistics::getSum()
{
    return sum;
}
double statistics::getLength()
{
    return length;
}
