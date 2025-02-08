//sort the linked list without using external array

#include<bits/stdc++.h>
using namespace std;
struct node
{
   int data;
   node* next;
};

node* head=NULL;
node* tail=NULL;

void in(int x)
{
    node* p=new node;
    p->data=x;
    p->next=NULL;
    if(head==NULL)
    {
        head=p;
        tail=p;
    }
    else
    {
        tail->next=p;
        tail=p;
    }
}

void sort()
{
    node* a=head;
    while(a!=NULL)
    {
        node* b=a->next;
        while(b!=NULL)
        {
            if(a->data>b->data)
            {
                int temp=a->data;
                a->data=b->data;
                b->data=temp;
            }
            b=b->next;
        }
        a=a->next;
    }
}

void display()
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
        in(x);
    }
  
    
    sort();
   
    display();


}