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

//just logic
 bool isSameTree(node* p, node* q) {

        if(p==NULL && q==NULL) return true;
        if(p!=NULL && q==NULL) return false;
        if(q!=NULL &&p==NULL) return false;

        bool left=isSameTree(p->left,q->left);
        bool right=isSameTree(p->right,q->right);
        bool value=(p->data==q->data);
        if(left&&right&&value) return true;
        else return false;
        
    }