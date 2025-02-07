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
void inorder(node* &root,vector<int>&arr)
{
    if(root==NULL) return ;
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}

double median(node* root)
{
    vector<int>arr;
    inorder(root,arr);
    int n=arr.size();
    if(n%2==0)
    {
        return (arr[n/2-1]+arr[n/2])/2.0;
    }
    else return (arr[n/2]);
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