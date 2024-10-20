#include <bits/stdc++.h>
using namespace std;

// Definition for a Doubly Linked List Node
struct DLLNode {
    int data;
    DLLNode* next;
    DLLNode* prev;
    DLLNode(int x) : data(x), next(nullptr), prev(nullptr) {}
};

class Solution {
  public:
    // Function to sort a k-sorted doubly linked list
    DLLNode* sortAKSortedDLL(DLLNode* head, int k) {
        if (!head) return nullptr;

        // Custom comparator for the priority queue to compare node data
        auto compare = [](DLLNode* a, DLLNode* b) { return a->data > b->data; };
        
        // Min-heap to store the nodes
        priority_queue<DLLNode*, vector<DLLNode*>, decltype(compare)> minHeap(compare);

        DLLNode* newHead = nullptr, *last = nullptr;

        // Insert the first k+1 elements into the heap
        DLLNode* current = head;
        for (int i = 0; i <= k && current != nullptr; ++i) {
            minHeap.push(current);
            current = current->next;
        }

        // Process all nodes
        while (!minHeap.empty()) {
            DLLNode* smallest = minHeap.top();
            minHeap.pop();

            // If this is the first element, it becomes the new head
            if (!newHead) {
                newHead = smallest;
                last = newHead;
                last->prev = nullptr;
            } else {
                // Connect the last sorted node to the current smallest node
                last->next = smallest;
                smallest->prev = last;
                last = smallest;
            }

            // Insert the next element into the heap if it exists
            if (current) {
                minHeap.push(current);
                current = current->next;
            }
        }

        // Ensure the last node points to nullptr
        last->next = nullptr;

        return newHead;
    }
};

// Helper function to print the list
void printList(DLLNode* head) {
    while (head) {
        cout << head->data;
        head = head->next;
        if (head) cout << " <-> ";
    }
    cout << endl;
}

// Helper function to create a doubly linked list from a vector
DLLNode* createList(vector<int> arr) {
    if (arr.empty()) return nullptr;
    
    DLLNode* head = new DLLNode(arr[0]);
    DLLNode* current = head;
    
    for (int i = 1; i < arr.size(); i++) {
        DLLNode* temp = new DLLNode(arr[i]);
        current->next = temp;
        temp->prev = current;
        current = temp;
    }
    
    return head;
}

// Main function for testing
int main() {
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    int k = 2;
    
    DLLNode* head = createList(arr);
    
    Solution obj;
    DLLNode* sortedHead = obj.sortAKSortedDLL(head, k);
    
    printList(sortedHead);
    
    return 0;
}
