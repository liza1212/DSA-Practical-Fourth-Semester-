#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct node
{
    int data;
    node *next;
}*start=NULL;

class stck_l_list
{
public:
    stck_l_list()
    {}
    node* create(int num)
    {
        node* temp=new node;
        if (temp==NULL)
        {
            cout<<"OVERFLOW!!!"<<endl;
            exit(1);
        }
        else
        {
            temp->data=num;
            temp->next=NULL;
        }
        return temp;
    }
    void push(int num)
    {
        node* new_node;
        new_node=create(num);
        new_node->next=start;
        start=new_node;
    }
    int pop()
    {
        if (!start)
        {
            cout<<"UNDERFLOW!!!"<<endl;
            exit(1);
        }
        node* temp;
        temp=start;
        int a;
        a=start->data;
        start=start->next;
        delete temp;
        return a;
    }
};
int main()
{
    stck_l_list s1;
    s1.push(12);
    cout<<s1.pop();
}
