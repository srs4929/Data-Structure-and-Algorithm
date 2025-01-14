#include<bits/stdc++.h>
using namespace std;
int heap[1000];
int last=-1;
int parent(int i)
{
    return (i-1)/2;
}
void heapify(int i)
{
    while(i>0)
    {
        int p=parent(i);
        if(heap[i]>=heap[p]) break;
        swap(heap[i],heap[p]);
        i=p;
    }
}
void heapup(int i)
{
    while(true)
    {   
        int small=i;
        int l=2*i+1;
        int r=2*i+2;
        if(l<=last && heap[small]>heap[l]) small=l;
         if(r<=last && heap[small]>heap[r]) small=r;
        if(small!=i)
        {
            swap(heap[small],heap[i]);
            i=small;
        }
        else
        {
            break;
        }
    }
}
int extract()
{
    int ret=heap[0];
    heap[0]=heap[last];
    last--;
    heapup(0);
    return ret;
    
}
void insert(int x)
{
    heap[last+1]=x;
    last++;
    heapify(last);
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
     for(int i=0;i<n;i++)
     {
         cout<<extract()<<endl;
     }
}