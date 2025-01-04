//07
/*You will be given a list of numbers and a list of queries. You have to find the frequency
of the queries in the list.
Input:
First line: n, a number. (1<=n<=10^5)
Next n lines: an integer v (-2147483648<=v <=2147483647), the numbers in the list
Next line: m, a number (1<=m<=10^5), the number of keys.
Next m lines: an integer q (-2147483648<= q <=2147483647), the queries.
Output:
m lines, each containing the frequencies of the queries
Input: 3 
1 1 2
3
2 1 3
output:
1 2 0*/


#include<bits/stdc++.h>
using namespace std;
typedef long int ll;
ll first(ll arr[],ll n,ll low, ll high, ll target)
{
     
      ll ans=-1;
      while(low<=high)
      {
        ll mid=(low+high)/2;
        if(arr[mid]==target)
        {
            ans=mid;
            high=mid-1;
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
      return ans;
}
ll last(ll arr[],ll n,ll low,ll high, ll target)
{
      
      ll ans=-1;
      while(low<=high)
      {
        ll mid=(low+high)/2;
        if(arr[mid]==target)
        {
            ans=mid;
            low=mid+1;
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
      return ans;
}

int main()
{
      ll n;
      cin>>n;
      ll arr[n];
      for(int i=0;i<n;i++)
      {
        cin>>arr[i];
      }
      ll m;
      cin>>m;
      sort(arr,arr+n);
      for(int i=0;i<n;i++)
      {   
          int q;
          cin>>q;
        
          ll firstocc=first(arr,n,0,n-1,q);
          ll lastocc=last(arr,n,0,n-1,q);
          if(firstocc!=-1&&lastocc!=-1)
          cout<<(lastocc-firstocc+1)<<endl;
          else if(firstocc==-1&&lastocc!=-1)
          {
            cout<<1<<endl;
          }
          else if(firstocc!=-1&&lastocc==-1)
          {
            cout<<1<<endl;
          }
          else{
            cout<<0<<endl;
          }

      }
      
}