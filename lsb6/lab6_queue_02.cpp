#include <iostream>

using std::cout;
using std::cin;
using std::endl;
template <class T>
class q_linked_list
{
struct node
{
    T data;
    node* next;
} *front=NULL, *rear=NULL;
public:
    // node*create(T num)
    // {
    //     node* new_node;
    //     new_node=new node;
    //     if(new_node)
    //     new_node->data=num;
    //     new_node->next=NULL;
    //}
    void enqueue(T num)
    {
        node* new_node;
        new_node=new node;
        new_node->data=num;
        if(front==NULL)
        {
            front=rear=new_node;
            front->next=rear->next=NULL;
        }
        else
        {
            rear->next=new_node;
            rear=new_node;
            rear->next=NULL;
        }
    }
    T dequeue()
    {
        node* new_node;
        if(front==NULL)
        {
            cout<<"UNDERFLOW!!!"<<endl;
            exit(1);
        }
        new_node=front;
        T f;
        f=front->data;
        front=front->next;
        delete new_node;
        return f;
    }
};

int main()
{
    q_linked_list<int> q1;
    q1.enqueue(23);
    cout<<q1.dequeue();
    cout<<q1.dequeue();
}