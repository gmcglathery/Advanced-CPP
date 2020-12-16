/*********************************************************************
*   Greg McGlathery
*   CS372 Recursion
*   Various problems solved using recursion
*********************************************************************/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

ofstream outfile;

//Prototypes
int numDig(int);
int printReverse(int);
void printAry(int[],int);
void reverseAry(int[],int,int);
int sumAry(int[],int);
int location(int[],int,int,int);
int gcd(int,int);
int hailstones(int);
void fillAry1(int[],int,int);
void fillAry2(int[],int,int);
void fillAry3(int[],int);
int stringConv(int,int,char[]);
void run(int,float,int,int);

int main()
{

    const int SIZE1 = 5;
    const int SIZE2 = 32;
    const int SIZE3 = 13;

    int ary2[SIZE2];
    int ary3[SIZE2];
    int ary4[SIZE3];

    cout<<"The number of digits in 345: "<<numDig(345)<<endl;
    cout<<"The reverse of 123 is: "<<printReverse(345)<<endl;

    int ary1[] = {1,2,3,4,5};

    cout<<"Original array:\n";  printAry(ary1,SIZE1); cout<<endl;
    cout<<"Reverse of array:\n"; reverseAry(ary1,0,SIZE1-1); printAry(ary1, SIZE1); cout<<endl;
    cout<<"Sum of the Array: "<<sumAry(ary1,SIZE1-1)<<endl;
    cout<<"Location of 4 in the array: Position "<<location(ary1,0,SIZE1-1,4)<<endl;
    cout<<endl;
    cout<< "GCD of 15387 and 7713249: "<<gcd(15387,7713249)<<endl;
    cout<<endl;
    cout<<"Hailstones of 1579: "<<hailstones(1579)<<endl;
    cout<<"Hailstones of 113270: "<<hailstones(113270)<<endl;
    cout<<endl;
    cout<<"Array filled with values 1 to 32 in order:\n"; fillAry1(ary2,0,SIZE2); printAry(ary2, SIZE2);
    cout<<endl<<endl;
    cout<<"Array filled with values 1 to 32 in reverse:\n"; fillAry2(ary3,0,SIZE2); printAry(ary3,SIZE2);
    cout<<endl<<endl;
    cout<<"Array with 1 in the middle:\n"; fillAry3(ary4,SIZE3/2); printAry(ary4,SIZE3);
    cout<<endl<<endl;

    char string1[] = "17968375";
    char string2[] = "745423";

    cout<<"Conversion of 17968375 from string to an int: " << stringConv(0,sizeof(string1)-2,string1)<<endl;
    cout<<"Conversion of 745423 from string to an int: "<<stringConv(0,sizeof(string2)-2,string2)<<endl<<endl<<endl;
    cout<<"Problem 9:\n\n";
    cout<<setw(13)<<"Minutes"<<setw(20)<<"Miles Traversed\n";
    run(5, 0.87, 60,1);

    return 0;
}

//This is a recursive function that finds the number of digits in a number
int numDig(int n)
{
    if(n<=0)
        return 0;
    else
        return 1 + numDig(n/10);
}
//Recursively prints a number in reverse order
int printReverse(int n)
{
    if(numDig(n)==1)
        return n;
    else
        return (n%10)*pow(10,(numDig(n)-1))+printReverse(n/10);
}
//Prints array
void printAry(int ary[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<setw(5)<<ary[i];

        if((i+1)%7==0)
            cout<<endl;
    }
    cout<<endl;
}
//Reverses an array recursively
void reverseAry(int ary[],int first,int last)
{
    int temp;

    if(first==last)
        return;
    else
    {
        temp = ary[last];
        ary[last] = ary[first];
        ary[first] = temp;
        reverseAry(ary,first+1,last-1);
    }
}
//Sums an array
int sumAry(int ary[],int n)
{
    if (n==0)
        return ary[n];
    else
        return ary[n] + sumAry(ary,n-1);
}
//Traverses array and finds position recursively
int location(int ary[],int first,int last, int elm)
{
    if(ary[first]==elm)
        return first;
    else if(ary[last]==elm)
        return last;

    else if(first==last)
        return 0;

    else
        return location(ary,first+1,last-1,elm);
}
//Finds GCD of two numbers
int gcd(int a,int b)
{
    if(a<0)
        a=-1*a;
    if(b<0)
        b=-1*b;

    int q=a/b;
    int r=a-(b*q);

    if(r==0)
        return b;
    else
        return gcd(b,r);
}
int hailstones(int n)
{
    if(n==1)
        return 0;

    else if(n%2==0)
        return 1+hailstones(n/2);

    else
        return 1+hailstones((3*n)+1);
}
//Recursive function to fill an array
void fillAry1(int ary[],int n,int s)
{
    if(n==s)
        return;
    else
    {
        ary[n]=n+1;
        fillAry1(ary,++n,s);
    }
}
//Recursive function to fill an array backwards
void fillAry2(int ary[],int n,int s)
{
    if(n==s)
        return;
    else
    {
        ary[n]=s-n;
        fillAry2(ary,++n,s);
    }
}
//Fill array
void fillAry3(int ary[],int n)
{
    if(n==6)
        ary[n]=1;
    if(n==0)
        return;
    else
    {
        ary[6-n]=(2*n)+1;
        ary[n+6]=(2*n);
        fillAry3(ary,--n);
    }
}
//ASCII to int
int stringConv(int i,int s,char string[])
{
    if(i==s)
        return string[i]-'0';
    else
    {
        return (string[i]-'0')*pow(10,s-i)+stringConv(i+1,s,string);
    }
}
//#9 Run Problem
void run(int m,float d,int max,int i)
{
    cout<<fixed<<showpoint<<setprecision(2);

    if(m==max)
    {
        cout<<setw(10)<<m<<setw(16)<<d<<endl;
        return;
    }
    else
    {
        cout<<setw(10)<<m<<setw(16)<<d<<endl;
        run(m+5,d+(.87-(i*.029)),60,i+1);
    }
}

