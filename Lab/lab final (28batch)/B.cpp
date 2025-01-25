//07
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int val;
    node* left;
    node* right;
    node* mid;
    node(int val)
    {
        this->val=val;
        left=NULL;
        right=NULL;
        mid=NULL;
    }
};

node* find(node* root,int key)
{
     if(root==NULL)  return NULL;
     if(root->val==key) return root;
     node* found=find(root->left,key);
     if(found!=NULL) return found;
     found=find(root->right,key);
     if(found!=NULL) return found;
     found=find(root->mid,key);
     if(found!=NULL) return found;
     return NULL;
}

void buildtree(int op,int key,int val,node* root)
{
    node* parent=find(root,key);
    if(parent==NULL) return;
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
    cout<<root->val<<endl;
    print(root->right);
    
}
int main()
{
    int r;
    cin>>r;
    node* root=new node(r);
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