#include<bits/stdc++.h>
using namespace std;
struct node
{
   int data;
   node *left;
   node *right;
   node(int data)
   {
     this->data =data;
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
   if(data==-1) return NULL; //-1 is said to be null
   cout<<"Enter data for inserting in left "<<data<<endl;
   root->left=buildtree(root->left);
   cout<<"Enter data for inserting in right "<<data<<endl;
   root->right=buildtree(root->right);



}
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
int main()
{
    node* root=NULL;
    //creating a tree
    root=buildtree(root);
    //levelordertransversal
    levelordertransversal(root);

}