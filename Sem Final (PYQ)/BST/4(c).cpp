// c) Let, a binary search tree B has the property that all the nodes to the left of a node have lower values than it and those to the right have higher values.
//  You have to build a new tree from B where all the nodes to the left of a node have higher values and those to the right have lower values. 
// Write a pseudocode to an efficient algorithm to do so.

#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
    node(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

node* insert(node* root,int x)
{
    if(root==NULL) 
    {
        return new node(x);
    }
    if(x<root->data) root->left=insert(root->left,x);
    else if(x>root->data) root->right=insert(root->right,x);
    return root;

}

//function to mirror

node* mirror(node* root)
{
    if(root==NULL) return;
    //swapping left and right recursively

    node* left=mirror(root->right);
    node* right=mirror(root->left);
    root->left=left;
    root->right=right;
    return root;
}

void print(node* root)
{    
    if(root==NULL) return;
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);

}
int main()
{
     node* root=NULL;
     int n;
     cin>>n;
     for(int i=0;i<n;i++)
     {
        int x;
        cin>>x;
        root=insert(root,x);
     }

     print(root);
     //store mirror
     root=mirror(root);
     print(root);
      
}