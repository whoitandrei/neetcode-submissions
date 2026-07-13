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

// 1. forward copy list
// 2. create hash map to map old nodes to new nodes
// 3. initialize random pointer nodes

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        unordered_map<Node*, Node*> mp;

        for (Node* cur = head; cur != nullptr; cur = cur->next) {
            mp[cur] = new Node(cur->val);
        }

        for (Node* cur = head; cur != nullptr; cur = cur->next) {
            mp[cur]->next = mp[cur->next];
            mp[cur]->random = mp[cur->random];
        }

        return mp[head];
    }
};
