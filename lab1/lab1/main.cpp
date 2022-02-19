/*
#include <iostream>
#define size 100
using namespace std;

template <class T>
class Stack
{
private:
    T stack[size];
    int top;
public:

    Stack()
    {
        top=-1;
    }
    bool isEmpty()
    {
        if (top<=-1)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if(top>=(size-1))
            return true;
        else
            return false;
    }
    void push(T item)
    {
        try
        {
            if(isFull())
                throw 1;
            else
                stack[++top]=item;
        }
        catch (int)
        {
            cerr<<"Stack is full!!!"<<endl;
        }
    }
    T pop()
    {
        try
        {
            if (isEmpty())
                throw 123;
            else
                return stack[top--];
        }
        catch (int)
        {
            cerr<<"Stack is empty!!!"<<endl;
        }
    }
};
int main()
{
    Stack<char> s;
    s.push('a');
    s.push('b');
    s.push('c');
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    return 0;
}
*/
