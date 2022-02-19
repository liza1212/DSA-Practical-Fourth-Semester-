#include <iostream>
#define size 7

using std::cout;
using std::cin;
using std::endl;

struct node_type
{
    int info;
    int next;
};

class Queue
{
private:
    int front=-1, rear=-1, avail=-1;
    node_type node[size];
    int getnode(void)
    {
        int p;
        if (avail==-1)
        {
            cout<<"OVERFLOW!!!"<<endl;
            exit(1);
        }
        p=avail;
        avail=avail[node].next;
        return p;
    }
    void freenode(int p)
    {
        node[p].next=avail;
        avail=p;
    }
    void init()
    {
        avail=0;
        for (int i=0;i<size-1;i++)
        {
            node[i].next=i+1;
        }
        node[size-1].next=-1;
    }
public:
    Queue()
    {
        init();
    }
    bool empty()
    {
        if(front==-1)
            return true;
        else
            return false;
    }
    void insert(int x)
    {
        int p;
        p=getnode();
        node[p].info=x;
        node[p].next=-1;
        if(rear==-1) //explain this!!!!!!!
            front =p;
        else
            node[rear].next=p;
        rear=p;
    }
    int remove ()
    {
        int p,x;
        if(empty())
        {
            cout<<"UNDERFLOWW!!"<<std::endl;
            exit(1);
        }
        p=front;
        x=node[p].info;
        front=node[p].next;
        if(front==-1)
            rear=-1;
        freenode(p);
        return x;
    }
};

int main()
{
    Queue q;
    for (int i=0;i<7;i++)
    {
        q.insert(i);
    }
    for (int i=0;i<4;i++)
    {
        cout<<q.remove()<<endl;
    }
    return 0;
}