//you are given a sorted array and a number k as input.Find the largest number that is smaller than k
#include<bits/stdc++.h>
using namespace std;
int find(int n,int arr[],int s,int e,int k)
{
    if(s>=e) return -1;
    int mid=(s+e)/2;
    if(arr[mid]==k) return mid;
    else if(arr[mid]>k) return find(n,arr,s,mid-1,k);
    else if(arr[mid]<k)return find(n,arr,mid+1,e,k);
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
    int k;
    cin>>k;
    int x=find(n,arr,0,n-1,k);
    cout<<arr[x-1]<<endl;

}