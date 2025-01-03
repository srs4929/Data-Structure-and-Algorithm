//07
//07
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* next;

};
node* head=NULL;
node* tail=NULL;

void last(int data)
{
    node* p=new node;
    p->data=data;
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
void print()
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int data;
        cin>>data;
        last(data);
    }
    print();
}