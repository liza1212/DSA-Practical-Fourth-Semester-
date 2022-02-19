#include <iostream>

using std::cout;
using std::cin;
using std::endl;

template <class T>
class s_lisy
{
private:
    struct stck
    {
        T info;
        stck* next;
    }*start_top=NULL;
public:
    void push(T item)
    {
        stck* new_node;
        new_node=new stck;
        new_node->info=item;
        new_node->next=start_top;
        start_top=new_node;
    }
    T pop()
    {
        if(!start_top)
        {
            cout<<"UNDEERFLOWW!!!"<<endl;
            exit(1);
        }
        stck* temp;
        temp=start_top;
        T dat=temp->info;
        start_top=start_top->next;
        delete temp;
        return dat;
    }
    void display()
    {
        stck* temp=start_top;
        cout<<"The items of the list are: "<<endl;
        while(temp!=NULL)
        {
            cout<<temp->info<<endl;
            temp=temp->next;
        }
    }
};
int main()
{
    s_lisy<char> s1;
    s1.push('l');
    s1.push('i');
    s1.display();
    cout<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
}