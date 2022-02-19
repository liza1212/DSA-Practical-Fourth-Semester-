#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int fib_using_non(int n)
{
    if(n<=1)
        return n;
    else    
        return fib_using_non(n-1)+fib_using_non(n-2);
}

int fib_using_tail(int n, int a=0,int b=1)
{
    if(n==0)
        return a;
    if(n==1)
        return b;
    return fib_using_tail(n-1, b, a+b);
}

int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<"USing tail: "<<fib_using_tail(n)<<endl;
    cout<<"Using non tail: "<<fib_using_non(n)<<endl;
}