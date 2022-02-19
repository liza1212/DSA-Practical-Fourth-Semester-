#include <iostream>
#define size 5

using namespace std;

int start=-1;
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
    else
    {
        node[avail_index].info=val;
        node[avail_index].next=node[start].next;
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

// template<class T>
// void freenode(node_type<T> *node, int node_index) //why and how does this free node work??
// {
//     node[node_index].next=avail;
//     avail=node_index;
//     if(node_index==start)
//     {
//         start=-1;
//     }
// }
template<class T>
void delete_beg(node_type<T> *node)
{
    T rem_item;
    if(start==-1)
    {
        cout<<"UNDERFLOW!!!"<<endl;
    }
    int ind;
    ind=start;
    start=node[start].next;
    rem_item=node[ind].info;
    cout<<"Removed Item: (DEL_BEG)"<<rem_item<<endl;
}

template<class T>
void delete_end(node_type<T> *node)
{
    T rem_items;
    if(start==-1)
    {
        cout<<"UNDERFLOW!!!!"<<endl;
        exit(1);
    }
    int pre, i;
    i=start;
    while(node[i].next!=-1)
    {
        pre=i;
        i=node[i].next;
    }
    rem_items=node[i].info;
    node[pre].next=-1;
    cout<<"Removed item is: (DEL_END) "<<rem_items<<endl;
}

template<class T>
void delete_after(node_type<T> *node, T aft_this)
{
    T rem_item;
    int i=start;
    while(node[i].info!=aft_this)
    {
        i=node[i].next;
    }
    rem_item=node[node[i].next].info;
    node[i].next=node[node[i].next].next;
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
    cout<<endl;
}

int main()
{
    node_type<int> node[size];
    init(node);
    insert_beg(node, 12);
    //insert_beg(node,1);
    //insert_end(node,34);
    insert_end(node,23);
    insert_after(node, 12, 15);
    insert_after(node, 15,2);
    Display(node);
    delete_beg(node);
    //delete_beg(node);
    delete_end(node);
    delete_end(node);
    // insert_beg(node,1234); //will create overflow!!!
    // insert_end(node, 9876);
    cout<<"Display after deleting some elements:"<<endl;
    Display(node);
}