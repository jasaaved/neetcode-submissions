/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
#include <unordered_map>

using namespace std;

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* current = head;
        unordered_map<Node*, Node*> mp;

        while(current != nullptr) {
            mp[current] = new Node(current->val);
            current = current->next;  
        }

        current = head;
        while(current != nullptr) {
            mp[current]->next = mp[current->next]; 
            mp[current]->random = mp[current->random];
            current = current->next;
        }

        return mp[head];
    }
};
