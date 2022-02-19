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

int check_precedence(char c)
{
    if (c=='^')
        return 3;
    else if(c=='*'||c=='/')
        return 2;
    else if (c=='+'||c=='-')
        return 1;
    else if(c=='('||c==')')
        return 12;
    else
    return 34;
}

bool check_operator(char c)
{
    return (c=='^'||c=='/'||c=='*'||c=='+'||c=='-');
}
int main()
{
    string exp;
    char c;
    int p_of_top_of_stack;
    int p_of_incoming;
    Stck<char> operatorr;
    cout<<"Enter the postfix expression: ";
    cin>>exp;
    cout<<"The postfix expression is:";
    int l=exp.length();
    exp[l]=')';
    exp[l+1]='\0';
    for (int i=0;i<exp.length();i++)
    {
        c=exp[i];
        if (!check_operator(c))
            cout<<c<<endl;
        else
        {
            cout<<"Is operator"<<endl;
            if (operatorr.isEmpty())
            {
                cout<<"pushing (  when the stack is empty."<<endl;
                operatorr.push('(');
                operatorr.push(c);
                cout<<operatorr.getTop();
            }
            else
            {
                cout<<"When the stack is not empty"<<endl;
                p_of_incoming=check_precedence(c);
                p_of_top_of_stack=check_precedence(operatorr.getTop());
                // while(p_of_incoming<=p_of_top_of_stack || p_of_top_of_stack!=12)//for the end of stck
                // {
                //     if (p_of_incoming>p_of_top_of_stack)
                //     {    operatorr.push(c);
                //         cout<<"When incoming is higher than the top of stack then pushin the value in the stack"<<endl;
                //     }
                //     else if(p_of_incoming<p_of_top_of_stack)
                //     {
                //         cout<<operatorr.pop();
                //         cout<<"When the incoming has lower precdence than the top of the stack then should print teh value"<<endl;
                //     }
                // }
                
            }
        }
    }
}