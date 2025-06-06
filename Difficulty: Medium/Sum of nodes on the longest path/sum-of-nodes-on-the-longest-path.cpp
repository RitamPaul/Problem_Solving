/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    int maxheight, maxsum;
    void f(Node *root, int cursum, int curheight){
        if(!root){
            if(curheight>maxheight){
                maxheight = curheight;
                maxsum = cursum;
            }
            else if(curheight==maxheight and cursum>maxsum)
                maxsum = cursum;
            return;
        }
        f(root->left, cursum+root->data, curheight+1);
        f(root->right, cursum+root->data, curheight+1);
        return;
    }
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        maxheight=0;
        maxsum=INT_MIN;
        f(root, 0, 1);
        return this->maxsum;
    }
};