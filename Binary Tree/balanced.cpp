
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

int height(node* root)
{
    if(root==NULL) return 0;
    int h1=height(root->left);
    int h2=height(root->right);
    int ans=max(h1,h2)+1;
    return ans;
}
bool balanced(node* root)
{
    if(root==NULL) return true;
    bool left=balanced(root->left);
    bool right=balanced(root->right);
    bool diff=abs(height(root->left)-height(root->right))<=1;
    if(left&&right&&diff) return true;
    else return false;


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
   // cout<<height(root)<<endl;
   cout<<balanced(root)<<endl;
    

}

