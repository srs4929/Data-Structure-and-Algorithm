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

void union_by_size(int a, int b) {
    a = rootfind(a);
    b = rootfind(b);
    if (a == b) return;
    if (size[a] > size[b]) {
        parent[b] = a;
        size[a] += size[b];
    } else if (size[a] < size[b]) {
        parent[a] = b;
        size[b] += size[a];
    } else { // Sizes are equal, break tie using node value
        if (a < b) { // Attach root of larger value to smaller value
            parent[b] = a;
            size[a] += size[b];
        } else {
            parent[a] = b;
            size[b] += size[a];
        }
    }
}


void rankfunction(int a,int b)
{
     a=rootfind(a);
     b=rootfind(b);
     if(a==b) return; 
     if(ranklist[a]>ranklist[b])
     {
          parent[b]=a;
     }
     else if(ranklist[b]>ranklist[a])
     {
        parent[a]=b;
     }
     else{
        parent[b]=a;
        ranklist[a]++;
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
     union_by_size(1,2);
      union_by_size(2,3);
      rankfunction(4,5);
      rankfunction(6,7);
     union_by_size(5,6);  
     cout<<rootfind(7)<<endl;
}