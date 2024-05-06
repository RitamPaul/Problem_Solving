/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<pair<int,ListNode*>> s;
        ListNode *ptr=head;
        while(ptr){
            while(s.size() && s.top().first < ptr->val)
                s.pop();
            if(head->val < ptr->val)
                head = ptr;
            if(s.size())
                s.top().second->next = ptr;
            s.push({ptr->val, ptr});
            ptr = ptr->next;
        }
        return head;
    }
};