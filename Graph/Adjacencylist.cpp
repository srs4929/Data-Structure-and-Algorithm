#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; //number of vertices
    cin>>n;
    int v; //number of input;
    cin>>v;
    vector<vector<int>>arr(n);
    for(int i=0;i<v;i++)
    {
           int e1,e2; //edge number
           cin>>e1>>e2;
           e1--,e2--;
           arr[e1].push_back(e2);
           arr[e2].push_back(e1);

    }
    // print the list
    for(int i=0;i<n;i++)
    {
        cout<<i+1<<"->";
        for(auto j: arr[i])  // iterate over all neighbors of vertex i in the adjacency list

        {
            cout<<j+1<<" ";
        }
        cout<<endl;
    }

}
//Time Complexity: o(v+e) //vertex=v, e=edges
//Auxiliary Space: o(v+e)