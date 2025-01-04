//07
#include<bits/stdc++.h>
using namespace std;
struct node
{
     int data;
     node* left;
     node* right;
     node* mid;
     node(int data)
     {
        this->data=data;
        left=NULL;
        right=NULL;
        mid=NULL;
     }
};

node* findnode(node* root,int key)
{
      if (root == nullptr) return nullptr;  // Base case: node is NULL
      if (root->data == key) return root;   // If key matches, return the node

    // Recursively search in the left, right, and mid subtrees
    node* found = findnode(root->left, key);
    if (found != nullptr) return found;

    found = findnode(root->right, key);
    if (found != nullptr) return found;

    found = findnode(root->mid, key);
    return found;

}
void buildtree(int op,int key,int val,node* root)
{
     node* parent=findnode(root,key) ;
     if(parent==NULL) return; //base case;
     node* newnode=new node(val);
     if(op==0) parent->left=newnode;
     else if(op==1) parent->mid=newnode;
     else if(op==2) parent->right=newnode;
}
void print(node* root)
{
    if(root==NULL) return;
    print(root->left);
    print(root->mid);
    cout<<root->data<<endl;
    print(root->right);
}

int main()
{
    int r;
    cin>>r;
    node* root=new node(r); //creating the root node;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int op,key,val;
        cin>>op>>key>>val;
        buildtree(op,key,val,root);
    }
    print(root);
}