//07
//07
/*You will be given a list of integers in sorted order and a list of queries. You have to find
the number of integers in the list less than or equal to the query. You may assume that
the query exists in the list of integers.
Input:
First line: n, a number. (1<=n<=10^6)
Next n lines: an integer v (-2147483648<=v <=2147483647), the numbers in the list
Next line: m, a number (1<=m<=10^5), the number of keys.
Next m lines: an integer q (-2147483648<= q <=2147483647), the queries.
Output:
m lines, each containing the number of integers in the list less than or equal to the
query.
input 
7
1 1 1 2 3 4 5
2
1
3
output
3
5*/


#include<bits/stdc++.h>
using namespace std;
int last(int arr[],int target,int s,int e)
{
    int ans=-1;
    while(s<=e)
    {
        int mid=(e+s)/2;
        if(arr[mid]==target)
        {
             ans=mid;
             s=mid+1;
        }
        else if(arr[mid]>target)
        {
               e=mid-1;
        }
        else if(arr[mid]<target)
        {
            s=mid+1;
        }
    }
    return ans;
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
    
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int m;
        cin>>m;
        int result= last(arr,m,0,n-1);
        cout<<result+1<<endl;

    }
}