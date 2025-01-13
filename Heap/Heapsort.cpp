#include<bits/stdc++.h>
using namespace std;

void heap(int arr[],int n,int i)
{
    int largest=i; //we assume the root
    //left child
    int l=2*i+1;
    //right
    int r=2*i+2;

    if(l<n && arr[l]>arr[largest])
    {
        largest=l;
    }
    if(r<n && arr[r]>arr[largest])
    {
        largest=r;
    }

    if(largest!=i)//root is not largest than swap
    {
        swap(arr[largest],arr[i]);
        heap(arr,n,i); //recursion call
    } 

}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    //(n/2  to n is leaf nodes)so we have to make heap the rest
    for(int i=(n/2-1);i>=0;i--)
    {
        heap(arr,n,i);
    }
    //now sorted print
    for(int i=(n-1);i>=0;i--)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
