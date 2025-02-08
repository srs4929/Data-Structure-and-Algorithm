
// You are given a sorted array of numbers and a number k as input. Write down an efficient algorithm
// for finding the largest number in the array that is smaller than k. Mention the runtime and
// space complexity of your algorithm.

//binary search
#include<bits/stdc++.h>
using namespace std;

int find(int arr[],int k,int s,int e)
{
    int ans=-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(arr[mid]<k)
        {
            ans=arr[mid];
            s=mid+1;
        }
        else e=mid-1;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int k;
    cin>>k;
    cout<<find(arr,k,0,n-1);
}


//Space complexity : o(1)

//Time complaexity :
/*
   
   T(n)=T(n/2)[every time half analysis]+c(time taken for check)

   T(n)=T(n/2)+c......(1)
   T(n/2)=T(n/4)+c......(2)
   substituting
   T(n)=[T(n/4)+c]+c
       =T(n/2^k)+kc 

       Where if T(n/2^k)=1 [if one item remain it is O(1) time]
                n=2^k
                logn=k
    T(n) =o(1) +logn*c
          =logn          
*/