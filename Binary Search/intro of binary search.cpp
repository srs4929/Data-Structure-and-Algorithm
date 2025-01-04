#include<bits/stdc++.h>
using namespace std;
 int binary(int n,int target,int arr[])
{
    int low=0;
    int high=n-1;
    while(low<=high)
    {
        int mid=(high+low)/2;
        if(arr[mid]==target)
        {
            return mid;
        }
        else if(arr[mid]>target)
        {
            high=mid-1;
        }
        else if(arr[mid]<target)
        {
            low=mid+1;
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
    int target;
    cin>>target;

    printf("%d\n", binary(n,target,arr));
    return 0;
}
