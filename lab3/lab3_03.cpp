#include <iostream>
#define size 3

using namespace std;

template <class T>
class deque
{
private:
    T q[size];
    int front , rear;
public:
    deque()
    {
        front=rear=-1;
    }
    void insert_at_end(T item)
    {
        try
        {
            if (rear==size-1)
                throw 1;
            else
            {
                rear++;
                q[rear]=item;
            }
        }
        catch(int)
        {
            std::cerr << "Queue is full!! (FULL) while inserting at the end." << '\n';
        }
    }
    void insert_at_begining(T item)
    {
        try
        {
            if(front==0)
                throw 1;
            else
            {
                front--;
                q[front]=item;
            }
        }
        catch(int)
        {
            std::cerr << "Queue is full!! (inserting at the begining)" << '\n';
        }
    }
    T delete_at_end()
    {
        T item;
        try
        {
            if(front==rear)
                throw 1;
            else
            {
                rear=rear-1;
                item=q[rear];
            }
        }
        catch(int)
        {
            std::cerr<<"Queue is empty!! (deleting from the end)"<<endl;
        }
        return item;
    }
    T delete_at_begining()
    {
        T item;
        try
        {
            if (front ==rear)
                throw 1;
            else
            {
                item=q[front];
                front++;
            }
        }
        catch(int)
        {
            std::cerr << "Queue is empty!! (deleting from the begining)" << '\n';
        }
        return item;
    }
    void print_contents()
    {
        for (int i=0;i<size;i++)
        {
            cout<<i<<":    "<<q[i]<<endl;
        }
    }
};

int main()
{
    deque<char> d1;

    d1.insert_at_end('b');
    d1.insert_at_end('c');
    d1.insert_at_end('d');
    d1.insert_at_begining('g');
    cout<<d1.delete_at_begining()<<endl;
    cout<<d1.delete_at_end()<<endl;
    cout<<d1.delete_at_end()<<endl;
    
    //d1.print_contents();
}