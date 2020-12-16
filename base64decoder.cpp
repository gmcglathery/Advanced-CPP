/************************************************************
* Greg McGlathery
* base64 Decoder
* This program takes a base64 encode and decodes it
* The program was written with certain constraints in place
* that made it difficult to solve the problem efficiently
************************************************************/

#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <stack>
#include <fstream>

using namespace std;

ofstream outfile;
ifstream infile;

void printIt(char ary[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<ary[i];
    }
}

int toBin(int bin, int ary[],int size);

char asc[64]={65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,48,49,50,51,52,53,54,55,56,57};
char ary[64]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9','+','/'};
int ary2[64]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63};

int main()
{
    outfile.open("results.txt");

    char dummy;

    infile.open("encoded.txt");
    if(!infile)
    {
        cout<<"Error opening file";
        return 0;
    }

    char myAry[1000];
    int myAry2[1000];
    int myAry3[1000];
    char myAry4[1000];
    int myAry5[1000];
    char myAry6[1000];

    int size=0; int cnt=0; int count=0;

    while(infile>>myAry[size])
    {
        size++;
    }

    int n=0;
    for(int i=0;i<size;i++)
    {
        char dummy=myAry[i];
        for(int k=0;k<64;k++)
        {
            if(ary[k]==dummy)
            {
                myAry2[n]=k;
                n++;
            }
        }
    }

    for(int i=0;i<size;i++)
    {
        int enc=myAry2[i];
        myAry3[i]=ary2[enc];
    }

    int l=0;int j=0;string s="";string s2="";
    for(int i=0;i<size*8;i++)
    {
        cnt=0;
        int dum=myAry3[j];
        while(cnt<6)
        {
            if(dum%2==0)
            {
                s+='0';
                i++;
            }
            if(dum%2==1)
            {
                s+='1';
                i++;
            }
            dum/=2;
            cnt++;
        }
        reverse(s.begin(),s.end());
        s2+=s;
        s="";
        j++;
    }

    int val=0;int power=7;j=0;int i=0;int g=0;
    //for(int i=0;i<size*8;i++)

    if(s2.length()%6!=0)
    {
        s2+='0';
    }

    while(i<s2.length())
    {
        if(s2[i]=='0')
        {
            power--;
            i++;
            j++;
        }
        if(s2[i]=='1')
        {
            val+=pow(2,power);
            power--;
            i++;
            j++;
        }
        if(j==8)
        {
            cout<<char(val);
            outfile<<char(val);
            val=0;
            power=7;
            j=0;
        }
    }

    return 0;
}
