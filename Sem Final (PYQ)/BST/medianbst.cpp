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

void count_nodes(node* root,int &c)
{
    if(root==NULL) return;
    count_nodes(root->left,c);
    c++;
    count_nodes(root->right,c);
}
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
void inorder(node* &root,vector<int>&arr)
{
    if(root==NULL) return ;
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}
void fun(node* &root,node* &curr,node* & prev,int x,int &c,int &f)
{
    if(root==NULL) return ;
    fun(root->left,curr,prev,x,c,f);
     if(prev==NULL)
     {
        prev=root;
        c++;
     }
     else if(c==x)
     {
         c++;
         curr=root;
         f=1;
         return;
     }
     else if(f==0)
     {
        c++;
        prev=root;
     }
     fun(root->right,curr,prev,x,c,f);

}
double median(node* root)
{
    int n=0;
    count_nodes(root,n);
    node* curr=NULL;
    node* prev=NULL;
    int c=1;
    int x=(n/2)+1;
    int f=0;
    fun(root,curr,prev,x,c,f);
    if(n&1) return (curr->data)*1.0;
    else{
        return ((curr->data+ prev->data)*1.0)/2.0;
    }
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
    cout<<median(root)<<endl;
   
   
}