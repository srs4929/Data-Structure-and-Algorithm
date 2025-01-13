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

node* minval(node* root) //find out the minimum value
{
    node* temp=root;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp;
}
node* maxvalue(node* root)// finding out the maxvalue
{
    node* temp=root;
    while(temp->right!=NULL)
    {
       temp=temp->right;   
    }
    return temp;
}
//deletion
node* del(node* root,int data)
{
     if(root==NULL) return NULL;
     if(root->data==data)
     {
        //0 child
         if(root->left==NULL&& root->right==NULL)
         {
            delete root;
            return NULL;
         }
        //1 child 
        //left case
        if(root->left!=NULL && root->right==NULL)
        {
            node* temp=root->left;
            delete root;
            return  temp;
        }
        //right child

        if(root->right!=NULL && root->left==NULL)
        {
            node* temp=root->right;
            delete root;
            return temp;
        }

        //2 child are present
        if(root->left!=NULL && root->right!=NULL)
        {
            int mini=minval(root->right)->data;
            //copy element
            root->data=mini;
            root->right=del(root->right,mini);
            return root;
        }
     }
     else if(root->data>data) // search for smaller
     {
         root->left=del(root->left,data);
         return root;
     }
     else{

        root->right=del(root->right,data);
        return root;
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
       cout<<"Before"<<endl;
       levelordertransversal(root);

       root=del(root,data);
       cout<<"After "<<endl;
       levelordertransversal( root);
    
}