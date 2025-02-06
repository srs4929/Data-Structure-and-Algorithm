#include<bits/stdc++.h>
using namespace std;
struct node
{
   int fre;
   char data;
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
    bool operator()(node* l,node* r)
    {
          return l->fre>r->fre;
    }
};

// printing the code

void printcode(node* root,string str)
{
    if(root==NULL) return ;
    
    if(root->left==NULL && root->right==NULL)
    {
        cout<<root->data<<" :"<<str<<endl;
    }
    printcode(root->left, str+"0");
    printcode(root->right,str+"1");
}

//build hufffman tree

void huffman(string x)
{
    map<char,int>p;
    for(auto c: x)
    {
        p[c]++;
    }

    //creating minheap
    priority_queue<node*,vector<node*>,Compare>minheap;

    for(auto pair: p)
    {
          minheap.push(new node(pair.first,pair.second)); // pair.first =key a,d pair.second=key value
    }

    //hufftree build
    while(minheap.size()>1)
    {
        node* left=minheap.top();
        minheap.pop();
        node* right=minheap.top();
        minheap.pop();
        node* top=new node('#',left->fre+right->fre);
        //make the left& right the child
        top->left=left;
        top->right=right;
        minheap.push(top);
    }
    // the last one is root;
    node* root=minheap.top();
    printcode(root,"");

}
int main()
{
    string x;
    cin>>x;
    huffman(x);
    
}
