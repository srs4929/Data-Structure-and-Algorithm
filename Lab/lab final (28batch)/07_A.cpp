//07
#include <iostream> 
using namespace std; 
 

struct Node { 
    int key; 
    int value;  // Frequency of the key 
    Node* next; // Pointer to the next node in case of collision 
     
    Node(int key,int value)
    {
        this->key=key;
        this->value=value;
        next=NULL;
    }
}; 
 
// Define the size of the hash table 
const int SIZE = 100003;  
// Hash table to store the linked list of nodes (buckets) 
Node* table[SIZE]; 
 

int hashFunction(int key) { 
    return (key % SIZE + SIZE) % SIZE;  // To handle negative keys 
} 
 
// Function to insert a key into the hash table and increment its frequency 
void insert(int key) { 
    int index = hashFunction(key); 
    Node* head = table[index]; 
 
   
    while (head) { 
        if (head->key == key) { 
            head->value++;  // If key is found, increment the frequency 
            return; 
        } 
        head = head->next; 
    } 
 
    // If key is not found, create a new node and insert it at the front 
    Node* newNode = new Node(key, 1);  // Start with a frequency of 1 
    newNode->next = table[index]; 
    table[index] = newNode;  
} 
 
// Function to get the frequency of a key 
int getFrequency(int key) { 
    int index = hashFunction(key); 
    Node* head = table[index]; 
 
    
    while (head) { 
        if (head->key == key) { 
            return head->value;  // Return the frequency if the key is found 
        } 
        head = head->next; 
    } 
 
    return 0;  // Return 0 if the key is not found 
} 
 
int main() { 
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
 
    int n, m; 
    cin >> n; 
 
    // Initialize the hash table to nullptr 
    for (int i = 0; i < SIZE; ++i) { 
        table[i] = nullptr; 
    } 
 
    // Insert numbers into the hash table 
    for (int i = 0; i < n; i++) { 
        int v; 
        cin >> v; 
        insert(v); 
    } 
 
    cin >> m; 
 
    // Process each query and print the frequency of the query number 
    for (int i = 0; i < m; i++) { 
        int q; 
        cin >> q; 
        cout << getFrequency(q) << '\n'; 
    } 
 
    return 0; 
}