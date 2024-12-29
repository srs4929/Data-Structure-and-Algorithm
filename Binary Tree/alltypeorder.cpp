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
void inorder(node* root) //LNR(Left, node,right)
{
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node* root)//NLR(Node left right)
{ 
    if(root==NULL) return;
    cout<<root->data<<endl;
    preorder(root->left);
    preorder(root->right);

}

void postorder(node* root)//LRN(Left Right Node)
{
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<endl;
}

int main()
{
    node* root=NULL;
    root= buildtree(root);
    cout<<"Inorder transversal :"<<endl;
    inorder(root);
    cout<<"Preorder transversal :"<<endl;
    preorder(root);
    cout<<"Postorder transversal :"<<endl;
    postorder(root);

}