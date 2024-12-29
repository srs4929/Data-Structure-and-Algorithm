/*In this problem, you need to create a singly linked list. You will be given n integers, vi,
which you will insert at the last of the linked list according to the given order. Then you
will sort the integers in ascending order. Do not use data structures like array, vector,
etc. Output the numbers in the linked list from head to tail.*/
#include <iostream>
using namespace std;

struct ll
{

    struct node
    {
        node *next;
        int val;
    };
    node *head=NULL;
    node *tail=NULL;

    void insert_last(int x)
    {
        //insert x at last
        //Your code starts here #001
         
         node* newNode = new node();
         newNode->val = x;
         newNode->next = NULL;

         if(head == NULL){
            head = newNode;
            tail = newNode;
         }
         else{
            tail->next = newNode;
            tail = newNode;
         }
        
        //Your code ends here #001
    }

    void sort(){
        //Sorts the linked list

        //Your code starts here #002
         
         node* start=head;
         while(start!=NULL)
         {
            node* next=start->next;
            while(next!=NULL)
            {
                if(start->val>next->val)
                {
                    int t=start->val;
                    start->val=next->val;
                    next->val=t;
                }
                next=next->next;
            }
            start=start->next;
         }
        
        //Your code ends here #002
    }

    void print()
    {
        //prints elements from head to tail
        //Your code starts here #003
         
         node* temp = head;

         while(temp!=NULL){
            cout<<temp->val<<endl;
            temp = temp->next;
         }
        
        //Your code ends here #003
    }
};


int main()
{

    //Your code starts here #004
    
     ll list;

     int n;
     cin>>n;
     for(int i =0;i<n;i++){
      int v;
      cin>>v;
      list.insert_last(v);
     }

     list.sort();

     list.print();
        
    //Your code ends here #004
    return 0;


}