#include<bits/stdc++.h>
using namespace std;
int rec(int n,int arr[],int s,int e,int key )
{
    int mid=(s+e)/2;
    if(s>=e) return -1;
    if(arr[mid]==key) return mid;
    else if(arr[mid]>key) return rec(n,arr,s,mid-1,key);
    else if(arr[mid]<key) return rec(n,arr,mid+1,e,key);
    
}
int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<rec(n,arr,0,n-1,k)<<endl;

}