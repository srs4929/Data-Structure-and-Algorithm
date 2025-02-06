//you have to encode the text "bobs runs over the river". However character u in not
//your huffman tree.How you modufy the tree to assign a code letter to u

//Added a check for 'u' in the frequency map and assigned it a small frequency if missing.

#include<bits/stdc++.h>
using namespace std;

struct node
{
    char data;
    int fre;
    node* left;
    node* right;
    node(char data,int fre)
    {
        this->data=data;
        this->fre=fre;
        left=NULL;
        right=NULL;
    }
};

struct Compare
{
    bool operator()(node* left,node* right)
    {
        return left->fre>right->fre;
    }
};

//store the huffman generated codes

unordered_map<char,string>codes;

void print(node* root, string x)
{
    if(root==NULL) return ;

    if(root->left==NULL && root->right==NULL)
    {   
        codes[root->data]=x;
        //cout<<root->data<<" : "<<x<<endl;
    }
    print(root->left,x+'0');
    print(root->right,x+'1');
}

node* build(string x )
{
    map<char,int>m;
    for(auto c:x )
    {
          m[c]++;
    }

    if(m.find('u')==m.end())
    {
        m['u']=1;  //did not find so add it
    }

    priority_queue<node*,vector<node*>, Compare>minheap;

    for(auto pair:m)
    {
        minheap.push(new node(pair.first,pair.second));
    }

   while(minheap.size()>1)
   {
    node* left=minheap.top() ;
    minheap.pop(); // extract the mean
    node* right=minheap.top();
    minheap.pop();
    node* top=new node('#',left->fre+right->fre);
    minheap.push(top);
    top->left=left;
    top->right=right;

   }
   
   return minheap.top();
}

//encode text using the stored codes
string encode(string message)
{
    string enstring="";
    for (char c: message)
    {
        enstring+=codes[c];
    }
    return enstring;
}
int main()
{
      string x="The quick brown mouse jumps over the lazy cat";
      node* root=build(x);
      print(root,"");
       // Example encoding
    string message = "bob jumps over the tree";
    string encodedMessage = encode(message);
    cout << "Encoded: " << encodedMessage << endl;

}