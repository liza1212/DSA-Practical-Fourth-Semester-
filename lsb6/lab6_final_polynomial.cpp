#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class lists
{
private:
    struct p_add
    {
        float coeff;
        float exp;
        p_add* next;
    }*start=NULL;
public:
    void insert(float c, float e)
    {
        p_add* new_node;
        new_node=new p_add;
        new_node->coeff=c;
        new_node->exp=e;
        new_node->next=NULL;
        p_add* temp=start;
        if(start==NULL)
            start=new_node;
        else
        {
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=new_node;   
        }
    }
    void add(lists l1, lists l2)
    {
        p_add* temp1,* temp2;
        temp1=l1.start; 
        temp2=l2.start;
        lists l3;
       while(temp1!=NULL || temp2!=NULL)
        {
            if(temp1==NULL && temp2!=NULL)
            {
                do
                {
                    l3.insert(temp2->coeff,temp2->exp);
                    temp2=temp2->next;
                }while(temp2!=NULL);
            }
            else if(temp2==NULL && temp1!=NULL)
            {
                do
                {
                    l3.insert(temp1->coeff,temp1->exp);
                    temp1=temp1->next;
                }while(temp1!=NULL);
            }
            else if(temp1->exp==temp2->exp)
            {
                l3.insert(temp1->coeff+temp2->coeff, temp1->exp);
                //cout<<temp1->coeff+temp2->coeff<<endl;
                cout<<"equal exp"<<endl;
                temp1=temp1->next;
                temp2=temp2->next;
            }
            else if((temp1->exp) < (temp2->exp))
            {
                cout<<"REached here!!"<<endl;
                l3.insert(temp2->coeff, temp2->exp);
                cout<<"First exp is smaller than second."<<endl;
                //cout<<temp2->coeff<<endl;
                temp2=temp2->next;
            }
            else if ((temp1->exp) > (temp2->exp))
            {
                cout<<"second"<<endl;
                l3.insert(temp1->coeff, temp1->exp);
                //cout<<temp1->coeff<<endl;
                temp1=temp1->next;
            }
            
        }
        cout<<"the result is:"<<endl;
        l3.display();
    }
    void display()
    {
        p_add* temp;
        temp=start;
        while(temp!=NULL)
        {
            cout<<"Coefficient: "<<temp->coeff<<"\t Exponent: "<<temp->exp<<endl;
            temp=temp->next;
        }
    }
};
int main()
{
    lists l1;
    lists l2;
    float c, e;
    int n1, n2;
    // cout<<"Enter the number of terms in the first polynomial: "<<endl;
    // cin>>n1;
    // for (int i=0;i<n1;i++)
    // {
    //     cout<<"Term "<<i+1<<endl;
    //     cout<<"Co-efficient: ";
    //     cin>>c;
    //     cout<<"Exponent: ";
    //     cin>>e;
    //     l1.insert(c,e);
    // }
    // cout<<"Enter the number of terms in the second polynomial: "<<endl;
    // cin>>n2;
    // for (int i=0;i<n2;i++)
    // {
    //     cout<<"Term "<<i+1<<endl;
    //     cout<<"Co-efficient: ";
    //     cin>>c;
    //     cout<<"Exponent: ";
    //     cin>>e;
    //     l2.insert(c,e);
    // }
    l1.insert(1,1);
    l1.insert(2,2);
    l1.insert(3,3);
    l1.insert(45,89);

    l2.insert(1,1);
    l2.insert(2,2);
    l2.insert(4,4);
    l2.insert(45,5);
    cout<<"Items of list 1: "<<endl;
    l1.display();
    cout<<"Items of list 2: "<<endl;
    l2.display();
    l2.add(l1, l2);
}