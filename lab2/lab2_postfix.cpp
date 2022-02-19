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
    else
    return -1;
}

bool check_operator(char c)
{
    return (c=='^'||c=='/'||c=='*'||c=='+'||c=='-');
}

string convert_postfix(string expr)
{
    Stck <char> s;
    string postfix;
    for(int i=0;i<expr.length();i++)
    {
        //if(expr[i]>='a' && expr[i]<='z'||expr[i]>='A'&&expr[i]<='Z'||expr[i]>='0'&&expr[i]<='9' ) ///why this line??
        if(expr[i]>='0'&&expr[i]<='9' ) ///why this line??
            postfix+=expr[i];
        else if(expr[i]=='(')
            s.push(expr[i]);
        else if(expr[i]==')')
        {
            while(s.getTop()!='(' && (!s.isEmpty()))
            {
                postfix+=s.pop();
            }
            if (s.getTop()=='(');
                s.pop(); //because postfix ma parenthesis haru hudaina
        }
        else if(check_operator(expr[i]))
        {
            if (s.isEmpty())
                s.push(expr[i]);
            else if(check_precedence(expr[i])>check_precedence(s.getTop()))
                s.push(expr[i]);
            else if (check_precedence(expr[i])==check_precedence(s.getTop()) && expr[i]=='^')
                s.push(expr[i]);
            else
            {
                while (!s.isEmpty() && (check_precedence(expr[i])<=check_precedence(s.getTop())))
                {
                    postfix+=s.pop();
                }
                s.push(expr[i]);
            }

        }
    }
    while(!s.isEmpty()) postfix+=s.pop();
    return postfix;
}
int main()
{
    string inf;
    cout<<"Enter the infix string:";
    cin>>inf;
    cout<<"THe postfix expression is:"<<convert_postfix(inf)<<endl;
}