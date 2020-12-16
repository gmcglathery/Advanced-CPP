/*********************************************************************
*   Greg McGlathery
*   CS372 Link List
*   This program manages a buffer of various sizes.  It will
*   determine the most efficient buffer size in regards to having to
*   accessing memory.
*********************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

ifstream infile;
ofstream outfile;

typedef string ET;

class LList
{
public:
    string val;
    LList *linky;
};

//Typedef LList for creating pointers
typedef LList *Node;
Node head,tail;
int toMem=0;


//Function Prototypes
void printLL(LList *cp);
void printRev(LList *cp);
void insert(string s1);
LList *newNode();
void solveIt();
void deleteNode(LList *cp,LList *n);

int main()
{
    string s1;
    int cnt=0;
    infile.open("values.txt");
    if(!infile)
    {
        cout<<"Error opening file.";
        return 0;
    }

    //Change cnt to the buffer size you want to execute with
    while(cnt<4)
    {
        infile>>s1;
        insert(s1);
        cnt++;
    }

    //Output
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"The buffer size is: "<<cnt<<endl;
    //While the infile is open, we loop our function to manage the buffer
    while(infile.good())
    {
        solveIt();
    }
    cout<<endl<<"Number of times memory was accessed: "<<toMem<<endl<<endl;
    cout<<"Last four variables: ";
    printLL(head);
    cout<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<endl<<endl;
    //And reverse for Recursion
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"In reverse for Recursion Homework"<<endl<<endl;
    printRev(head);
    cout<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;

    //For housekeeping
    infile.close();

    return 0;
}
//Create a new node
LList *newNode()
{
    LList *temp;
    temp= new LList();
    temp->val='0';
    temp->linky=NULL;
    return temp;
}
//Insert function.
void insert(string s1)
{
    Node c,p,temp;
    //Checks to see if there is a link list, if no, creates one and assigns value
    if(!head)
    {
        head=newNode();
        head->val=s1;
    }
    //If there is a list, will insert node at end
    else
    {
        c=head;
        while(c)
        {
            p=c;
            c=c->linky;
        }
    }
    temp=newNode();
    temp->val=s1;
    p->linky=temp;
    tail=temp->linky;
};
//Function for managing the buffer
void solveIt()
{
    Node c=head;Node t=head;
    string s1; int cnt=0;
    infile>>s1;
    //I used a count to check if the value read in was already in the buffer
    while(c)
    {
        //If value is present, increment counter for switch statement
        if(c->val==s1)
        {
            cnt++;
        }
        //Traverses the buffer until the end or value is found
        c=c->linky;
    }
    //Switch statement for case of value present and value not present
    switch(cnt)
    {
        //If value is not in buffer, we bump head to remove oldest value
        //Then we insert value "s1" to end of buffer, making it newest
    case 0:
        head=t->linky;
        insert(s1);
        toMem++;
        break;
        //This case is for if the value is already in the buffer
    case 1:
        //Reset pointers
        c=head; t=head;
        while(c)    //Same as (c!=NULL)
        {
            //First condition.  If we traverse through the list to find
            //The target value is the last (newest) value, we do nothing
            //As there is no shuffling needed.
            if(c->linky==NULL)
            {
                break;
            }
            //Second condition.  This simply checks to see if the value
            //to be inserted is in the link list, but NOT the first (oldest)
            //value in the buffer.
            else if(head->val==c->val&& head!=c)
            {
                head=t->linky;
                insert(s1);

            }
            //Last condition.  After going through conditions 1 and 2, The last
            //possible instance is that the value(s1) is in the link list, but not
            //at the head position and not at the end of the LList.  At this point,
            //we simply delete the node that has the target value, shuffle everything
            //down with the deleteNode() function, and reinsert s1 at the end of the
            //link list.
            else if(c->val==s1)
            {
                deleteNode(t,c);
                insert(s1);
            }
            c=c->linky;
        }
        break;
    }
}
//Function to print LList
void printLL(LList *cp)
{
    while(cp)
    {
        cout<<cp->val<<" ";
        cp=cp->linky;
    }
}
//Recursive function to print remaining variables in reverse
void printRev(LList *cp)
{
    if(cp==NULL)
        return;
    printRev(cp->linky);
    cout<<cp->val<<" ";
}
//This function will delete the current node and shuffle
//remaining nodes down.
void deleteNode(LList *cp,LList *n)
{
    //Checking for LList
    if(head==n)
    {
        if(head->linky==NULL)
        {
            return;
        }
        // Copy the data of linky node to head
        head->val=head->linky->val;
        // store address of linky node
        n=head->linky;
        // Remove the link of linky node
        head->linky=head->linky->linky;
        // free memory
        free(n);
        return;
    }
    //Find the previous node
    Node prev=head;
    while(prev->linky!=NULL&&prev->linky!=n)
    {
        prev=prev->linky;
    }
    //Check if node really exists in Linked List
    if(prev->linky==NULL)
    {
        cout << "\nGiven node is not present in Linked List";
        return;
    }
    //Remove node from Linked List
    prev->linky = prev->linky->linky;
    //This is a neat little function I discovered to free memory
    free(n);
    return;
}
