//write a code to traverse a binary search tree in such order that the generated output
//is in descinding order

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
node* insert(node* root,int key)
{
    if(root==NULL)
    {
       return new node(key);
    }
    if(key<root->data) root->left=insert(root->left,key);
    else if(key>root->data) root->right=insert(root->right,key);
    return root;
}
void print(node* &root)
{
    if(root==NULL) return ;
    print(root->right);
    cout<<root->data<<endl;
    print(root->left);
}


int main()
{
    int n;
    cin>>n;
    node* root=NULL;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        root=insert(root,x);
    }
    print(root);
   
   
}