#include <iostream>
#define size 100

using std::cout;
using std::cin;
using std::endl;
using std::string;

template <class T>
class Stck
{
private:
    T stack[size];
    int top;
public:
    Stck()
    {
        top=-1;
    }
    void push(T a)
    {
        stack[++top]=a;
    }
    T pop()
    {
        return stack[top--];
    }
    T getTop()
    {
        return stack[top];
    }
    bool isEmpty()
    {
        if (top<0)
            return true;
        else 
        return false;
    }
};

char pairof(char c)
{
    if (c==')')
        return '(';
    else if(c=='}')
        return '{';
    else 
        return '[';
}

int main()
{
    string exp;
    cout<<"Enter the string value:";
    cin>>exp;
    char c;
    Stck <char> bracket;
    for (int i;i<exp.length();i++)
    {
        c=exp[i];       //how to do for when it starts with ) or } or ]
        if (c=='('||c=='{'||c=='[')
            bracket.push(c);
        if (c==')'||c=='}'||c==']')
        {
            if (bracket.getTop()==pairof(c))
                bracket.pop();
        }
    }
    if (bracket.isEmpty())
    {
        cout<<"The brackets are balanced."<<endl;
    }
    else 
        cout<<"The brackets are not balanced."<<endl;
}