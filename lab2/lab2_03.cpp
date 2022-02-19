#include <iostream>
#define size 100
using namespace std;
template <class T>
class stack
{
private:
    T Stack[size];
    int top;
public:
    stack()
    {
        top=-1;
    }
    void push(T a)
    {
            Stack[++top]=a;
    }
    T pop()
    {
       return Stack[top--];
    }
};
bool check_operator(char c)
{
    return (c=='^'||c=='/'||c=='+'||c=='*'||c=='-');
}
int main()
{
    stack<int> s;
    string val;
    char c;
    int a;
    int opA, opB;
    cout<<"Enter the postfix expression:";
    cin>>val;
    int l=val.length();
    for (int i=0;i<l;i++)
    {
        c=val[i];
        if (c>='0' && c<='9')
            s.push(c-'0');
        else if(check_operator(c))
        {
            opA=s.pop();
            opB=s.pop();
            switch (c)
            {
                case '+':
                    s.push(opA+opB);
                    break;
                case '-':
                    s.push(opA-opB);
                    break;
                case '*':
                    s.push(opA*opB);
                    break;
                case '/':
                    s.push(opA/opB);
                    break;
                case '^':
                    for (int i=0;i<opB;i++)
                    {
                        a=a*opA;
                    }
                    s.push(a);
                    break;
                default:
                    break;
            }
        }
    }
    cout<<"The result is:"<<s.pop();
}