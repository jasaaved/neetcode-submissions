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
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;

        return search(mp, head);
    }

private:
    Node* search(unordered_map<Node*, Node*>& mp, Node* current) {
        if(current == nullptr) {
            return nullptr;
        }

        if(!mp.contains(current)){
            Node* new_node = new Node(current->val);
            mp[current] = new_node;

            new_node->next = search(mp, current->next);
            new_node->random = search(mp, current->random);
        }

        return mp[current];
    }
};
