#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; //number of vertices
    cin>>n;
    int v; //number of input;
    cin>>v;
    vector<vector<int>>arr(n,vector<int>(n,0)); //array size
    for(int i=0;i<v;i++)
    {
           int e1,e2; //edge number
           cin>>e1>>e2;
           e1--,e2--;
           arr[e1][e2]=1;
           arr[e2][e1]=1;

    }
    //print the graph
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

}
//Time Complexity: O(V^2), where V is the number of vertices in the graph.
//Auxiliary Space: O(V^2)
//edge insertion : o(1)
//edge query: o(1)
