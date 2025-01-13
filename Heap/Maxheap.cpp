#include<bits/stdc++.h>
using namespace std;
int heap[10000];
int last=-1;

int getmax() //finding out the maximum
{
     if(last==-1) return -1; 
     else return heap[0];

}


int parent(int i)
{
    return (i-1)/2;
}
void heapify(int i)
{
    while(i>0)
    {
        int p=parent(i) ; //find out the index of its root;
        if(heap[p]>heap[i]) break; //if the root is already larger than the value braek
        swap(heap[p],heap[i]); //otherwise swap;
        i=p;//move the index
    }
}
void insert(int val)
{
    heap[last+1] =val; //increase the heap size
    last++;
    heapify(last);

}

void del()
{
    if(last==-1) return;
    heap[0]=heap[last] ; //store the most rightmost element at root
    last--;// reduce the last , remove the last 

    //take root node to its correct position

    int i=0;
    while(i<last)
    {
        int leftindex=2*i+1;
        int rightindex=2*i+2;

        if(leftindex<=last&& heap[i]<heap[leftindex])
        {
               swap(heap[i],heap[leftindex]);
               i=leftindex;
        }
        else if(rightindex<=last&& heap[i]<heap[rightindex])
        {
               swap(heap[i],heap[rightindex]);
               i=rightindex;
        }
        else{
            return;
        }

    }
}
void print()
{
    for(int i=0;i<=last;i++)
    {
        cout<<heap[i]<<" ";
    }
    cout<<endl;
}


int main()
{
      int n;
      cin>>n;
      for(int i=0;i<n;i++)
      {
        int d;
        cin>>d;
        insert(d);
      }
      print();
      cout<<endl; 
      cout<<"max value "<<getmax()<<endl;
      del();
      cout<<"After deleting"<<endl;
      print();
}