//07
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int val;
    node* left;
    node* right;
    node* parent;
};
node* root=NULL;
void insert(node* p,int x)
{
    if(root==NULL)
    {
         root=new node();
         root->val=x;
         root->left=NULL;
         root->right=NULL;
         root->parent=NULL;
         return ;
    }
    else if(x<p->val)
    {
        if(p->left==NULL)
        {
            p->left=new node();
            p->left->val=x;
            p->left->left=NULL;
            p->left->right=NULL;
            p->left->parent=p;
        }
        else
        {
            insert(p->left,x);
        }
    }
    else  if(x>p->val)
    {
        if(p->right==NULL)
        {
            p->right=new node();
            p->right->val=x;
            p->right->left=NULL;
            p->right->right=NULL;
            p->right->parent=p;
        }
        else
        {
            insert(p->right,x);
        }
    }
    
}

void del(int x)
{
    node* p=root;
    while(p!=NULL)
    {
        if(x<p->val)
        {
           p=p->left;
        }
        else if(x>p->val)
        {
            p=p->right;
        }
        else
        {
            if(p->left==NULL && p->right==NULL) //no child
            {
                if(p->parent!=NULL)
                {
                    if(p->parent->left==p) p->parent->left=NULL;
                    else p->parent->right=NULL;
                }
                else
                {
                    root=NULL;
                }
                delete p;
                break;
            }
            if(p->left==NULL || p->right==NULL) //one child
            {
                node* child=(p->left!=NULL)?p->left:p->right;
                if(p->parent!=NULL)
                {
                    if(p->parent->left==p) p->parent->left=child;
                    else p->parent->right=child;
                }
                else
                {
                    root=child;
                }
                child->parent=p->parent;
                delete p;
                break;
            }
            else
            {
                node* temp=p->right;
                while(temp->left!=NULL) temp=temp->left;
                p->val=temp->val;
                x=temp->val;
                p=temp;
            }
        }
    }
}
void print(node* root)
{
    if(root==NULL) return;
    print(root->left);
    cout<<root->val<<endl;
    print(root->right);
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int v;
        cin>>v;
        insert(root,v);
    }
  int v;
  cin>>v;
  for(int i=0;i<v;i++)
  {
      int x;
      cin>>x;
      del(x);
  }
  print(root);
    
}