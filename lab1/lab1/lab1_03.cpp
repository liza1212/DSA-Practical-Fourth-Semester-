#include <iostream>
#define size 100
using std::cout;
using std::cin;
using std::string;
using std::cerr;
using std::endl;
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
bool check_operator(char c)
{
    return (c=='+'||c=='-'||c=='*'||c=='/'||c=='^');
}
int check_precendence(char c)
{
    return ((c=='^')?3:(c=='*'||c=='/')?2:1);
}
void convert_postfix(string exp)
{
    Stack <char> post_operands;
    for (int i=0;i<exp.length();i++)
    {
        if (!check_operator(exp[i]))
            cout<<exp[i];
        else
        {
            if (post_operands.isEmpty())
                post_operands.push(exp[i]);
            else
            {
                int top_of_stack=check_precendence(post_operands.pop());
                int incoming_symbol=check_precendence(exp[i]);
                do
                {

                }
                if (incoming_symbol>top_of_stack)
                    post_operands.push(exp[i]);
                if (incoming_symbol<top_of_stack)
                {
                    cout<<post_operands.pop();
                }

            }
        }
    }
}
int main()
{
    Stack <string> postf;
    string postfix;
    string exp;
    cout<<"Enter a infix expression:";
    cin>>exp;
    convert_postfix(exp);

}



