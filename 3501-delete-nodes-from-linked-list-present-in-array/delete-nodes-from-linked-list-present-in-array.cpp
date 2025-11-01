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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st;
        for (auto& i : nums)
            st.insert(i);

        ListNode *prev = NULL, *cur = head;
        while (cur) {
            if (st.count(cur->val)){
                if(!prev)
                    head = head->next;
                else
                    prev->next = cur->next;
            }
            else
                prev = cur;
            cur = cur->next;
        }
        return head;
    }
};