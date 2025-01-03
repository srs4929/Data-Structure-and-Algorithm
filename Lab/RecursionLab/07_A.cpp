//07
//07
#include<bits/stdc++.h>
using namespace std;

void com(vector<int>&arr,int index,int k,vector<int>result)
{
      if(result.size()==k)
      {
           for(int i=0;i<result.size();i++)
           {
              cout<<result[i]<<" ";
           }
           cout<<endl;
           return;
      }
      if(index>=arr.size()) return;

      result.push_back(arr[index]);
      com(arr,index+1,k,result);
      result.pop_back();
      com(arr,index+1,k,result);
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        arr[i]=i;
    }
    sort(arr.begin(),arr.end(),greater<int>());
    vector<int>result;
    com(arr,0,k,result);
    

}