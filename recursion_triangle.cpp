/*******************************************************************************
* Greg McGlathery                                                              *
* CS 372                                                                       *
* Recursion Triangle                                                           *
*******************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>


using namespace std;

ofstream outfile;

void spaces(char);
void line(char, char, char);
void triangle(char, char, char);

int main()
{
    outfile.open("results.txt");
    char start = 'A';
    char end = 'm';
    char space = 0;
    triangle(start, end, space);
    outfile.close();
    return 0;
}

void spaces(char space)
{
    if (space <= 0)
    {
        return;
    }
    outfile<< " ";
    spaces(space-1);
}

void line(char start, char end, char space)
{
    if (start != end)
    {
        outfile<<start;
        line(start+1, end, space-1);
        outfile<<start;
    }
    else
    {
        outfile<<end;
    }
}

void triangle(char start, char end, char space)
{
    ++space;
    if (start != end)
    {
        triangle(start, end-1, space);
    }
    spaces(space);
    line(start, end, space);
    spaces(space);
    outfile<<endl;
}
