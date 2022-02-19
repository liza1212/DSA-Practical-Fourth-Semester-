#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node * next;
    
        node(int val){
            data = val;
            next = NULL;
        }
}*start;

class cLinkedList{
    public:
    cLinkedList(){
        start=NULL;
    }
    void addBeg(int data){
        node *newnode =new node(data);
        if(start==NULL){
            newnode->next=newnode;
            start = newnode;
            return ;
        }
        node *temp = start;
        while(temp->next!=start){
            temp=temp->next;
        }
        temp->next = newnode;
        newnode->next = start;
        start = newnode;


    }

    void addEnd(int data){
        node *newnode =new node(data);
        node *temp = start;
        if(start == NULL){
            addBeg(data);
        }
        while(temp->next!=start){
            temp=temp->next;
        }
        temp->next = newnode;
        newnode->next = start;
    }

    int delBeg(){
        node * temp = start;
        while(temp->next!=start){
            temp=temp->next;
        }
        node *deletednode = start;
        temp->next=start->next;
        start= start->next;
        int deletedata = deletednode->data;
        delete deletednode;
        return deletedata;
    }

    int delEnd(){
        node *temp = start,*pretemp;
        while(temp->next!=start){
            pretemp = temp;
            temp= temp->next;
        }
        node *deletednode= temp;
        pretemp->next = start;
        int deletedata = deletednode->data;
        delete deletednode;
        return deletedata;
    }
    



    void display(){
        node *temp = start;
        do
        {
            cout << temp->data;
            temp = temp->next;
        } while (temp!=start);
        cout << endl;
        
    }

};

int main(){
    cLinkedList l;
    l.addBeg(5);
    l.addBeg(4);
    l.addEnd(6);
    l.addEnd(7);
    l.addEnd(8);
    cout << l.delEnd();
    

}