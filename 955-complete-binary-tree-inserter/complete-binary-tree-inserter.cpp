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
class CBTInserter {
public:
    TreeNode *root;
    queue<TreeNode *> q;
    CBTInserter(TreeNode* root) {
        this->root = root;
        queue<TreeNode *> bfs;
        TreeNode *front;
        int count;
        bfs.push(root);
        while(bfs.size()){
            count = bfs.size();
            while(count--){
                front = bfs.front();
                bfs.pop();

                if((front->left and !front->right) or (!front->left and !front->right))
                    q.push(front);
                
                if(front->left)         bfs.push(front->left);
                if(front->right)        bfs.push(front->right);
            }
        }
    }
    
    int insert(int val) {
        int ans = q.front()->val;
        if(q.front()->left){
            q.front()->right = new TreeNode(val);
            q.push(q.front()->right);
            q.pop();
        }
        else{
            q.front()->left = new TreeNode(val);
            q.push(q.front()->left);
        }
        return ans;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */