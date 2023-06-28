/* The Node structure is
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution{
  public:
    /*You are required to complete this method*/
    int maxDepth(Node *root) {
        queue<Node *> q;
        Node *ptr=NULL;
        int ans=1;
        if(root->left)
            q.push(root->left);
        if(root->right)
            q.push(root->right);
        while(q.empty()==false){
            int count = q.size();
            ans++;
            while(count--){
                ptr = q.front();
                q.pop();
                if(ptr->left)
                    q.push(ptr->left);
                if(ptr->right)
                    q.push(ptr->right);
            }
        }
        return ans;
    }
};