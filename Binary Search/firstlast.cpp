#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int first(int n,int arr[],int s,int e,int key)
{   
    int result=-1;
    while(s<=e)
    {   
        int mid=(s+e)/2;
        if(arr[mid]>key) e=mid-1;
        else if(arr[mid]<key) s=mid+1;
        else
        {
           result=mid;
           e=mid-1; 
        }
    }
    return result;
}


int last(int n,int arr[],int s,int e,int key)
{   
    int result=-1;
    while(s<=e)
    {   
        int mid=(s+e)/2;
        if(arr[mid]>key) e=mid-1;
        else if(arr[mid]<key) s=mid+1;
        else
        {
           result=mid;
           s=mid+1; 
        }
    }
    return result;
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int key;
    cin>>key;
    int x=first(n,arr,0,n-1,key);
    int y=last(n,arr,0,n-1,key);
    int z=y-x+1;
    if((x==-1&&y==-1)) cout<<x<<" "<<y<<" "<<0<<endl;
    else if((x==-1&&y!=1)||(y!=-1&&x==1))cout<<x<<" "<<y<<" "<<1<<endl;
    else cout<<x<<" "<<y<<" "<<z<<endl;
    return 0;
}
