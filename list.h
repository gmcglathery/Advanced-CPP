/**********************************************
*Greg McGlathery
*CS 372 list.h w/Stack Class & Queue Template
**********************************************/


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const int CAP = 75;
typedef char ET;
typedef size_t size_type;

template<typename T>
class List
{
private:
     int pos;
     size_type used;
     T myAry[CAP];

public:

     //default constructor
     List()
     {
          used = 0;
          pos = -1;
     }

     //copy constructor
     List (List &list)
     {
          for (int i = 0; i < list.used; i++)

              myAry[i] = list.myAry[i];

          used = list.used;
          pos = list.pos;
     }

     bool empty()   //empty returns true or false if list is empty or not.
     {
         if(used==0)
         {
             cout<<"empty list";
             return true;
         }

         else
         {
             cout<<"not empty list";
             return false;
         }
     }

     void front()  //makes current position at the beginning of the list
     {
          if (used>0)
          {
              pos=0;
          }
     }

     void last()     //end makes current position at the end of a list.
     {
          if (used>0)
          {
              pos = used-1;
          }
     }

     void prev()  //prev places current position at the previous element in the list
     {
          if (pos > 0)
          {
              pos--;
          }

     }

     void next()  //places current position at the next element in the list
     {
          if (pos < used - 1)
          {
                pos++;
          }
     }

     int getPos()  //returns current position or where you are in the list
     {
          return pos;
     }

     void setPos (int pos_in)  //places current position in a certain position in the list
     {
              pos = pos_in;
     }

     void insertBefore (T ele)  //inserts a new element before the current position
     {
          if (used == 0)
          {
              myAry[0] = ele;
              pos = 0;
              used = 1;
          }
     }

     void insertAfter (T ele, T dummy)  //inserts a new element after the current position
    {
       if (pos >= CAP)
       {
          cout << "Cannot insert a new element, CAP reached." << endl;
       }

       else
       {
          for (int i=pos; i<CAP; i++)
          {
            myAry[pos+1]=ele;
          }

          if (used == 0)
          {
             myAry[pos+1]=ele;
          }

          else
          {
             myAry[pos + 1]=ele;
             pos++;
           }
        used++;
       }
      }

     ET getElement()  //returns the one element that current position is pointing to
     {
              return myAry[pos];
     }

     int size()  //returns the size of the list (number of myAry in list)
     {
          return used;
     }

     void replace(int newEle)  //replace the current element with a new value
     {
          myAry[pos] = newEle;
     }

     void clear()  //makes the list an empty list
     {
          used = 0; pos = -1;
     }

     void erase()  //deletes the current element
     {
          for(int i=getPos();i<used;i++)
          {
              myAry[i] = myAry[i + 1];
          }
          used--;
     }

     bool operator==(List &list)  //comparing two lists if they are equal
     {
          if(list.size()==this->size())
          {
              for(int i=0;i<this->size();i++)
              {
                   list.setPos(i);

                   if(list.getElement()!=myAry[i])
                   {
                        return false;
                   }
              }
              return true;
          }

          else
          {
              return false;
          }
     }

     void operator=(List &list)  //assignment operator
     {
          for (int i = 0; i < list.used; i++)
          {

              myAry[i] = list.myAry[i];
              used = list.used;
              pos = list.pos;
          }
     }

     friend ostream& operator<< (ostream &os, List &list);
};

template<typename T>
ostream& operator<< (ostream &os, List<T> &list)  //to print out in ( , )
{
     for (int i = 0; i < list.used; i++)
     {
              os << list.myAry[i] << endl;
     }
          return os;
}


template<typename T>
class Stack
{
private:
    List<char> myStack;

public:
    Stack();
    void push(char v);
    void pop();
    int size();
    T top();
    bool empty();
    bool test(char input);
    void displayItems();

};
template<typename T>
Stack<T>:: Stack() //default constructor
{
    List<T> myStack;
}
template<typename T>
void Stack<T>:: push(char v)  //adds an item to the Stack
{
    myStack.last();
    myStack.insertAfter(v, 0);
}
template<typename T>
void Stack<T>:: pop()  //removes an item from the Stack
{
    myStack.erase();
}
template<typename T>
int Stack<T>:: size()  //returns the size of the Stack
{
    return myStack.size();
}
template<typename T>
T Stack<T>:: top()  //returns the top element in the Stack
{
    myStack.last();
    return myStack.getElement();
}
template<typename T>
bool Stack<T>:: empty()  //checks if the Stack is empty
{
    return myStack.empty();
}
template<typename T>
class Queue
{
public:
    Queue();
    void enqueue(char v);
    void dequeue();
    T top();
    int size();
    T getElement();
    void next();
    void first();
    void prev();
    int getPos();
    int setPos(int x);
private:
    List<T> myQueue;
};
template<typename T>
Queue<T>::Queue()
{
    List<T> myQueue;
}
template<typename T>
void Queue<T>::enqueue(char v)
{
    myQueue.last();
    myQueue.insertAfter(v,0);
}
template<typename T>
void Queue<T>::dequeue()
{
    myQueue.erase();
}
template<typename T>
T Queue<T>::top()
{
    myQueue.last();
    return myQueue.getElement();
}
template<typename T>
int Queue<T>::size()
{
    return myQueue.size();
}
template<typename T>
T Queue<T>::getElement()
{
    return myQueue.getElement();
}
template<typename T>
void Queue<T>::next()
{
    myQueue.next();
}
template<typename T>
void Queue<T>::first()
{
    myQueue.front();
}
template<typename T>
void Queue<T>::prev()
{
    myQueue.prev();
}
template<typename T>
int Queue<T>::getPos()
{
    myQueue.getPos();
}
template<typename T>
int Queue<T>::setPos(int x)
{
    myQueue.setPos(x);
}
