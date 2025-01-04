//you need to find the index of a given key in an array
//input
//first line : n, a number
//next n lines :an integer v
//next line: m, a number the number of keys
//next m lines: an integer key , the key to be searched for

#include<bits/stdc++.h>
using namespace std;

int find(int n,int arr[],int x,int s,int e)
{
    
    while(s<=e)
    {   int mid=(s+e)/2;
        if(arr[mid]==x) return mid;
        else if(arr[mid]>x)
        {
            e=mid-1;
        }
        else if(arr[mid]<x)
        {
            s=mid+1;
        }
    }
    return -1;
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
    int key;
    cin>>key;
    vector<int>result;
    for(int i=0;i<key;i++)
    {
        int x;
        cin>>x;
        result.push_back(find(n,arr,x,0,n));

    }

    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<endl;
    }
}