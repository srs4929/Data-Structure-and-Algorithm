/*In this problem, you need to create a singly linked list. You will be given n integers, vi,
which you will insert at the last of the linked list according to the given order. Then you
have to delete all the integers in the list within a given range [l, u] where l is the lower
limit and u is the upper limit.
You must use the template named “template_b.cpp” stored in the template folder.
Input:
First line: n, a number (1<=n<=10^6).
Next n lines: vi, a integer (-10000<=v <=10000).
Next line: Two integers, l u, (-10000<= l < u <=10000).
Output:
Each line will contain the values stored in the linked list from head to tail.
input:
5
1
2
3
4
5
2 3
output
1
4
5*/

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
        node* p=new node;
        p->val=x;
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

    void delete_range(int l, int u){

       node* temp=head;

       node* prev=NULL;
       while(temp!=NULL)
       {
           if(temp->val>=l&&temp->val<=u)
           {
               if(temp==head)
               {
                   head=temp->next;
                   delete temp;
                   temp=head;
               }
               else
               {
                   prev->next=temp->next;
                   delete temp;
                   temp=prev->next;

               }

           }
           else
           {
               prev=temp;
               temp=temp->next;
           }

       }
       tail=prev;


    }

    void print()
    {
        node* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->val<<endl;
            temp=temp->next;
        }

    }
};


int main()
{

    int n;
    cin>>n;
    ll p;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        p.insert_last(x);
    }
    int l,u;
    cin>>l>>u;
    p.delete_range(l,u);
    p.print();
    return 0;


}

