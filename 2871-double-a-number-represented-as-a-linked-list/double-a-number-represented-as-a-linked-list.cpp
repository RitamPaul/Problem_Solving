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
    ListNode* rev(ListNode *head){
        ListNode *ptr=head, *cur=head, *prev=NULL;
        while(ptr){
            ptr = ptr->next;
            cur->next = prev;
            prev = cur;
            cur = ptr;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        head = rev(head);
        ListNode *ptr = head, *prev = NULL;
        int carry = 0;
        while(ptr){
            int mul = ptr->val * 2;
            ptr->val = (mul % 10) + carry;
            carry = mul / 10;
            prev = ptr;
            ptr = ptr->next;
        }
        if(carry != 0)
            prev->next = new ListNode(carry);
        return rev(head);
    }
};