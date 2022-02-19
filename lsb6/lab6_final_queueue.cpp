#include <iostream>

using std::cout;
using std::cin;
using std::endl;

template <class T>
class s_linked_list
{
private:
    struct q_using_list
    {
        T data;
        q_using_list* next;
    }
    *front=NULL, *rear=NULL;
public:
    void enqueue_insertend(T item)
    {
        q_using_list* temp;
        temp=new q_using_list;
        temp->data=item;
        temp->next=NULL;
        if(front==NULL) //when adding the first element in the queue
        {
            front=rear=temp;
        }
        else
        {
            rear->next=temp;
            rear=temp;  //we're inserting at the end
            rear->next=NULL;
        }
    }
    // insert beg ani delete ened garna mildina?
    T dequeue_delete()
    {
        q_using_list* temp;
        temp=front;
        if (rear==NULL ||front==NULL)
        {
            cout<<"UNDERFLOLWW!!"<<endl;
            exit(1);
        }
        else
        {
            front=front->next; //deleting from the brginning for FIFO
        }
        return temp->data;
        delete temp;
    }
    void display()
    {
        q_using_list* temp=front;
        cout<<"The list elements are: "<<endl;
        while(temp!=NULL)
        {
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }
};
int main()
{
    s_linked_list<int> s1;
    s1.enqueue_insertend(12);
    s1.enqueue_insertend(34);
    s1.enqueue_insertend(345);
    s1.display();
    cout<<"Displaying the sequence of deletion of items from the queue: "<<endl;
    cout<<s1.dequeue_delete()<<endl;
    cout<<s1.dequeue_delete()<<endl;
    cout<<s1.dequeue_delete()<<endl;
    cout<<s1.dequeue_delete()<<endl;
}