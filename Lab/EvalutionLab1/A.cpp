/*In this problem, you need to create a singly linked list and insert integer values at the
first and last of the linked list.
Input:
First line: n, a number. (1<=n<=10^6)
Next n lines: p v, two integers (0<=p<=1, -1000<=v <=1000). If p = 0, insert v at the first
of the linked list. Otherwise, insert v at the last.
Output:
n lines, each containing the values stored in the linked list from head to tail.
Sample Case:
Input Output
5
0 1
0 2
0 3
1 4
1 5
Output:
3
2
1
4
5
*/
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* next;
    
};
node* head=NULL;
node* tail=NULL;
void first(int data)
{
    node* p=new node();
    p->data=data;
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

void last(int data)
{
    node* p=new node();
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
    for(int i=0;i<t;i++)
    {
        int p,v;
        cin>>p>>v;
        if(p==0)
        {
            first(v);
        }
        else
        {
            last(v);
        }

    }
    print();
}



