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

int sumtree(node* root)
{
    if(root==NULL) return 0;

    return sumtree(root->left)+root->data+sumtree(root->right);
}

bool issum(node* root)
{
      if(root==NULL||(root->left && root->right)) return true;

      int ls=issum(root->left);
      int rs=issum(root->right);

      if((root->data==ls+rs)&&issum(root->left)&&issum(root->right)) return true;
      return false;

}

node* buildtree(node* root)
{
    cout<<"Enter the data"<<endl;
    int data;
    cin>>data;
    root=new node(data);
     if(data==-1) return NULL;
    cout<<"Enter data for left "<< data<<endl;
    root->left=buildtree(root->left);
    cout<<"Enter data for right "<<data<<endl;
    root->right=buildtree(root->right);
    return root;
   

}


int main()
{
    node* root=NULL;
    root= buildtree(root);
    cout<<issum(root)<<endl;
    

}