#include <iostream>
#include <cassert>

using std::cout;
using std::cin;
using std::endl;

struct node
{
    int data;
    node *next;
}*start=NULL;
class c_list
{
private:
public:
    c_list(int num)
    {
        // insert_beg(num);
        node *new_node;
        new_node=create(num);
        //new_node->data=num;
        start=new_node;
        new_node->next=start;
        // start->next=start;
    }
    node *create(int num)
    {
        node *temp;
        temp=new node;
        if(temp==NULL)
        {
            cout<<"OVERFLOW!!!!"<<endl;
            exit(1);
        }
        else
        {
            temp->data=num;
            temp->next=NULL;
        }
        return temp;
    }
    void insert_beg(int num)
    {
        node *new_node;
        new_node=create(num);
            node* ptr=start;
            while(ptr->next!=start)
                ptr=ptr->next;
            new_node->next=start;
            ptr->next=new_node;
            start=new_node;
    }
    void insert_end(int val)
    {
        node* new_node;
        new_node=create(val);
        node* temp;
        temp=start;
        while(temp->next!=start)
            temp=temp->next;
        temp->next=new_node;
        new_node->next=start;
    }
    void insert_after(int aft_this, int val)
    {
        node* new_node;
        new_node=create(val);
        node *ptr=start;
        while(ptr->data!=aft_this)
        {
            if(ptr->next==start)
            {
                cout<<"No such element exists!!! (insert after)"<<endl;
                //return; yha break matra rakhda pani milcha???
                exit(1);
            }
            ptr=ptr->next;
        }
        new_node->next=ptr->next;
        ptr->next=new_node;
    }
    void insert_before(int bef_this, int val)
    {
        node* new_node=create(val);
        node* pre_temp;
        node* temp=start;
        while(temp->data!=bef_this)
        {
            if(temp->next==start)
            {
                cout<<"No such element was found (insert before!!!)"<<endl;
                exit(1);
            }
            pre_temp=temp;
            temp=temp->next;
        }
        new_node->next=temp;
        pre_temp->next=new_node;
    }
    void display()
    {
        node *ptr=start;
        do
        {
            cout<<ptr->data<<endl;
            ptr=ptr->next;
        }while(ptr!=start);
    }
    void delete_beg()
    {
        node* temp,*temp2;
        temp=start;
        while(temp->next!=start)
            temp=temp->next;
        temp2=start;
        temp->next=start->next;
        start=start->next;
        delete temp2;
    }
    void delete_end()
    {
        node *temp=start;
        node *pre_temp;
        while(temp->next!=start)
        {
            pre_temp=temp;
            temp=temp->next;
        }
        pre_temp->next=start;
        delete temp;
    }
    void delete_after(int aft_this)
    {
        node* temp=start;
        while(temp->data!=aft_this)
        {
            if(temp->next==start)
            {
                cout<<"No such elememt exists!!!"<<endl;
                exit(1);
            }
            temp=temp->next;
        }
        node* temp2=temp->next;
        temp->next=temp->next->next;
        delete temp2;
    }
};
int main()
{
    //cout<<"hello"<<endl;
    c_list c1(12);
    c1.insert_beg(200);
    c1.insert_end(900);
    c1.insert_after(12,1000);
    c1.insert_before(900,3);
    cout<<"Displaying the items:"<<endl;
    c1.display();
    c1.delete_beg();
    c1.delete_end();
    c1.delete_after(1000);
    cout<<"Displaying the items(after deleting):"<<endl;
    c1.display();
}
