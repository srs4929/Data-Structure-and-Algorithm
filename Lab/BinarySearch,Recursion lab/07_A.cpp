//07
/*You will be given a list of numbers and a list of queries. You have to find out if the
queries exist in the list.
Input:
First line: n, a number. (1<=n<=10^5)
Next n lines: an integer v (-2147483648<=v <=2147483647), the numbers in the list
Next line: m, a number (1<=m<=10^5), the number of keys.
Next m lines: an integer q (-2147483648<= q <=2147483647), the queries to be
searched for.
Output:
m lines, each containing 1 if the query is found, otherwise 0.
*/

#include<bits/stdc++.h>
using namespace std;
int search(int arr[],int target,int n,int s,int e)
{   
    while(s<=e){
    int mid=(s+e)/2;
    if(arr[mid]==target) return 1;
    else if(arr[mid]>target) e=mid-1;
    else if(arr[mid<target]) s=mid+1;
    }
    return 0;

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
    int m;
    cin>>m;
    sort(arr,arr+n);
    for(int i=0;i<m;i++)
    {
        int q;
        cin>>q;
        cout<<search(arr,q,n,0,n-1)<<endl;;

    }
}