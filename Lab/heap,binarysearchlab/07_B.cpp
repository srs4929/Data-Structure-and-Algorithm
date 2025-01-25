//07
#include<bits/stdc++.h>
using namespace std;
int heap[10000];
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
        if(heap[i]>heap[p]) break;
        swap(heap[p],heap[i]);
        i=p;
    }
}
void insert(int x)
{
    heap[last+1]=x;
    last++;
    heapup(last);
}

void heapdown (int i)
{
   while(i<=last)
   {
       int left=2*i+1;
       int right=2*i+2;
       int small=i;
       if(left<=last&&heap[left]<heap[small]) small=left;
       if(right<=last&& heap[right]<heap[small]) small=right;
       if(small!=i)
       {
        swap(heap[small],heap[i]);
        i=small;
       }
       else break;
   }
    
}
int extractmin()
{
    int mini=heap[0];
    heap[0]=heap[last];
    last--;
    heapdown(0);
    return mini;
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
    while(last>=0)
    {
        cout<<extractmin()<<endl;
    }
}