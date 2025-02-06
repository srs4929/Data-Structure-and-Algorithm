#include<bits/stdc++.h>
using namespace std;

struct node  // node structure
{
    char data;
    int fre;
    node* left;
    node* right;
    node(char data, int fre)
    {
        this->data=data;
        this->fre=fre;
        left=NULL;
        right=NULL;
        
    }
};

struct Compare
{
    bool operator()(node* l, node* r)
    {
        return l->fre>r->fre;
    }
};

// function to print the huffman code
void printcode(node* root, string str)
{
    if(root==NULL) return ;
    
    if(root->left==NULL && root->right==NULL)
    {
        cout<<root->data<<" :"<<str<<endl;
    }
    printcode(root->left, str+"0");
    printcode(root->right,str+"1");
}

// main function to build huffman'
void huffman(char data[],int fre[],int size)
{
    priority_queue<node*,vector<node*>,Compare>minheap;
    
    // creating a leaf node
    for(int i=0;i<size;i++)
    {
        minheap.push(new node(data[i],fre[i]));
    }
    
    // building tree
    while(minheap.size()>1)
    {
        node* left=minheap.top(); // smallest one
        minheap.pop();
        node* right=minheap.top();
        minheap.pop();
        
        //creating a internal node summing up the frequency
        node* top=new node('#',left->fre+right->fre);
        //the two extracted node will be the children of new node
        top->left=left;
        top->right=right;
        minheap.push(top);
    }
    node* root=minheap.top();
    printcode(root,"");
}
int main()
{
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };

    int size = sizeof(arr) / sizeof(arr[0]);

    // Build the Huffman tree and print the codes
    huffman(arr, freq, size);
}