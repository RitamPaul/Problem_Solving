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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *h=NULL, *cur=NULL, *prev=NULL, *ptr=head, *temp;
        while(ptr){
            if(ptr->val == 0){
                int sum=0;
                if(ptr->next)
                    ptr = ptr->next;
                else
                    break;
                while(ptr->val != 0){
                    sum += ptr->val;
                    ptr = ptr->next;
                }
                
                cur = new ListNode(sum, NULL);
                if(prev)
                    prev->next = cur;
                prev = cur;

                if(!h)  h = cur;
                continue;
            }
            ptr = ptr->next;
        }
        return h;
    }
};