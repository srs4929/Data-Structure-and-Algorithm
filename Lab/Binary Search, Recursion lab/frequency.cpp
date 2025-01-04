//07
//07
//07
//07
//07
//07
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