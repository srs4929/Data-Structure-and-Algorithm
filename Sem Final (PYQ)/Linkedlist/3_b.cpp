//check if a linked list is circular or not
#include<bits/stdc++.h>
using namespace std;

struct node
{ 
     int data;
     node* next;
     node(int data)
     {
        this->data=data;
        next=NULL;
     }
};

bool check(node* head)
{
    if(head==NULL) return  true; //empty so circular
    node* curr=head->next; //check from next
    while(curr!=NULL && curr!=head)
    {
        curr=curr->next;
        
    }
    return (curr==head); // if current is head found circular or false
}
int main()
{
      node* first=new node(7);
      node* second=new node(8);
      node* third=new node(9);

      first->next=second;
      second->next=third;
      third->next=first;
      cout<<check(first)<<endl;

}