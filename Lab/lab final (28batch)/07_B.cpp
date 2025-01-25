//07
#include<bits/stdc++.h>
using namespace std;

void mergesort(pair<int,int>arr[],int s,int e)
{
    int mid=(s+e)/2;
    int len1=(mid-s+1);
    int len2=(e-mid);
    vector<pair<int,int>>first(len1),sec(len2);
    int k=s;
    for(int i=0;i<len1;i++) first[i]=arr[k++];
    k=mid+1;
    for(int i=0;i<len2;i++) sec[i]=arr[k++];
    int in1=0;
    int in2=0;
    int j=s;
    while(in1<len1&&in2<len2)
    {
        if(first[in1].second<sec[in2].second)
        {
            arr[j++]=first[in1++];
        }
        else if(first[in1].second==sec[in2].second)
        {
             if(first[in1].first<sec[in2].first)
             {
                 arr[j++]=first[in1++];
             }
             else
             arr[j++]=sec[in2++];
        }
        else 
        {
            arr[j++]=sec[in2++];
        }
    }
    
    while(in1<len1)
    {
         arr[j++]=first[in1++];
    }
    while(in2<len2)
    {
           arr[j++]=sec[in2++];
    }
    
    
}
void merge(pair<int,int>arr[],int s,int e)
{  
    if(s>=e) return;
    int mid=(s+e)/2;
    merge(arr,s,mid);
    merge(arr,mid+1,e);
    mergesort(arr,s,e);
}

int main()
{
    int n;
    cin>>n;
    pair<int,int>arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].first>>arr[i].second;
    }
    merge(arr,0,n-1);
    for(auto x:arr)
    {
        cout<<x.first<<endl;
    }
}
