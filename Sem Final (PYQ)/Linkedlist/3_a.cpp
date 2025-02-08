
//Design a linked list with the following properties
/*
a)Insertion of an item in the first or last position take 0(1)
b)Deletion of an item from the middle position has the complexity o(1)
*/

//using double linkedlist

#include<bits/stdc++.h>
using namespace std;

struct node
{
   int data;
   node* prev;
   node* next;
   node(int data)
   {
    this->data=data;
    prev=NULL;
    next=NULL;
   }
};

node* head=NULL;
node* tail=NULL;
//map to store node pointers

unordered_map<int,node*>fre;
//insert at front o(1)

void insert(int x)
{
    node* p=new node(x);
    if(head==NULL)
    {
        head=p;
        tail=p;
    }
    else{
        p->next=head;
        head->prev=p;
        head=p;
    }
    fre[x]=p; // store in the map;
}

//insert back

void last(int x){
    
    node* p=new node(x);
    if(head==NULL)
    {
        head=p;
        tail=p;
    }
    else{
        tail->next=p;
        p->prev=tail;
        tail=p;
    }
    fre[x]=p; // store in the map;
}

//delete middle

void del(int x)
{
    if(fre.find(x)==fre.end()) return ;// if value not found

    node* temp=fre[x] ; //store the node in temp

    //if it is head
    if(temp==head)
    {
        head=head->next;
        if(head) head->prev=NULL;
        else tail=NULL; //if list is empty tail also null
    }

    else if(temp==tail)
    {
        tail=tail->prev;
        if(tail) tail->next=NULL;
        else head=NULL;
    }
    else{
    temp->prev->next=temp->next;
    if(temp->next) temp->next->prev=temp->prev;
    }
    fre.erase(x);  // earse from map
    delete temp;
}

void print()
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
      insert(60);
      insert(80);
      last(20);
      print();
      
}
//since unordered map we just fetch it not transverse thus the time complexity of
//deletion is o(1)