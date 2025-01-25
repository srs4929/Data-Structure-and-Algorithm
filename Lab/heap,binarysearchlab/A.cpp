//07
#include<bits/stdc++.h>
using namespace std;

int search(int arr[],int s,int e,int t)
{
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(arr[mid]==t) return 1;
        else if(arr[mid]>t) e=mid-1;
        else s=mid+1;
    }
    return 0;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int q;
        cin>>q;
        cout<<search(arr,0,n-1,q)<<endl;

    }
}