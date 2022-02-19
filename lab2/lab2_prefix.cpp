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
string reverse(string expr)
{
    string rev;
    int l=expr.length();
    for (int i=0;i<l;i++)
    {
        rev+=expr[l-1-i];
    }
    return rev;
}
string convert_to_prefix(string expr)
{
    string prefix;
    Stck<char> s;
    char c;
    expr=reverse(expr);
    for (int i=0;i<expr.length();i++)
    {
        if (expr[i]=='(')
            expr[i]=')';
        else if(expr[i]==')')
            expr[i]='(';
    }
    for(int i=0;i<expr.length();i++)
    {
        c=expr[i];
        if (c>='a'&&c<='z'||c>='A' && c<='Z'||c>='0'&&c<='9')
            prefix+=c;
        else if(c=='(')
            s.push(c);
        else if(c==')')
        {
            while (s.getTop()!=')' && (!s.isEmpty()))
            {
                prefix+=s.getTop();
                s.pop();
            }
            if(s.getTop()=='(') s.pop();
        }
        else if(check_operator(c))
        {
            if (s.isEmpty())
                s.push(c);
            else if(check_precedence(c)>check_precedence(s.getTop()))
                s.push(expr[i]);
            else if(check_precedence(c)==check_precedence(s.getTop())&&expr[i]=='^')
            {
                // while (check_precedence(c)==check_precedence(s.getTop())&&expr[i]=='^')
                //     prefix+=s.pop();
                s.push(c);
            }
            else
            {
                while(!s.isEmpty()&&(check_precedence(c)<check_precedence(s.getTop())))
                    prefix+=s.pop();
                s.push(c);
            }
        }
    }
    while(!s.isEmpty())
        prefix+=s.pop();
    return reverse(prefix);
}
int main()
{
    string e1="a+b*(c+d)";
    cout<<convert_to_prefix(e1);
}