#include<bits/stdc++.h>
using namespace std;

void dfs(int root, vector<bool>&visit,vector<vector<int>>&arr)
{
    visit[root]=true;
    cout<<root<<" ";
    
    for(int x : arr[root])// find the adjacency 
    {
        if(!visit[x])
        {
            dfs(x,visit,arr);
        }
    }
    
}

int main()
{
    int v, t,r;
    cin>>v>>t>>r;
    vector<vector<int>>arr(v) ;
    vector<bool>visit(arr.size(),false);
    for(int i=0;i<t;i++)
    {
         int e1,e2;
         cin>>e1>>e2;
         arr[e1].push_back(e2);
         arr[e2].push_back(e1);
    }
    dfs(r,visit,arr);
}
