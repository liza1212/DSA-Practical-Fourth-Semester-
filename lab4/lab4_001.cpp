#include <iostream>
#define size 5

using namespace std;

int start=0;
int avail=-1;

template <class T>
struct node_type
{
    T info;
    int next;
};

template<class T>
void init(node_type<T> *node)
{
    avail=0;    
    start=0;
    for (int i=0;i<size;i++)
    {
        node[i].next=i+1;
    }
    node[size-1].next=-1;
}

template<class T>
int get_avail_node(node_type<T> *node)
{
    int p=avail;
    avail=node[avail].next;
    return p;
}

template<class T>
void insert_beg(node_type<T> *node, T val)
{
    int avail_index=get_avail_node(node);
    if(avail_index==-1)
    {
        cout<<"OVERFLOW!!!"<<endl;
        exit(1);
    }
    else if(avail_index==0)
    {
        node[avail_index].info=val;
        node[avail_index].next=-1;
        //start=avail_index;
    }
    else
    {
        node[avail_index].info=val;
        node[avail_index].next=start;
        start=avail_index;

    }
}

template<class T>
void insert_end(node_type<T> *node, T val)
{
    int avail_index=get_avail_node(node);
    if(avail_index==-1)
    {
        cout<<"OVERFLOW!!!"<<endl;
        exit(1);
    }
    else
    {
        node[avail_index].info=val;
        node[avail_index].next=-1;
    }
}

template<class T>
int ret_node_for_after(node_type<T> *node, T val)
{
    int i=0;
    while(node[i].info!=val)
    {
        i=node[i].next;
        if(i==-1)
            break;
    }
    return i;
}

template<class T>
void insert_after(node_type<T> *node, T aft_this, T val)
{
    int nod_index;
    int index_for_newnode=get_avail_node(node);
    nod_index=ret_node_for_after(node, aft_this);
    if(nod_index==-1)
    {
        cout<<"There is no such valur in the list."<<endl;
    }
    else
    {
        node[index_for_newnode].info=val;
        node[index_for_newnode].next=node[nod_index].next;
        node[nod_index].next=index_for_newnode;
    }
}

template<class T>
void Display(node_type<T> *node)
{
    int pt;
    pt=start;
    cout<<"List items:"<<endl;
    while(pt!=-1)
    {
        cout<<node[pt].info<<" ";
        pt=node[pt].next;
    }
    // for(int i=0;i<size;i++)
    // {
    //     cout<<node[pt].info<<" ";
    // }
}

int main()
{
    node_type<int> node[size];
    init(node);
    insert_beg(node, 12);
    insert_beg(node,1);
    //insert_end(node,34);
    // insert_end(node,23);
    // insert_after(node, 12, 15);
    // insert_after(node, 15,2);
    Display(node);
}