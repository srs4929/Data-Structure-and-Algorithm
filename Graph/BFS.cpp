#include<bits/stdc++.h> //undirected and disconnected graph
using namespace std;

void bfs(vector<vector<int>>&arr,vector<bool>&visited,int n)
{
    queue<int>q; // create a queue list
    visited[n]=true;
    q.push(n);
    while(!q.empty())
    {   
        int curr=q.front();
        cout<<curr<<" "; //pop out the first element
        q.pop();
        //get all the adjacent of it
        for(int x:arr[curr])
        {
             if(!visited[x]) //if not visited
             {
                visited[x]=true;
                q.push(x);
             }
        }

    }
}
void disconnected(vector<vector<int>>&arr) //if the node is visited or not check
{
     vector<bool>visited(arr.size(),false);// the entire visited marked as false
     for(int i=0;i<arr.size();i++)
     {
        if(!visited[i]) //if not visited call bfs function
        {
           bfs(arr,visited,i);//pass the array ,visited and that number to the bfs list
        }
     }
}
void addedge(vector<vector<int>>&arr,int e1,int e2) // creating list
{

  arr[e1].push_back(e2);
  arr[e2].push_back(e1);

}
int main()
{
   //adjacent list
   int n,m;
   cin>>n>>m; //number of nodes and edges
   vector<vector<int>>arr(n);
   for(int i=0;i<m;i++)
   {
      int a,b;
      cin>>a>>b;
      addedge(arr,a,b);
   }

   disconnected(arr);
}

/*Enter the number of nodes and edges: 
5 4
Enter the edges (u v):
0 1
0 2
3 4
2 3
BFS traversal of the graph:
0 1 2 3 4*/
/*Adjacent list
0->1->2
1->0
2->0->3
2->4->3
3->4->2
4->2

*/





