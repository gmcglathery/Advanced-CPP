/*Greg McGlathery
Binary Tree Workout */

#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;

ofstream outfile;
ifstream infile;

struct Tree
{
    Tree *lchild;
    int val;
    int cnt;
    Tree *rchild;
};

Tree *root;
Tree* del(Tree*, int);
Tree* minVal(Tree*);
Tree* searchTree(Tree *, int);
Tree* deepestLeaf(Tree*);
Tree* MyNewNode();
void insert(Tree *, int);
void printIt(Tree *, int, int&);
void printItpre(Tree*, int, int&);
void printItpost(Tree*, int, int&);
void numNodes(Tree *, int&);
void sumIt(Tree*, float &);
void bumpCnt(Tree *, int);
void findDLeaf(Tree*, int, int*, bool, Tree**);
void countLeafs(Tree*, float &);
void oneChild(Tree*, float &);
void average(Tree*, float &);
void cntDupes(Tree*, float &);
int digitsumIt(int);
void nineorLess(Tree*);

int main()
{
    infile.open("TreeNbrsV2.txt");
    outfile.open("results.txt");

    if(!infile)
    {
        cout<<"Error opening file";
        return 0;
    }

    int x, cnt=0, cnt2=0, counter=0;
    float tot=0, avg, sum=0;

    while(infile>>x)
    {
        if(searchTree(root, x)){}
        else
        {
            insert(root, x);
        }
    }

    outfile<<"Binary Tree Workout"<<endl;
    outfile<<"1. Inorder: ";
    printIt(root, 20, cnt2);
    outfile<<endl;
    cnt2=0;
    outfile<<"\n2. Preorder: ";
    printItpre(root, 20, cnt2);
    outfile<<endl;
    cnt2=0;
    outfile<<"\n3. Postorder: ";
    printItpost(root, 20, cnt2);
    numNodes(root, cnt);
    outfile<<endl;
    outfile<<"\n4. Nodes in Tree: "<<cnt<<endl;
    sumIt(root, sum);
    avg=sum/cnt;
    outfile<<"\n5. Sum and Average of nodes in Tree: Sum="<<sum<<" Average="<<avg;
    outfile<<endl;
    cntDupes(root, tot);
    outfile<<"\n6. Duplicates: "<<tot<<endl;
    tot=0;
    countLeafs(root, tot);
    outfile<<"\n7. Number of leafs: "<<tot<<endl;
    tot=0;
    oneChild(root, tot);
    outfile<<"\n8. Number of nodes with 1 leaf: "<<tot<<endl;
    Tree* result=deepestLeaf(root);
    outfile<<"\n9. Deepest leaf value in tree: "<<result->val<<endl;

    while(counter<cnt)
    {
        nineorLess(root);
        counter++;
    }
    cnt2=0;
    outfile<<"\n10. Print Tree Inorder after deleting nodes with value < 9: ";
    printIt(root, 20, cnt2);
    outfile<<endl;
    cnt=0;
    numNodes(root, cnt);
    outfile<<"\n11. Number of Nodes in altered Tree: "<<cnt;
    sum=0;
    sumIt(root, sum);
    outfile<<endl;
    outfile<<"\n12. Sum and Average of all nodes in the altered tree: Sum = "<<sum<<" Average = "<<sum/cnt;
    outfile<<endl<<endl;

    infile.close();
    outfile.close();
}

Tree* MyNewNode()
{
    Tree *temp;
    temp=new Tree;
    temp->val=NULL;
    temp->cnt=NULL;
    temp->rchild=NULL;
    temp->lchild=NULL;
    return temp;
}

void insert(Tree *c, int targ)
{
    Tree *p;
    p=NULL;

    while(c)
    {
        p=c;
        if(targ<c->val)
        {
            c=c->lchild;
        }
        else
        {
            c=c->rchild;
        }
    }
    c=MyNewNode();
    c->val=targ;
    c->cnt=1;
    if(!p)
    {
        root=c;
    }
    if(p)
    {
        if(targ<p->val)
        {
            p->lchild=c;
        }
        else
        {
            p->rchild=c;
        }
    }
}

void printIt(Tree *c, int x, int &cnt)
{
    if(c)
    {
        printIt(c->lchild, x, cnt);
        if(cnt<x)
        {
            outfile<<c->val<<" ";
            ++cnt;
        }
        printIt(c->rchild, x, cnt);
    }
}

void printItpre(Tree *c, int x, int &cnt)
{
    if(c)
    {
        if(cnt<x)
        {
            outfile<<c->val<<" ";
            ++cnt;
        }
        printItpre(c->lchild, x, cnt);
        printItpre(c->rchild, x, cnt);
    }
}

void printItpost(Tree *c, int x, int &cnt)
{
    if(c)
    {
        printItpost(c->lchild, x, cnt);
        printItpost(c->rchild, x, cnt);
        if(cnt<x)
        {
            outfile<<c->val<<" ";
            ++cnt;
        }
    }
}

void numNodes(Tree *c, int &tot)
{
    if(!c)
    {
        return;
    }
    numNodes(c->lchild, tot);
    tot++;
    numNodes(c->rchild, tot);
}

void sumIt(Tree *c, float &tot)
{
    if(!c)
    {
         return;
    }
    sumIt(c->lchild, tot);
    if(c->cnt > 1)
    {
        int a;
        a=c->val*(c->cnt--);
        tot += a;
    }
    tot=tot + c->val;
    sumIt(c->rchild, tot);
}

Tree* searchTree(Tree *c, int targ)
{
    while(c && c->val!=targ)
    {
        if(targ<c->val)
        {
            c=c->lchild;
        }
        else
        {
            c=c->rchild;
        }
    }
    if(c)
    {
        if(c->val==targ)
        {
            c->cnt++;
        }
    }
    return c;
}

void bumpCnt(Tree *c, int targ)
{
     if(!c)
    {
        return;
    }
    bumpCnt(c->lchild, targ);
    if(targ==c->val)
    {
        c->cnt++;
    }
    bumpCnt(c->rchild, targ);
}

void findDLeaf(Tree *c, int lvl, int *maxlvl, bool isLeft, Tree **resPtr)
{
    if (!c)
        return;
    if (isLeft && !c->lchild && !c->rchild && lvl > *maxlvl)
    {
        *resPtr=c;
        *maxlvl=lvl;
        return;
    }
    findDLeaf(c->lchild, lvl+1, maxlvl, true, resPtr);
    findDLeaf(c->rchild, lvl+1, maxlvl, false, resPtr);
}

Tree* deepestLeaf(Tree *root)
{
    int maxlevel=0;
    Tree*result=NULL;
    findDLeaf(root, 0, &maxlevel, false, &result);
    return result;
}

void average(Tree *c, float &tot)
{
    if(!c)
    {
         return;
    }
    average(c->lchild, tot);
    if(c->cnt>1)
    {
        int a;
        a=c->cnt-1;
        tot+=a;
    }
    tot++;
    average(c->rchild, tot);
}

void cntDupes(Tree *c, float &tot)
{
    if(!c)
    {
         return;
    }
    cntDupes(c->lchild, tot);
    if(c->cnt > 1)
    {
        int a;
        a=c->cnt-1;
        tot+=a;
    }
    cntDupes(c->rchild, tot);
}

void countLeafs(Tree *c, float &tot)
{
    if(!c)
    {
         return;
    }
    countLeafs(c->lchild, tot);
    if(!c->lchild && !c->rchild)
    {
        tot++;
    }
    countLeafs(c->rchild, tot);
}

void oneChild(Tree *c, float &tot)
{
    if(!c)
    {
         return;
    }
    oneChild(c->lchild, tot);
    if(!c->lchild && c->rchild || c->lchild && !c->rchild)
    {
        tot++;
    }
    oneChild(c->rchild, tot);
}

struct Tree *del(struct Tree *root, int key)
{
    if (!root)
        return root;
    if (key<root->val)
        root->lchild=del(root->lchild, key);
    else if (key > root->val)
        root->rchild=del(root->rchild, key);
    else
    {
        if (!root->lchild)
        {
            struct Tree *temp=root->rchild;
            free(root);
            return temp;
        }
        else if (!root->rchild)
        {
            struct Tree *temp=root->lchild;
            free(root);
            return temp;
        }
        struct Tree *temp=minVal(root->rchild);
        root->val=temp->val;
        root->rchild=del(root->rchild, temp->val);
    }
    return root;
}

struct Tree *minVal(struct Tree *node)
{
    struct Tree *current=node;
    while (current && current->lchild)
        current=current->lchild;
    return current;
}

int digitsumIt(int x)
{
    if(x==0)
    return 0;
    return (x%10+digitsumIt(x/10));
}

void nineorLess(Tree *c)
{
    if(!c)
    {
         return;
    }
    nineorLess(c->lchild);
    int y=c->val;
    int x=digitsumIt(y);
    if(x<9)
    {
        del(root, y);
        return;
    }
    nineorLess(c->rchild);
}
