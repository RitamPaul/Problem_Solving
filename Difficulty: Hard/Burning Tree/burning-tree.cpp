/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int target2closeleaf, target2farleaf, targetfound;
    pair<int,int> dfs(Node *root, int target){
        if(!root)
            return {false,0};
        pair<int,int> lc=dfs(root->left, target);
        bool foundinleft=lc.first;
        int leafdisinleft=lc.second;
        pair<int,int> rc=dfs(root->right, target);
        bool foundinright=rc.first;
        int leafdisinright=rc.second;
        
        // from now, we will send distance till this node not till leaf
        if(root->data==target){
            target2closeleaf=max({target2closeleaf, leafdisinleft, leafdisinright});
            return {true,1};
        }
        if(foundinleft or foundinright){
            target2farleaf = max({target2farleaf, leafdisinleft+leafdisinright});
            if(foundinleft)
                return {true,leafdisinleft+1};
            return {true,leafdisinright+1};
        }
        return {false,max(leafdisinleft,leafdisinright)+1};
    }
    int minTime(Node* root, int target) {
        // code here
        target2closeleaf=target2farleaf=targetfound=0;
        dfs(root, target);
        return max(target2closeleaf,target2farleaf);
    }
};