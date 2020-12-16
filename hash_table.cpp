#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

ofstream outfile;
ifstream infile;

int cnt=0, limit;

class HashTable{
public:


    HashTable();
    int power(int, int);
    int findhash(string, string);
    void insert(int, int&);
    void print();
    string searchHash(string);
    void build();
    void buildLists();
    void printCombo();
    void printDupe();
    int digSum(int);
    int createHash(int);
    void buildTable();
    void printTable();

private:
    static const int max=61;
    struct Node
    {
        int number;
        Node *linky;
    };
    Node *table[max];
    Node *combo;
    Node *dupe;
    Node *table2[17];
    int search(Node *, int );
    int search2(int targ);

void InsertCombo(Node *c, int targ)
{
    Node *t;
    Node *p;
    p=NULL;
    while(c)
    {
        p=c;
        c=c->linky;
    }
    t=new Node;
    t->number=targ;
    t->linky=c;
    if(p)
    {
        p->linky=t;
    }
    else
    {
        combo=t;
    }
}

void Insertdupe(Node *c, int targ)
{
    Node *t;
    Node *p;
    p=NULL;
    while(c)
    {
        p=c;
        c=c->linky;
    }
    t=new Node;
    t->number=targ;
    t->linky=c;
    if(p)
    {
        p->linky=t;
    }
    else
    {
        dupe=t;
    }
}

};

HashTable::HashTable()
{
    for(int x=0; x<max; x++)
    {
        table[x]=new Node;
        table[x]->number=NULL;
        table[x]->linky= NULL;
    }
    for(int x=0; x<17; x++)
    {
        table2[x]=new Node;
        table2[x]->number=NULL;
        table2[x]->linky= NULL;
    }
    combo=new Node;
    combo->number=NULL;
    combo->linky= NULL;
    dupe=new Node;
    dupe->number=NULL;
    dupe->linky= NULL;
}

int main()
{
    infile.open("ListOf3.txt");
    outfile.open("results.txt");

    int num;
    HashTable list;

    cout << endl;
    list.build();
    list.buildLists();
    cout << "Original List: " ;
    cout << endl;
    list.print();
    cout << endl;
    cout << "Combo List: ";
    list.printCombo();
    cout << endl;
    cout << "Dupe List: ";
    list.printDupe();
    cout << endl;
    list.buildTable();
    cout << endl;
    cout << "Collisions: ";
    cout << cnt;
}

void HashTable::build()
{
    int x=0, y;
    while(infile >> y)
    {
        if(table[x]->number==NULL)
        {
            table[x]->number=y;
        }
        else
        {
            Node *p=table[x];
            Node *t=new Node;
            t->number=y;
            t->linky=NULL;

            while(p->linky)
            {
                p=p->linky;
            }
            p->linky=t;
        }
        char b;
        if(infile.peek()=='\n')
        {
            x++;
            limit++;
        }
    }
    limit++;
}

void HashTable::buildLists()
{
    int x=0, y, test;
    while(x<limit)
    {
        Node *c=table[x];
        if(c->linky)
        {
            while(c->linky)
            {
                y=c->number;
                test=search(combo, y);
                if(test==1)
                {
                    InsertCombo(combo, y);
                }
                else
                {
                    test=search2(y);
                    if(test==1)
                    {
                        test=search(dupe, y);
                        if(test==1)
                        {
                            Insertdupe(dupe, y);
                        }
                    }
                }
                c=c->linky;
                if(c->linky==NULL)
                {
                    y=c->number;
                    test=search(combo, y);

                    if(test==1)
                    {
                        InsertCombo(combo, y);
                    }
                    else
                    {
                        test=search2(y);
                        if(test==1)
                        {
                            test=search(dupe, y);
                            if(test==1)
                            {
                                Insertdupe(dupe, y);
                            }
                        }
                    }
                }
            }
        }
        x++;
    }
}

void HashTable::print()
{
    int x=0;
    while(x<limit)
    {
        Node *c=table[x];
        if(c->linky)
        {
            while(c->linky)
            {
                cout << c->number << " ";
                c=c->linky;
            }
        }
        cout << c->number << " ";
        x++;
        cout << endl;
    }
}

void HashTable::printCombo()
{
    Node *c=combo;
    c=c->linky;
    while(c)
    {
        cout << c->number << " ";
        c=c->linky;
    }
}

void HashTable::printDupe()
{
    Node *c=dupe;
    c=c->linky;
    while(c)
    {
        cout << c->number << " ";
        c=c->linky;
    }
}

int HashTable::digSum(int num)
{
    if(num==0)
    {
        return 0;
    }
    return(num % 10 + digSum(num / 10));
}

int HashTable::createHash(int x)
{
    int hash=0, index;
    hash=digSum(x);
    index=hash % 17;
    return index;
}

void HashTable::insert(int number, int &cnt)
{
    int index=createHash(number);
    if(table2[index]->number==NULL)
    {
        table2[index]->number=number;

    }
    else
    {
        cnt++;
        Node *p=table2[index];
        Node *t=new Node;
        t->number=number;
        t->linky=NULL;
        while(p->linky)
        {
            p=p->linky;
        }
        p->linky=t;
    }
}

void HashTable::buildTable()
{
    Node *c=combo;
    c=c->linky;
    while(c)
    {
        int num=c->number;
        insert(num, cnt);
        c=c->linky;
    }
    Node *c2=dupe;
    c2=c2->linky;
    while(c2)
    {
        int num=c2->number;
        insert(num, cnt);
        c2=c2->linky;
    }
}

int HashTable::search(Node *c, int targ)
{
    while(c)
    {
        if(c->number==targ)
        {
            return -1;
        }
            c=c->linky;
        }
        return 1;
}

int HashTable::search2(int targ)
{
    int x=0, z=0;
    while(x<limit)
    {
        int y=0;
        Node *c=table[x];
        if(c->linky)
        {
            while(c->linky)
            {
                if(c->number==targ)
                {
                        y=1;
                    }
                    c=c->linky;
                    if(c->number==targ)
                    {
                        y=1;
                    }
                }
            }
            if(y==1)
            {
                z++;
            }
            x++;
        }
        if(z >= limit)
        {
            return 1;
        }
}
