#include<bits/stdc++.h>
using namespace std;
int calh(int p[],int n,int total)
{
    int totalh=0;
    for(int i=0;i<n;i++)
    {
        totalh+=ceil((double)p[i]/(double)total);
    }
    return totalh;
}
int binary(int a[],int n,int k)
{
    int low=1,high=a[n-1];
    int ans=INT_MAX;
    while(low<=high)
    {
        int mid=(low+high)/2;
        int totalhour=calh(a,n,mid);
        if(totalhour<=k)
        {
            ans=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return ans;
}
int main()
{
    int n,k;
    cin>>n>>k;
    int v[n];
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    sort(v,v+n);
    cout<<binary(v,n,k)<<endl;
}
