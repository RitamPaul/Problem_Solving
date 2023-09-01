/*
Structure of a node is as following
struct Node
{
     int data;
     struct Node* left;
     struct Node* right;
};
*/
void printCorner(Node *root){
    queue<Node *> q;
    q.push(root);
    while(q.size()){
        int count = q.size();
        for(int i=1; i<=count; ++i){
            Node *front = q.front();
            q.pop();
            if(i==1 or i==count)
                cout << front->data << " ";
            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);
        }
    }
}