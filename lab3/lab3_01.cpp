#include <iostream>
#define size 100
using std::cout;
using std::cin;
using std::endl;
using std::string;
//#include <>
template <class T>
class queue
{
private:
    T q[size];
    int front,rear;
public:
    queue()
    {
        front=rear=-1;
    }
    bool isFull()
    {
        if (rear>size)
            return true;
        else 
            return false;
    }
    void enqueue(T item)
    {
        try
        {
            if(isFull())
                throw 1;
            else
            {
                if (front==-1 && rear==-1)
                {
                    front=0;
                    rear=0;
                }
                else 
                    rear++;
                q[rear]=item;
            }
        }
        catch(int)
        {
            std::cerr <<"Queue overflow (full)!!!" << '\n';
        }
        
    }
    T dequeue()
    {
        T item;
        try
        {
            if(front<0)
                throw 1;
            else if(front>rear) 
                throw 'a';
            else
            {
                item=q[front];
                front++;
            }
        }
        catch(int)
        {
            std::cerr <<"Queue underflow (empty)!!!" << '\n';
        }
        catch(char)
        {
            std::cerr<<"front has exceeded the rear."<<endl;
        }
        return item;
    }
};
int main()
{
    queue<char> ab;
    ab.enqueue('a');
    ab.enqueue('b');
    cout<<"printint the dequeue elements:"<<endl;
    cout<<ab.dequeue()<<endl;
    cout<<ab.dequeue()<<endl;
    ab.dequeue();
}