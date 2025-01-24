#include<bits/stdc++.h>
using namespace std;
int heap[1000];
int last=-1;

int parent(int i)
{
    return (i-1)/2;
}
void heapup(int i)
{
   while(i>0)
   {
       int p=parent(i);
       if(heap[p]>heap[i]) break;
       swap(heap[p],heap[i]);
       i=p;
   }
}
void insert(int val)
{
    heap[last+1]=val;
    last++;
    heapup(last);
    
}

void heapdown(int index)
{
    int i=index;
    while(i<=last)
    {
        int left=2*i+1;
        int right=2*i+2;
        if(left<=last&&heap[i]<heap[left])
        {
            swap(heap[i],heap[left]);
            i=left;
        }
        else if(right<=last && heap[i]<heap[right])
        {
            swap(heap[i],heap[right]);
            i=right;
        }
        else return;
    }
}
void del(int d)
{
    int ind=-1 ;//the index that need to be deleted
    for(int i=0;i<=last;i++)
    {
        if(heap[i]==d)
        {
            ind=i;
            break;
        }
    }
    heap[ind]=heap[last];
    last--;
    //heapup(ind);//if the value is greater
    heapdown(ind); //if the value is smaller. 
}

void print()
{
    for(int i=0;i<=last;i++)
    {
        cout<<heap[i]<<" " ;
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
        insert(x);
    }
    print();
     cout<<endl;
    cout<<"The value that want to be deleted"<<endl;
    int d;
    cin>>d;
    del(d);
   
    print();
}