// You are given two linkedlist.Write down an efficient algo to combine both of them

#include<bits/stdc++.h>
using namespace std;
struct node
{
   int data;
   node* next;
};

node* head1=NULL;
node* tail1=NULL;
node* head2=NULL;
node* tail2=NULL;
void in(node* &head1,node* &tail1,int x)
{
    node* p=new node;
    p->data=x;
    p->next=NULL;
    if(head1==NULL)
    {
        head1=p;
        tail1=p;
    }
    else
    {
        tail1->next=p;
        tail1=p;
    }
}

node* merge(node* &head1,node* &head2)
{
    node* first=head1;
    node* second=head2;
    if(first==NULL) return second;
    if(second==NULL) return first;

    node* result=NULL;
   
    if(first->data<second->data) 
    {
        result=first;
        result->next=merge(first->next,second);
    }
    else
    {
       result=second;
       result->next=merge(first,second->next);
    }
    
    
    return result;
    
}

void display(node* &head)
{
    node* ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<endl;
        ptr=ptr->next;
    }
}




int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        in(head1,tail1,x);
    }
    int n2;
    cin>>n2;
    for(int i=0;i<n2;i++)
    {
        int x;
        cin>>x;
        in(head2,tail2,x);
    }
   
    node* mergehead=merge(head1,head2);
    display(mergehead);

   
    


}