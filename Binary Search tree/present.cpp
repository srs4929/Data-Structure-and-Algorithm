//if a given value is present or not
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

node* build(node* &root,int data){
    
    if(root==NULL)
    {
        root=new node(data);
        return root;
    }
    if(data>root->data)
    {
        root->right=build(root->right,data);

    }
    else{
        root->left=build(root->left,data);
    }
   return root;
}

bool check(node* &root,int data)
{
    //base case
    if(root==NULL)
    {
        return false;
    }
    //base case2 if found
    if(root->data==data)
    {
        return true;
    }
    if(root->data>data) //check for left
    {
         return check(root->left,data) ;
    }
    else{
        return check(root->right,data);
    }
}
void takeinput(node* &root)
{
    int data;
    cin>>data;
    while(data!=-1)
    {
        root=build(root,data);
        cin>>data;
    }
}
int main()
{
       node* root=NULL;
       takeinput(root);
       int data;
       cin>>data;
       cout<<check(root,data)<<endl;
}