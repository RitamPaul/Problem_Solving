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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        
        vector<vector<int>> ans(m, vector<int>(n, -1));
        
        int topr=0, downr=m-1, leftc=0, rightc=n-1;
        
        // each boundary
        while(head and topr <= downr and leftc <= rightc){
            for(int j=leftc; j<=rightc and head; ++j){
                ans[topr][j] = head->val;
                head = head->next;
            }
            ++topr;

            if(topr <= downr and head){
                for(int i=topr; i<=downr and head; ++i){
                    ans[i][rightc] = head->val;
                    head = head->next;
                }
                --rightc;
            }
            if(head and topr <= downr and rightc >= leftc){
                for(int j=rightc; j>=leftc and head; --j){
                    ans[downr][j] = head->val;
                    head = head->next;
                }
                --downr;
            }
            if(head and downr >= topr and leftc <= rightc){
                for(int i=downr; i>=topr and head; --i){
                    ans[i][leftc] = head->val;
                    head = head->next;
                }
                ++leftc;
            }
        }

        return ans;
    }
};