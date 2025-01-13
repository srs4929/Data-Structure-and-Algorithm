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

void levelordertransversal(node* root)
{
   queue<node*>q;
   q.push(root);
   q.push(NULL);
   while(!q.empty())
   {
      node* temp=q.front();
      
      q.pop();

      if(temp==NULL)//the previous level completed
      {
         cout<<endl;
         if(!q.empty())//queue has still some nodes
         {
            q.push(NULL);
         }
      }
      else{
       cout<<temp->data<<" ";  
      if(temp->left)
      {
         q.push(temp->left);
      }
      if(temp->right)
      {
         q.push(temp->right);
      }
      }
   }
}
node* insert(node* root,int d)
{
    if(root==NULL) {
       root=new node(d) ;
       return root;
    }

    if(d >root->data)
    {   
        root->right=insert(root->right,d);
    }
    else{
        root->left=insert(root->left,d);
    }
    return root;

}
void takeinput(node* &root)
{
    int data;
    cin>>data;
    while(data!=-1)
    {
        root=insert(root,data);
        cin>>data;
    }
}
int main()
{
       node* root=NULL;
       cout<<"Enter data to craete BST"<<endl;
       takeinput(root);
       levelordertransversal(root);
}