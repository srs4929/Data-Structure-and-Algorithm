//consider the input strings
//"The quick brown mouse jumps over the lazy cat"
//Build a huffman tree from the input text

#include<bits/stdc++.h>
using namespace std;

struct node
{
    char data;
    int fre;
    node* left;
    node* right;
    node(char data,int fre)
    {
        this->data=data;
        this->fre=fre;
        left=NULL;
        right=NULL;
    }
};

struct Compare
{
    bool operator()(node* left,node* right)
    {
        return left->fre>right->fre;
    }
};



void print(node* root, string x)
{
    if(root==NULL) return ;

    if(root->left==NULL && root->right==NULL)
    {
        cout<<root->data<<" : "<<x<<endl;
    }
    print(root->left,x+'0');
    print(root->right,x+'1');
}

void build(string x )
{
    map<char,int>m;
    for(auto c:x )
    {
          m[c]++;
    }

    priority_queue<node*,vector<node*>, Compare>minheap;

    for(auto pair:m)
    {
        minheap.push(new node(pair.first,pair.second));
    }

   while(minheap.size()>1)
   {
    node* left=minheap.top() ;
    minheap.pop(); // extract the mean
    node* right=minheap.top();
    minheap.pop();
    node* top=new node('#',left->fre+right->fre);
    minheap.push(top);
    top->left=left;
    top->right=right;

   }
   node* root=minheap.top();
   print(root," ");
  
}
int main()
{
      string x="The quick brown mouse jumps over the lazy cat";
      build(x);
}