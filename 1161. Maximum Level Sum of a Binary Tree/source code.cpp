class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int ans = 1, sumcurrent = root->val, level=2;
        queue<TreeNode *> q;
        if(root->left)
            q.push(root->left);
        if(root->right)
            q.push(root->right);
        while(q.empty()==false){
            int count = q.size(), sumlevel=0;
            while(count--){
                TreeNode *front = q.front();
                q.pop();
                sumlevel += (front->val);
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }
            if(sumlevel > sumcurrent){
                ans = level;
                sumcurrent = sumlevel;
            }
            ++level;
        }
        return ans;
    }
};