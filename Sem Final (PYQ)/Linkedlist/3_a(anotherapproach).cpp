
//Design a linked list with the following properties
/*
a)Insertion of an item in the first or last position take 0(1)
b)Deletion of an item from the middle position has the complexity o(1)
*/

//using double linkedlist
#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* next;
    node* prev;
    node(int data) {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

node* head = NULL;
node* tail = NULL;
node* mid = NULL;
int cnt = 0;

void infirst(int x) {
    node* p = new node(x);
    if (head == NULL) {
        head = tail = mid = p;
    } else {
        p->next = head;
        head->prev = p;
        head = p;
    }
    cnt++;
    if (cnt % 2 == 1 && cnt > 1) { // Ensure mid->prev exists before accessing
        mid = mid->prev;
    }
}

void inlast(int x) {
    node* p = new node(x);
    if (head == NULL) {
        head = tail = mid = p;
    } else {
        tail->next = p;
        p->prev = tail;
        tail = p;
    }
    cnt++;
    if (cnt % 2 == 0 && mid) { // Ensure mid->next exists before accessing
        mid = mid->next;
    }
}

void del() {
    if (mid == NULL) return;

    node* temp = mid;
    if (mid->prev) mid->prev->next = mid->next;
    if (mid->next) mid->next->prev = mid->prev;

    if (mid == head) head = head->next;
    if (mid == tail) tail = tail->prev;

    if (cnt % 2 == 0) mid = mid->prev;
    else mid = mid->next;

    cnt--;
    delete temp;

    // If list becomes empty, reset pointers
    if (cnt == 0) {
        head = tail = mid = NULL;
    }
}

void print() {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int main() {
    infirst(67);
    infirst(78);
    inlast(90);
    del();
    print();
}
