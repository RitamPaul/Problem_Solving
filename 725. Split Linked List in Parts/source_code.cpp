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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode *> ans(k, NULL);
        int count=0, div, excess, i=0, ind=0;
        ListNode *ptr=head, *prev;

        if(!head)   return ans;
        
        while(ptr){
            ++count;
            ptr = ptr->next;
        }
        if(k > count){
            div = 1;
            excess = 0;
        }
        else{
            div = count / k;
            excess = count % k;
        }
        ptr = head;
        
        while(true){
            if(excess==0)
                i = 0;
            else{
                i = 1;
                excess--;
            }
            count = div + i;
            ans[ind] = ptr;
            while(count && ptr){
                prev = ptr;
                ptr = ptr->next;
                count--;
            }
            prev->next = NULL;
            ind++;
            if(!ptr)
                break;
        }
        return ans;
    }
};