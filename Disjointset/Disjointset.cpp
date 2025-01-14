#include<bits/stdc++.h>
using namespace std;
void initialize(vector<int>&parent,vector<int>&rank,int n)
{
   
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
        rank[i]=0;
    }
}

int find(vector<int>&parent,int x)
{
   if(parent[x]!=x)
   {
    parent[x]=find(parent,parent[x]);
   }
   return parent[x];
}
void unionset(vector<int>&parent,vector<int>&rank,int x,int y)
{
     int rootx=find(parent,x);
     int rooty=find(parent,y);
     
     if(rank[rootx]<rank[rooty])
     {
        parent[rootx]=rooty;
     }
     else if(rank[rooty]<rank[rootx])
     {
        parent[rooty]=rootx;
     }
     else{

        parent[rooty] = rootx; // Make rootx the parent
        rank[rootx]++;
     }

}
int main()
{
    int n;
    cin>>n;
    vector<int>parent(n);
    vector<int>rank(n);
    initialize(parent,rank,n);
    unionset(parent,rank,0,1);
    unionset(parent,rank,1,2);
    cout<<"Root of 2 "<<find(parent,2)<<endl;
    cout<<"Rank of 0 "<<rank[0]<<endl;
    if(find(parent,1)==find(parent,2))
    {
        cout<<"The roots are same"<<endl;
    }
    else{
        cout<<"The root are diff"<<endl;
    }
}