//07
#include <iostream>
using namespace std;

#define INT_MAX 2147483647

struct LinkedListNode{
        LinkedListNode *next;
        int val;
};

struct LinkedList{

    LinkedListNode *head=NULL;
    LinkedListNode *tail=NULL;

    void insert_last(int x)
    {
        //insert int x at last
        LinkedListNode* a=(LinkedListNode*)malloc(sizeof(LinkedListNode));
        a->next=NULL;
        a->val=x;
        if(tail)
        {
            tail->next=a;
            tail=a;
        }
        else
        {
            head=a;
            tail=a;
        }
    }

    void print()
    {
        LinkedListNode *p=head;
        while(p)
        {
            cout<<p->val<<endl;
            p=p->next;
        }
    }
};

struct LinkedListofLinkedListNode{
        LinkedListofLinkedListNode *next;
        LinkedList* list;
};

struct LinkedListofLinkedList{

    LinkedListofLinkedListNode *head=NULL;
    LinkedListofLinkedListNode *tail=NULL;

    void insert_last(LinkedList* x)
    {
        //insert LinkedList x at last
        LinkedListofLinkedListNode *a=(LinkedListofLinkedListNode*)malloc(sizeof(LinkedListofLinkedListNode));
        a->next=NULL;
        a->list=x;
        if(tail)
        {
            tail->next=a;
            tail=a;
        }
        else
        {
            head=a;
            tail=a;
        }
    }
};

LinkedList* sortLinkedListofLinkedList(LinkedListofLinkedList* lol){
    // You code starts here - 001
    if (!lol->head) return NULL;

    LinkedList* mergedList = lol->head->list; // Start with the first list
    LinkedListofLinkedListNode* current = lol->head->next; // Start from the second list

    // Merge lists one by one directly
    while (current) {
        LinkedListNode* dummy = new LinkedListNode(); // Dummy node to simplify merge
        LinkedListNode* tail = dummy;
        LinkedListNode* p1 = mergedList->head;
        LinkedListNode* p2 = current->list->head;

        // Merge two lists while both are non-empty
        while (p1 && p2) {
            if (p1->val <= p2->val) {
                tail->next = p1;
                p1 = p1->next;
            } else {
                tail->next = p2;
                p2 = p2->next;
            }
            tail = tail->next;
        }

        // Append remaining nodes
        if (p1) tail->next = p1;
        if (p2) tail->next = p2;

        // Set mergedList to the new merged list
        mergedList->head = dummy->next;

        // Find the new tail of the merged list
        tail = mergedList->head;
        while (tail && tail->next) {
            tail = tail->next;
        }
        mergedList->tail = tail;

        // Move to the next list in the list of linked lists
        current = current->next;
    }

    return mergedList;
    // You code ends here - 001
}

int main() {
    
    int n, m, v;
    cin>>n;
    LinkedListofLinkedList* lol = new LinkedListofLinkedList();
    for(int i = 0;i<n;i++){
        LinkedList* l = new LinkedList();
        cin>>m;
        for(int j= 0;j<m;j++){
            cin>>v;
            l->insert_last(v);
        }
        lol->insert_last(l);
    }
    
    LinkedList* sorted = sortLinkedListofLinkedList(lol);

    sorted->print();
    


    return 0;
}

