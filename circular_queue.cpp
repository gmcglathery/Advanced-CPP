/*****************************************
*Greg McGlathery
*CS 372 Circular Queue
*****************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "list.h"
#include <cmath>

using namespace std;

ofstream outfile;
ifstream infile;

void printIt();

int main()
{
    outfile.open("results.txt");
    Queue<char> q1;
    char khar='!';
    int cnt=1;
	for (int i=0; i<CAP; i++)
	{
        q1.enqueue(khar);
        khar++;
	}

	q1.first();
	outfile<<"The suitors line up as follows:"<<endl;
	for(int i=0;i<CAP;i++)
    {
        if(i%15==0)
        {
            outfile<<endl;
        }
        outfile<<q1.getElement()<<"\t";
        q1.next();
    }

    outfile<<endl<<endl;

    outfile<<"Removing every 4th Suitor\n"<<endl;

	q1.first();
	for(int i=0;q1.size()!=1;i++)
    {
        if(cnt==4)
        {
            outfile<<endl<<q1.getElement()<<" is removed from consideration";
            q1.dequeue();
            outfile<<" "<<q1.size()<<" suitors left."<<endl;
            q1.prev();
            cnt=0;
        }
        if(i+1==CAP)
        {
            q1.first();
            i=0;
        }
        cnt++;
        q1.next();
    }

    q1.first();
    outfile<<"\nStar has chosen "<<q1.getElement()<<" as her suitor!";

    outfile.close();
    return 0;
}
