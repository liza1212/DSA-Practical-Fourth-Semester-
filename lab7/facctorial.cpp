#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int fact_using_tail(int n, int result=1)
{
    if(n==0)
        return result;
    else
        return (fact_using_tail(n-1,result*n));
}

int fact_using_non(int n)
{
    if(n==1)
        return 1;
    else    
        return n*fact_using_non(n-1);
}

int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<"USing tail: "<<fact_using_tail(n)<<endl;
    cout<<"Using non tail: "<<fact_using_non(n)<<endl;
}