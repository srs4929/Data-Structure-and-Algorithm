/*Consider an undirected graph where each edge weighs 6 units. Each of the nodes is labeled consecutively from 1 to n.

You will be given a number of queries. For each query, you will be given a list of edges describing an undirected graph. After you create a representation of the graph, you must determine and report the shortest distance to each of the other nodes from a given starting position using the breadth-first search algorithm (BFS). Return an array of distances from the start node in node number order. If a node is unreachable, return  for that node.*/

/*
Input Format

The first line contains an integer , the number of queries. Each of the following  sets of lines has the following format:

The first line contains two space-separated integers  and , the number of nodes and edges in the graph.
Each line  of the  subsequent lines contains two space-separated integers,  and , that describe an edge between nodes  and .
The last line contains a single integer, , the node number to start from.
Sample input:
2
4 2
1 2
1 3
1
3 1
2 3
2

Sample output :
6 6 -1
-1 6

Hackerrank problem

*/
#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>&arr,vector<bool>&visit,vector<int>&dist,int s)
{
    queue<int>q;
    q.push(s);
    visit[s]=true;
    dist[s]=0;
    
    // find the adjacent one
    while(!q.empty()){
        
        int curr=q.front();
        q.pop();
        for(int x: arr[curr])
        {
            if(!visit[x])
            {
                visit[x]=true;
                q.push(x);
                dist[x]=dist[curr]+6;
            }
        }
    }

}
    


int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        int n,m;
        cin>>n>>m; // n=node/vertex & m =edge
        vector<vector<int>>arr(n);
        //creating adj list
        for(int i=0;i<m;i++)
        {
            int e1,e2;
            cin>>e1>>e2;
            arr[e1-1].push_back(e2-1);
            arr[e2-1].push_back(e1-1);
        }
        int s;
        cin>>s;
        s=s-1; // root or starting point
        vector<bool>visit(arr.size(),false);
        vector<int>dist(arr.size(),-1); 
        bfs(arr,visit,dist,s);
        // printing the distances excluding starting node
        for(int i=0;i<n;i++)
        {
            if(i!=s)
            {
                cout<<dist[i]<<" ";
            }
        }
        cout<<endl;
        
    }
}

