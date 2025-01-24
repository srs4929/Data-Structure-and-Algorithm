#include<bits/stdc++.h>
using namespace std;
int parent[10000];
int ranklist[10000];
int size[10000];
void make_set(int x)
{
    parent[x]=x;// the root is itself first
    ranklist[x]=0;
    size[x]=1; //initially the size is 1

}



int rootfind(int a)
{
       if(a==parent[a]) return a;
       return parent[a]=rootfind(parent[a]);
}

void union_by_size(int a ,int b)
{
    a=rootfind(a);
    b=rootfind(b);
    if(a==b) return;
    if(size[a]>size[b])
    {
        parent[b]=a;
        size[a]+=size[b];
    }
    else if(size[b]>size[a]){
        parent[a]=b;
        size[b]+=size[a];
    }
}


int main()
{
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        make_set(i);
    }
    union_by_size(3,4);
    cout<<rootfind(4)<<endl;
}