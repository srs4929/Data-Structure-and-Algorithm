
//given binary search tree no elements common. make a tree which combine both tree
//contaning elements from both bst

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

vector<int>mergearray(vector<int>&a,vector<int>&b)
{
        vector<int>ans(a.size()+b.size());
        int i=0;
        int j=0;
        int k=0;
        while(i<a.size()&&j<b.size())
        {
             if(a[i]<b[j])
             {
                ans[k++]=a[i++];
             }
             else 
             {
                ans[k++]=b[j++];
             }
        }
        while(i<a.size())
        {
            ans[k++]=a[i++];
        }
        while(j<b.size())
        {
            ans[k++]=b[j++];
        }
        return ans;
}

node* bst(vector<int>&arr,int s,int e)
{
    if(s>e) return NULL;
    int mid=(s+e)/2;
    node* root=new node(arr[mid]);
    root->left=bst(arr,s,mid-1);
    root->right=bst(arr,mid+1,e);
    return root;
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
void inorder(node* &root,vector<int>&bst)
{
    if(root==NULL) return ;
    inorder(root->left,bst);
    bst.push_back(root->data);
    inorder(root->right,bst);
}
// Print BST in In-order Traversal
void printBST(node* root) {
    if (root == NULL) return;
    printBST(root->left);
    cout << root->data << " ";
    printBST(root->right);
}


int main()
{
    int n1;
    cin>>n1;
    node* root1=NULL;
    for(int i=0;i<n1;i++)
    {
        int x;
        cin>>x;
        root1=insert(root1,x);
    }
   // print(root);

   int n2;
   cin>>n2;
   node* root2=NULL;

   for(int i=0;i<n2;i++)
   {
    int x;
    cin>>x;
    root2=insert(root2,x);
   }
   vector<int>bst1,bst2;
   inorder(root1,bst1);
   inorder(root2,bst2);
   vector<int>merged=mergearray(bst1,bst2);
   node* mergebst=bst(merged,0,merged.size()-1);
   printBST(mergebst);
   
}