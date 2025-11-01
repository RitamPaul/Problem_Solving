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
    int bs(int target, vector<int>& nums){
        int n=nums.size(), low=0, high=n-1, mid;
        while(low<=high){
            mid = low + (high-low) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                low = mid+1;
            else
                high = mid-1;
        }
        return -1;
    }
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        sort(nums.begin(), nums.end());
        ListNode *cur=head, *prev=NULL;
        while(cur){
            if(bs(cur->val, nums) >= 0){
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