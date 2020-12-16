/************************************************************
* Greg McGlathery
* base64 Encoder
* This program takes a user input as string and encodes
* to base64.
************************************************************/

#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <stack>
#include <fstream>

using namespace std;

void printIt(stack<char> myStack)
{
    while(!myStack.empty())
    {
        cout<<myStack.top();
        myStack.pop();
    }
}

ofstream outfile;

int main()
{
    outfile.open("encoded.txt");

    string s;
    stack<char> myStack;
    stack<char> myStack2;
    stack<char> myStack3;
    string sixty4="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    int cnt=0;int i=0;
    cout<<"Enter string for encoding: ";
    getline(cin,s);
    int size=s.size();

    for(i=0;i<size;i++)
    {
        while(cnt<8)
        {
            if(s[i]%2==0)
            {
                myStack.push('0');
                s[i]/=2;
                cnt++;
            }
            else
            {
                myStack.push('1');
                s[i]/=2;
                cnt++;
            }
            if(cnt==8)
            {
                while(!myStack.empty())
                {
                    myStack2.push(myStack.top());
                    myStack.pop();
                }
            }
        }
        cnt=0;
    }

    while(!myStack2.empty())
    {
        myStack3.push(myStack2.top());
        myStack2.pop();
    }

    int count=0;

    while(!myStack3.empty())
    {
        int val=0;int power=5;
        for(int i=0;;i++)
        {
            if(myStack3.top()=='0')
            {
                power--;
            }
            if(myStack3.top()=='1')
            {
                val+=pow(2,power);
                power--;
            }
            if(i==5)
            {
                cout<<sixty4[val];
                outfile<<sixty4[val];
                i=-1;
                val=0;
                power=5;
                count++;
            }
            myStack3.pop();
            if(myStack3.empty())
            {
                if(count>0)
                {
                    while(count<=8)
                    {
                        count++;
                    }
                }
                cout<<sixty4[val];
                outfile<<sixty4[val];
                return 0;
            }
        }
    }

    outfile.close();
    return 0;
}
