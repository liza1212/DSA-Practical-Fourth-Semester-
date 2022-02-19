#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void tower_of_hanoi(int n, char source, char extra, char destination)
{
    if(n==1)
    {
        cout<<"Move from "<<source<<" to "<<destination<<endl;
    }
    else
    {
        tower_of_hanoi(n-1, source, extra, destination);
        tower_of_hanoi(1, source, destination, extra);
        tower_of_hanoi(n-1, extra, destination, source);
    }
}

int main()
{
    int n;
    cout<<"Enter the value: "<<endl;
    cin>>n;
    tower_of_hanoi(n, 'a','b','c');

}