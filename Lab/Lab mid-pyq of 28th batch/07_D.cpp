//07
#include<bits/stdc++.h>
using namespace std;
struct node
{
      int val;
      node* left;
      node* right;
      node(int val)
      {
          this->val=val;
          left=NULL;
          right=NULL;
      }
};
node* insert(node* &root,int x)
{
    if(root==NULL)
    {
        node* p=new node(x);
        root=p;
        return root;
    }
    if(x>root->val)
    {
        //root->right=x;
        root->right=insert(root->right,x);
    }
    else
    {
        //root->left=x;
        root->left=insert(root->left,x);
    }
    return root;
}
node* min(node* root)
{
    node* temp=root;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp;
}
node* del(node* &root, int d)
{
    if(root==NULL) return NULL;
    if(d>root->val) root->right=del(root->right,d);
    else if(d<root->val) root->left=del(root->left,d);
    else if(root->val==d)
    {
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        }
        else if(root->left!=NULL && root->right==NULL)
        {
            node* temp=root->left;
            delete root;
            return temp;
            
        }
        else if(root->right!=NULL && root->left==NULL)
        {
            node* temp=root->right;
            delete root;
            return temp;
        }
        node* temp = min(root->right);
        root->val = temp->val;
        root->right = del(root->right, temp->val);
    }
    return root;
}
void inorder(node* &root)
{
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->val<<endl;
    inorder(root->right);
    
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
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int k;
        cin>>k;
        root=del(root,k);
    }
    inorder(root);
}