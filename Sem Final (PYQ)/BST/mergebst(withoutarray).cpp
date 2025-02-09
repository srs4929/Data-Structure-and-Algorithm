// You are given two bst.Write down an efficient algo to combine both of them
#include<bits/stdc++.h>
using namespace std;

struct node
{
   int data;
   node* left;
   node* right;
   node(int x)
   {
    this->data=x;
    left=NULL;
    right=NULL;
   }
};

node* insert(node* root,int d)
{
    if(root==NULL) return new node(d);
    if(d<root->data) root->left=insert(root->left,d);
    else root->right=insert(root->right,d);
    return root;
}
//to combine
void inorder(node* &root,node* &merge)
{
    if(root!=NULL)
    {
        inorder(root->left,merge);
        merge=insert(merge,root->data);
        inorder(root->right,merge);
    }
}

node* mergetwo(node* &root1,node* &root2)
{
    node* mergehead=NULL;
    inorder(root1,mergehead);
    inorder(root2,mergehead);
    return mergehead;
}
//print in inorder

void print(node* root)
{
    if(root==NULL)
    {
        return;
    }
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}
int main()
{
     node* root1 = NULL;
    node* root2 = NULL;

    root1 = insert(root1, 10);
    root1 = insert(root1, 5);
    root1 = insert(root1, 15);

    root2 = insert(root2, 12);
    root2 = insert(root2, 3);
    root2 = insert(root2, 7);

    node* mergedBST = mergetwo(root1, root2);

    cout << "Merged BST Inorder Traversal: ";
    print(mergedBST);
    cout << endl;   

    // The time complexity of this algorithm is O(n + m)
    //insertion time o(nlogn)
}