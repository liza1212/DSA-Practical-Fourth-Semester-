// #include <iostream>
// #include <cassert>
// using std::cin;
// using std::cout;
// using std::endl;

// struct node
// {
//     float exp;
//     float coeff;
//     node *next;
// } *start = NULL;

// class l_list
// {
// private:
// public:
//     l_list(float num)
//     {
//         insert_beg(num);
//     }
//     node *create(float num)
//     {
//         node *ptr;
//         ptr = new node;
//         if (ptr == NULL)
//         {
//             cout << "OVERFLOW!!!" << endl;
//             exit(1);
//         }
//         else
//         {
//             ptr->data = num;
//             ptr->next = NULL;
//             return ptr;
//         }
//     }

//     void insert_beg(float num)
//     {
//         node *ptr;
//         ptr = create(num);
//         if (ptr == NULL)
//         {
//             cout << "OVERFLOW!!!" << endl;
//             exit(1);
//         }
//         else
//         {
//             ptr->data = num;
//             ptr->next = start;
//             start = ptr;
//         }
//     }

//     void insert_end(float num)
//     {
//         node *ptr;
//         node *new_node;
//         new_node=create(num);
//         if (new_node == NULL)
//         {
//             cout << "OVEREFLOW!!!" << endl;
//             exit(1);
//         }
//         else
//         {
//             //new_node->data = num;
//             new_node->next = NULL;
//             ptr = start;
//             while (ptr->next != NULL)
//             {
//                 ptr = ptr->next;
//             }
//             ptr->next = new_node;
//         }
//     }

//     void display()
//     {
//         node *ptr= start;
//         cout << "List items are:" << endl;
//         while (ptr != NULL)
//         {
//             cout << ptr->data << endl;
//             ptr = ptr->next;
//         }
//     }

//     void insert_after(float aft_this, float val)
//     {
//         node* new_node;
//         new_node=create(val);
//         node* temp;
//         temp=start;
//         while(temp->data!=aft_this)
//         {
//             temp=temp->next;
//             if (temp==NULL) 
//             {
//                 cout<<"NO element!!!"<<endl;
//                 break;
//             }
//         }
//         new_node->next=temp->next;
//         temp->next=new_node;
//     }
//     void insert_before(float bef_this,float val)
//     {
//         node* new_node;
//         new_node=create(val);
//         node* temp;
//         temp=start;
//         node* pre_temp;
//         pre_temp=temp;
//         while (temp->data!=bef_this)
//         {
//             pre_temp=temp;
//             if(temp->next==NULL) // new if
//             {
//                 cout<<"No such element found!!"<<endl;
//                 return;
//             }
//             temp=temp->next;
//         }
//         new_node->next=temp;
//         pre_temp->next=new_node;
//     }
//     void delete_beg()
//     {
//         node* temp = start;
//         assert(start!=NULL && "Deleting from empty");
//         start=start->next;
//         delete temp;
//     }
//     void delete_end()
//     {
//         node* temp = start, * pre_temp = start;
//         assert(start!=NULL && "Deleting from empty");
//         if(!start->next)
//         {
//             delete start;
//             start=NULL;
//         }
//         else
//         {
//             while(temp->next !=NULL)
//             {
//                 pre_temp=temp;
//                 temp=temp->next;
//             }
//             pre_temp->next=NULL;
//             delete temp;
//         }
        
//     }
//     void delete_after(float aft_this)
//     {
//         node* temp = start;
//         //assert(!start->next && "Single element list");
//         while(temp->data!=aft_this) temp=temp->next;
//         node* temp2_electricboogaloo = temp->next;
//         temp->next = temp->next->next;
//         delete temp2_electricboogaloo;
//     }
// };



// float main()
// {

// }