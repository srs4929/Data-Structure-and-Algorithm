/*BST has property that all the nodes of a left have lower values and right have higher
have higher values.You have to build a tree from where all the nodes to the left will
higher value and right will have lower value
*/

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
    if(x<root->data) root->right=insert(root->right,x);
    else if(x>root->data) root->left=insert(root->left,x);
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
      
}