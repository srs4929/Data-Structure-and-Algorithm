#include<bits/stdc++.h>
using namespace std;
void bfs(vector<vector<int>>&arr,vector<bool>&visit,int root)
{
    queue<int>q;
    visit[root]=true;
    q.push(root);
    while(!q.empty())
    {
        int curr=q.front();
        cout<<curr<<" ";
        q.pop();
        for(int x: arr[curr])
        {
            if(!visit[x])
            {
                visit[x]=true;
                q.push(x);
            }
        }
    }
}
void disconnected(vector<vector<int>>&arr,int root)
{
    vector<bool>visit(arr.size(),false);
    if(!visit[root]) // root not visited
    {
        bfs(arr,visit,root);
    }
    //for the rest
    for(int i=0;i<arr.size();i++)
    {
        if(!visit[i])
        {
            bfs(arr,visit,i);
        }
    }
}
void adjacentlist(vector<vector<int>>&arr,int e1,int e2)
{
    arr[e1].push_back(e2);
    arr[e2].push_back(e1);
}
int main()
{
    int v,e,root;
    cin>>v>>e>>root;//vertex,edge,root
    //creating adjacent list
    vector<vector<int>>arr(v);
    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        adjacentlist(arr,a,b);
    }
   
   
    disconnected(arr,root);


}

/*Enter the number of nodes and edges:
6 5
Enter the edges (u v):
0 1
0 2
3 4
4 5
2 3
Enter the starting node (root):
3*/

/*BFS starting from node 3:
3 4  2 5 0 1
*/
