#include <iostream>
#define size 3

using namespace std;

template <class T>
class c_queue
{
private:
    T q[size];
    int front, rear;
public:
    c_queue()
    {
        front=-1;rear=-1;
    }
    bool isFull()
    {
        if(front==0 && rear==(size-1) || front==rear+1)
            return true;
        else 
            return false;
    }
    bool isEmpty()
    {
        if (front==-1)
            return true;
        else
            return false;
    }
    void enqueue(T item)
    {
        try
        {
            if (isFull())
                throw 1;
            else 
            {
                if (front==-1 && rear==-1)
                {
                    front=0;
                    rear=0;
                }
                else if(front!=0 && rear==size+1)
                    rear=0;
                else
                    rear++;
                q[rear]=item;
            }
        }
        catch(int)
        {
            std::cerr << "Circular queue is full!!! (FULL)" << '\n';
        }
        //re
    }
    T dequeue()
    {
        T item;
        try
        {
            if(isEmpty())
                throw 1;
            else
            {
                item=q[front];
            }
            if(front==rear)
            {
                front=-1; //not zero!!! becausse 0 rakhyo vane 0th positio nma empty nai vairakhcha
                rear=-1;
            }
            else if (front==size-1)
            {
                front=0;
            }
            else
            {
                front++;
            }
        }
        catch(int)
        {
            cerr<<"Circular queue underflow!!! (EMPTY)"<<endl;
        }
        return item;
    }
    // void print_contents()
    // {
    //     for (int i=0;i<size;i++) //front to rear
    //     {
    //         cout<<i<<":   "<<q[i]<<endl;
    //     }
    // }
};
int main()
{
    c_queue <char> c1;
    c1.enqueue('a');
    c1.enqueue('b');
    c1.enqueue('c');
    cout<<"Trying to dequeue: "<<endl;
    cout<<c1.dequeue()<<endl;
    cout<<c1.dequeue()<<endl;
    cout<<c1.dequeue()<<endl;
    //cout<<c1.dequeue()<<endl; //mistake becuase it will still print c!!!!
    c1.dequeue(); //circular queue underflow
    c1.enqueue('l');
    c1.enqueue('i');
    c1.enqueue('z');
    c1.enqueue('a');
    cout<<c1.dequeue();  //print contents from front
    cout<<c1.dequeue();
    //c1.print_contents();
}