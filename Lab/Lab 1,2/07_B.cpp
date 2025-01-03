//07
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    string name;
    node* next;

};
node* head=NULL;
node* tail=NULL;

void last(string x,int data)
{
    node* p=new node;
    p->data=data;
    p->name=x;
    p->next=NULL;
    if(head==NULL)
    {
        head=p;
        tail=p;
    }
    else
    {
       p->next=head;
       head=p;
    }
    
}
void print()
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->name<<" "<<temp->data<<endl;
        temp=temp->next;
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {   
        string name;
        int data;
        cin>>name>>data;
        last(name,data);
    }
    print();
}