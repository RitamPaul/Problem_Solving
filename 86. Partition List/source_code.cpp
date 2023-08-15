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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next)     return head;
        queue<int> q;
        ListNode *ptr=head, *small=head;
        while(ptr){
            if(ptr->val < x){
                small->val = ptr->val;
                small = small -> next;
            }
            else
                q.push(ptr->val);
            ptr = ptr->next;
        }
        ptr = small;
        while(q.size()){
            ptr->val = q.front();
            q.pop();
            ptr = ptr->next;
        }
        return head;
    }
};