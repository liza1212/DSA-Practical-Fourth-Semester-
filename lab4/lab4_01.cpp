#include <iostream>
#define size 20
using namespace std;
struct node_type
{
    int info, next;
};

class List 
{
private: 
    int avail=-1;
    int start;
    node_type node[size];
    void init()
    {
        avail=0;
        for (int i=0;i<(size-1);i++)
        {
            node[i].next=i+1;
        }
        node[size-1].next=-1;
    }
public:
    
    List(int first)
    {
        init();
        start=get_node();
        node[start].info=first;
        node[start].next=-1;
    }
    int get_node()
    {
        int p;
        try
        {
            if(avail==-1)
            {    throw 1;
                exit(1);}
            p=avail;
            avail=node[avail].next;
            return p;
        }
        catch(...)
        {
            cout<<"OVERFLOW!!!"<<endl;
        }    
    }
    void insert_at_begining(int value)
    {
        try
        {
            if (avail==-1)
            {
                throw 1;
            }
            else
            {
                int new_node = get_node();
                node[new_node].info=value;
                node[new_node].next=start;
                start=new_node;
            }
        }
        catch(int)
        {
           cout<<"OVERFLOW!!!"<<endl;
        }
    }
    void insert_at_end(int value)
    {
        try
        {
            if(avail==-1)
            {
                throw 1;
            }
            else
            {
                int new_node;
                new_node=get_node();
                node[new_node].info=value;
                node[new_node].next=-1;
            }
        }
        catch(int)
        {
            cout<<"OVERFLOWW!!!"<<endl;
            exit(1);
        }
    }
    void insert_after_n(int to_ins, int aft_ins)
    {
        if(avail==-1)
        {
            cout<<"OVERFLOW!!!"<<endl;
            exit(1);
        }
        else
        {
            int new_node;
            new_node=get_node();
            node[new_node].info=to_ins;
            int i=start;
            int j_pre=i;
            while(node[j_pre].info!=aft_ins)
            {
                // node[i].info=
                j_pre=i;
                i=node[i].next;
            }
            node[j_pre].next=new_node;
            node[new_node].next=i;
        }
    }
    void delete_at_beginning()
    {
        if(start==-1)
        {
            cout<<"UNDERFLOW!!!!"<<endl;
            exit(1);
        }
        else
        {
            int temp=start;
            start=node[start].next;
            node[temp].next=avail;
            avail=temp;

        }
    }

};
