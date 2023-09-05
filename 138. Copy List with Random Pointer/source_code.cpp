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

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;
        unordered_map<Node *, Node *> mp;
        Node *ptr = head, *anshead = NULL;
        while(ptr){
            mp[ptr] = new Node(ptr->val);
            ptr = ptr->next;
        }
        ptr = head;
        while(ptr){
            if(!anshead)
                anshead = mp[ptr];
            mp[ptr]->next = mp[ptr->next];
            if(ptr->random)
                mp[ptr]->random = mp[ptr->random];
            else
                mp[ptr]->random = NULL;
            ptr = ptr->next;
        }
        return anshead;
    }
};