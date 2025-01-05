//07
#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

node* findnode(node* root, int val) {
    if (root == NULL)
        return NULL;
    if (root->data == val)
        return root;
    node* found = findnode(root->left, val);
    if (found != NULL)
        return found;
    return findnode(root->right, val);
}

void buildtree(node* root, int op, int key, int val) {
    node* parent = findnode(root, key);
    if (parent == NULL) {
        
        return;
    }
    node* newnode = new node(val);
    if (op == 0)
        parent->left = newnode;
    else if (op == 1)
        parent->right = newnode;
}

int equal(node* r1, node* r2) {
    if (r1 == NULL && r2 == NULL)
        return 1;
    if (r1 == NULL || r2 == NULL)
        return 0;
    return (r1->data == r2->data && equal(r1->left, r2->left) && equal(r1->right, r2->right));
}

int main() {
    int r1;
    cin >> r1;
    node* root1 = new node(r1);
    int n;
    cin >> n;

    if (n == 0) {
       
        return 0;
    }

    for (int i = 0; i < n; i++) {
        int op, key, val;
        cin >> op >> key >> val;
        buildtree(root1, op, key, val);
    }

    int r2;
    cin >> r2;
    node* root2 = new node(r2);
    int n2;
    cin >> n2;

    if (n2 == 0) {
       
        return 0;
    }

    for (int i = 0; i < n2; i++) {
        int op, key, val;
        cin >> op >> key >> val;
        buildtree(root2, op, key, val);
    }

    cout << equal(root1, root2) << endl;
    return 0;
}
