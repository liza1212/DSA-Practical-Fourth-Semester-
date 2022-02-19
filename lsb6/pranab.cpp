// #include<iostream>
// using namespace std;

// struct node{
//     int exponent;
//     int coefficient;
//     node *next;

//     node(){}
//     node(int e,int c){
//         exponent= e;
//         coefficient = c;
//         next = NULL;
//     }
// };

// class LinkedList{
//     private:
//         node *start;

//     public:
    
//         LinkedList(){
//            start = NULL;
//         }
//         node* getstart(){
//             return start;
//         }
//         int getexp(){
//             return start->exponent;
//         }
//         int getcoeff(){
//             return start->coefficient;
//         }

//         void AddEnd(int c,int e)
//     {

//         node *newnode = new node(e,c);
//         node *ptr = start;
//         if(start == NULL){
//             newnode->next = NULL;
//             start = newnode;
//             return;
//         }
//         while (ptr->next != NULL)
//         {
//             ptr = ptr->next;
//         }

//         ptr->next = newnode;
//     }

//     void moveStart(){
//         start=start->next;
//     }

//     void display(){
//          node *temp = start;
//         do
//         {
//             cout << temp -> coefficient << "x^" << temp->exponent; 
//             temp = temp->next;
//             cout << endl;
//         } while (temp!=NULL);
//         cout << endl;
//     }

// };

// int main(){

//     cout << "Enter the number of terms for 1st eqn:";
//     int term1,c1,e1;
//     cin >> term1;
//     LinkedList l1;
//     cout << "Enter input for 1st eqn";
//     for(int i =0; i< term1;i++){
//         cout << "Term " << i+1<<endl<< "Enter,";
//         cout <<"Coefficient";
//         cin >> c1;
//         cout << "Exponent";
//         cin >> e1;
//         l1.AddEnd(c1,e1);
//     }
//     cout << "Enter the number of terms for 2nd eqn:";
//     int term2,c2,e2;
//     cin >> term2;
//     LinkedList l2;
//     cout << "Enter input for 1st eqn";
//     for(int i =0; i< term2;i++){
//         cout << "Term " << i+1 <<endl<< "Enter,";
//         cout <<"Coefficient";
//         cin >> c2;
//         cout << "Exponent";
//         cin >> e2;
//         l2.AddEnd(c2,e2);
//     }

//     LinkedList R;

//     while(true){
//         if(l1.getexp()>l2.getexp()){
//             R.AddEnd(l1.getcoeff(),l1.getexp());
//             l1.moveStart();
//         }   
//         else if(l1.getexp()<l2.getexp()){
//             R.AddEnd(l2.getcoeff(),l2.getexp());
//             l2.moveStart();
//         } 
//         else if(l1.getexp()==l2.getexp()){
//             R.AddEnd(l2.getcoeff()+l1.getcoeff(),l2.getexp());
//             l1.moveStart();
//             l2.moveStart();
//         } 
//         else if(l2.getstart() == NULL){
//             while(l1.getstart()==NULL){
//                 R.AddEnd(l1.getcoeff(),l1.getexp());
//             }
//         }
//         else if(l1.getstart() == NULL){
//             while(l2.getstart()==NULL){
//                 R.AddEnd(l2.getcoeff(),l2.getexp());
//             }
//         }

//         if(l1.getstart()==NULL && l2.getstart() == NULL ) break;

//     }
//     R.display();


// }
#include <iostream>

using namespace std;

class LinkedList
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
    void add(LinkedList l1, LinkedList l2)
    {
        p_add* temp1,* temp2;
        temp1=l1.start; 
        temp2=l2.start;
        LinkedList l3;
        while(!(temp1==NULL && temp2==NULL))
        {
            if(temp1==NULL && temp2!=NULL){
                do
                {
                    l3.insert(temp2->coeff,temp2->exp);
                    temp2=temp2->next;
                }while(temp2!=NULL);
            }
            else if(temp2==NULL && temp1!=NULL){
                do
                {
                    l3.insert(temp1->coeff,temp1->exp);
                    temp1=temp1->next;
                }while(temp1!=NULL);
            }
            else if(temp1->exp==temp2->exp){
                l3.insert(temp1->coeff+temp2->coeff, temp1->exp);
                cout<<"equal exp"<<endl;
                temp1=temp1->next;
                temp2=temp2->next;
            }
            else if((temp1->exp) < (temp2->exp)){
                cout<<"Reached here!!"<<endl;
                l3.insert(temp1->coeff, temp1->exp);
                cout<<"First exp is smaller than second."<<endl;
                temp1=temp1->next;
            }
            else if ((temp1->exp) > (temp2->exp)){
                cout<<"second"<<endl;
                l3.insert(temp2->coeff, temp2->exp);
                temp2=temp2->next;
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
            cout << temp ->coeff << "x^" << temp->exp; 
            temp = temp->next;
            cout << endl;
        }
    }
};
int main()
{
    cout << "Enter the number of terms for 1st eqn:";
    int term1,c1,e1;
    cin >> term1;
    LinkedList P;
    cout << "Enter input for 1st eqn";
    for(int i =0; i< term1;i++){
        cout << "Term " << i+1<< "Enter," <<endl;
        cout <<"Coefficient";
        cin >> c1;
        cout << "Exponent";
        cin >> e1;
        P.insert(c1,e1);
    }
    P.display();
    cout << "Enter the number of terms for 2nd eqn:";
    int term2,c2,e2;
    cin >> term2;
    LinkedList Q;
    cout << "Enter input for 1st eqn";
    for(int i =0; i< term2;i++){
        cout << "Term " << i+1 << "Enter," <<endl;
        cout <<"Coefficient";
        cin >> c2;
        cout << "Exponent";
        cin >> e2;
        Q.insert(c2,e2);
    }
    Q.display();
    Q.add(P,Q);

}