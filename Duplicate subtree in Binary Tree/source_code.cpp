/*The structure of the Binary Tree Node  is
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/

class Solution {
  public:
    pair<string,int> helper(Node *root, unordered_map<string,bool> &mp){
        // base case
        if(!root)
            return {"N",0};
        
        // recursive case
        pair<string,int> left = helper(root->left, mp);
        string leftsubtree = left.first;
        if(leftsubtree.size() == 0)
            return {"", 1};
        int leftcountnode = left.second;
        
        pair<string,int> right = helper(root->right, mp);
        string rightsubtree = right.first;
        if(rightsubtree.size() == 0)
            return {"", 1};
        int rightcountnode = right.second;
        
        string cursubtree = root->data + "-" + leftsubtree + "-" + rightsubtree;
        int curcountnode = leftcountnode + 1 + rightcountnode;
        
        // cursubtree already found && its size >= 2
        if(curcountnode >= 2 and mp.find(cursubtree) != mp.end())
            return {"", 1};
        mp[cursubtree] = true;
        return {cursubtree, curcountnode};
    }
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    int dupSub(Node *root) {
        unordered_map<string,bool> mp;
        return helper(root, mp).first.size() == 0;
    }
};