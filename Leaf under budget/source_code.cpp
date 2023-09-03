class Solution
{
public:
    void dfs(Node *root, int level, vector<int> &temp){
        if(root->left)
            dfs(root->left, level+1, temp);
        if(root->right)
            dfs(root->right, level+1, temp);
        if(!root->left and !root->right)
            temp.push_back(level);
        return;
    }
    int getCount(Node *root, int k){
        vector<int> temp;
        dfs(root, 1, temp);
        sort(temp.begin(), temp.end());
        int count=0;
        for(int i=0; i<temp.size(); ++i){
            if(k-temp[i] >= 0)
                ++count;
            else
                break;
            k -= temp[i];
        }
        return count;
    }
};