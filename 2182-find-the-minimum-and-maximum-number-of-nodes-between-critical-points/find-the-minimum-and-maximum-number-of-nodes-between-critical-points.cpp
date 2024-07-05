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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *ptr=head->next, *prev=head;
        int initindex=-1, previndex=-1, curindex=-1;
        int index = 2;
        int mindis = INT_MAX;
        while(ptr->next){
            // found critical point : local minima or local maxima
            if((prev->val > ptr->val and ptr->val < ptr->next->val) or
                (prev->val < ptr->val and ptr->val > ptr->next->val)){
                // it is initial index of critical point
                if(initindex == -1)
                    initindex = previndex = curindex = index;
                else{
                    curindex = index;
                    mindis = min(mindis, curindex - previndex);
                    previndex = curindex;
                }
            }

            prev = ptr;
            ptr = ptr->next;
            ++index;
        }

        if(mindis != INT_MAX)
            return {mindis, curindex - initindex};
        return {-1, -1};
    }
};