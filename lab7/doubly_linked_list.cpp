#include <iostream>

using std::cout;
using std::cin;
using std::endl;

template<class T>
class doubly_linked_list
{
private:
    struct Node
    {
        T data;
        Node* prev=NULL;
        Node* next=NULL;
    };
    Node* start;
public:
    doubly_linked_list()
    {
        start=NULL;
    }
    void insert_beg(T item)
    {
        Node* new_node=new Node;
        new_node->data=item;
        if(start==NULL)
        {
            new_node->next=start;
            start=new_node;
        }
        else                               //becaus when empty start=NUll
        {
            start->prev=new_node;
            new_node->next=start;
            start=new_node;
        }
    }

    void insert_afer(T item, T after_this)
    {
        Node* new_node=new Node;
        new_node->data=item;
        Node* ptr=start;
        //cout<<"inside the funsction!!"<<endl;
        try
        {
            while(ptr->data!=after_this)
            {
                //cout<<"Inside the while loop"<<endl;
                ptr=ptr->next;
                if (ptr==NULL)
                    throw 1;
            }
            if(ptr->next==NULL) //because end ma add garda probem aauncha tala kai method use garda
                insert_end(item);
            else
            {
                new_node->next=ptr->next;
                new_node->prev=ptr;
                ptr->next->prev=new_node;
                ptr->next=new_node;
            }
        }
        catch(int)
        {
            std::cerr <<"ITEM NOT FOUND!!!" << '\n';
        }
    }

    void insert_bef(T item, T bef_this)
    {
        Node* new_node= new Node;
        new_node->data=item;
        Node* ptr=start;   
        try
        {
             while(ptr->data!=bef_this)
            {
                if(ptr==NULL)
                    throw 1;
                ptr=ptr->next;
            }
            if(ptr==start) //if we try to insert before with only one element in the list or in be beginning of the list
                insert_beg(item);
            else
            {
                new_node->next=ptr;
                new_node->prev=ptr->prev;
                ptr->prev->next=new_node;
                ptr->prev=new_node;
            }
        }
        catch(int)
        {
            std::cerr << "ITEm not in the list!!" << '\n';
        }
    }

    void insert_end(T item)
    {
        if(start==NULL)
            insert_beg(item);
        else
        {
            Node* new_node=new Node;
            new_node->data=item;
            Node* ptr=start;
            while(ptr->next!=NULL)
                ptr=ptr->next;
            new_node->prev=ptr;
            ptr->next=new_node;
        }
    }

    T del_beg()
    {
        if(start==NULL)
        {
            cout<<"No item to delete!!"<<endl;
            exit(1); 
        }
        else
        {
            T temp;
            Node* ptr=start;
            temp=ptr->data;
            start=start->next;
            start->prev=NULL;
            delete ptr;
            return temp;
        }
    }
    
    T del_end()
    {
        //have to make condition to check underflow
        if(start==NULL)
        {
            cout<<"NO item in the stack";
            exit(1);
        }
        else
        {
            Node* ptr=start;
            T temp;
            while(ptr->next!=NULL)
                ptr=ptr->next;
            temp=ptr->data;
            ptr->prev->next=NULL;
            delete ptr;
            return temp;
        }
    }

    T del_aft(T after_this)
    {
        if(start==NULL)
        {cout<<"NO item in the stack";    exit(1);}
        Node *ptr=start;
        Node* ptr2;
        try
        {
            while(ptr->data!=after_this)
            {
                if(ptr==NULL)
                    throw 1;
                ptr=ptr->next;
            }
            T temp;
            ptr2=ptr->next;
            if(ptr2->next==NULL)
                temp=del_end();
            else
            {
                ptr2->next->prev=ptr;
                ptr->next=ptr2->next;   //also check if this item is the item at last then call the function del_end
                temp=ptr2->data;
            }
            delete ptr2;
            return temp;
        }
        catch(int)
        {
            cout<<"No such value exists in the stack"<<endl;
        }
    }

    T del_bef(T item)
    {
        Node* ptr=start;
        while(ptr->data!=item)
        {
            if(ptr==NULL)
            {
                cout<<"No such item exists in the list!!!"<<endl;
                exit(1);
            }
            ptr=ptr->next;
        }
        Node* ptr2=ptr->prev;
        ptr->prev=ptr2->prev;
        ptr2->prev->next=ptr;
        T temp=ptr2->data;
        delete ptr2;
        return temp;
    }

    void display()
    {
        Node* ptr=start;
        Node* ptr2;
        cout<<"Displaying the items: "<<endl;
        while(ptr!=NULL)
        {
            cout<<"Value: "<<ptr->data<<endl;
            ptr2=ptr;
            ptr=ptr->next;
        }
        // cout<<"Displaying from the end: "<<endl;    //using prev to print the data
        // do
        // {
        //     cout<<"Value: "<<ptr2->data<<endl;
        //     ptr2=ptr2->prev;
        // } while (ptr2!=start);
        // cout<<"Value: "<<ptr2->data<<endl;
    }
    
};
int main()
{
    doubly_linked_list<int> d1;
    //cout<<"HERE";
    d1.insert_beg(1);
    //cout<<"HERE!!@@";
    d1.insert_beg(2);
    d1.insert_beg(3);
    //cout<<"HEre"<<endl;
    d1.insert_afer(100,2);
    d1.insert_afer(200,1);
    d1.insert_end(1000);
    //cout<<"HERERERERER"<<endl;
    d1.insert_bef(120000,3);
    //cout<<"HERE!!"<<endl;
    d1.display();
    cout<<endl<<endl<<"Deleting item from beginning: "<<d1.del_beg()<<endl;
    cout<<"Deleting item from the end: "<<d1.del_end()<<endl;
    cout<<"Deleting item after an item after 3 is: "<<d1.del_aft(3)<<endl;
    cout<<"Deleting item before 200: "<<d1.del_bef(200)<<endl;
    d1.display();


}