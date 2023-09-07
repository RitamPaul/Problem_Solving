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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right)
            return head;
        ListNode *prelow=NULL, *low=NULL, *high=NULL, *posthigh=NULL;
        ListNode *ptr = head, *before = NULL, *after = NULL;
        int ind = 1;
        while(ptr){
            if(ind == left-1)
                prelow = ptr;
            else if(ind == right+1)
                posthigh = ptr;
            if(left<=ind and ind<=right){
                if(ind == left)     low = ptr;
                if(ind == right)    high = ptr;
                after = ptr;
                ptr = ptr->next;
                after->next = before;
                before = after;
            }
            if(ind<left or ind>right)
                ptr = ptr->next;
            ++ind;
        }
        if(left == 1)
            head = high;
        if(prelow)
            prelow->next = high;
        if(posthigh)
            low->next = posthigh;
        return head;
    }
};