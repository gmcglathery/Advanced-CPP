/*****************************************
*Greg McGlathery
*CS 372 Stack Programs Template
*****************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "list.h"

using namespace std;

ofstream outfile;
ifstream infile;

int main()
{
    int choice;
    cout<<"Enter choice for report:"<<endl;
    cout<<"Enter 1 for test.txt."<<endl;
    cout<<"Enter 2 for Stack3Data."<<endl;
    cout<<"Enter 3 for ListClassData."<<endl;
    cout<<"Enter 4 to exit."<<endl;
    cin>>choice;

    switch(choice)
    {
        case 1:
            infile.open("test.txt");
            break;
        case 2:
            infile.open("stack3.txt");
            break;
        case 3:
            infile.open("listclassdata.txt");
            break;
        case 4:
            return 0;
        default:
            cout<<"Enter a correct Value"<<endl;
    }

    if(!infile)
    {
        cout<<"File did not open, please try again."<<endl;
        return 0;
    }

    outfile.open("results.txt");

    char input;
    int amount=0;
    int amount2=0;

    Stack<char> s1;

    while(infile)
   {
        infile>>input;
        if(input=='(' || input=='[' || input=='{' || input=='<')
        {
            s1.push(input);
            outfile<<input;
            amount++;
        }

        if(input==')')
        {
            outfile<<input;
            if(s1.top()=='(')
            {
                s1.pop();
                amount2++;
            }
        }
        if(input==']')
        {
            outfile<<input;
            if(s1.top()=='[')
            {
                s1.pop();
                amount2++;
            }
        }
        if(input=='}')
        {
            outfile<<input;
            if(s1.top()=='{')
            {
                s1.pop();
                amount2++;
            }
        }
        if(input=='>')
        {
            outfile<<input;
            if(s1.top()=='<')
            {
                s1.pop();
                amount2++;
            }
        }
   }
   outfile<<endl;

   if(amount-1==amount2)
   {
       outfile<<"The strings are matched"<<endl;
   }
   else
   {
       outfile<<"The strings are mismatched"<<endl;
   }

    infile.close();
    outfile.close();
    return 0;
}
