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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool match(ListNode *head, TreeNode *root){
        if(!head)       return true;
        if(!root)       return false;
        if(head->val != root->val)
            return false;
        
        bool leftmatch = match(head->next, root->left);
        if(leftmatch == true)
            return true;
        bool rightmatch = match(head->next, root->right);
        return rightmatch;
    }
    bool find(ListNode *head, TreeNode *root){
        if(!root)       return false;

        bool ans = match(head, root);
        if(ans == true)
            return true;

        bool leftfind = find(head, root->left);
        if(leftfind == true)
            return true;
        bool rightfind = find(head, root->right);
        return rightfind;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        return find(head, root);
    }
};