// your task is to complete the Function
// Function should return median of the BST
void number(Node *root, int &count){
    if(!root)   return;
    count++;
    number(root->left, count);
    number(root->right, count);
    return;
}
void median(Node *root, int &count, int sind, int eind, float &ans){
    if(!root)   return;
    median(root->left, count, sind, eind, ans);
    
    count++;
    if(count==sind)     ans = root->data;
    if(count==eind)     ans = (ans + (float)root->data) / 2;
    
    median(root->right, count, sind, eind, ans);
    return;
}
float findMedian(struct Node *root){
    int count=0, sind=0, eind=0;
    float ans=0;
    number(root, count);
    //even number of nodes
    if(count%2 == 0){
        sind = count / 2;
        eind = sind + 1;
    }
    //odd number of nodes
    else if(count&1 == 1){
        sind = (count/2) + 1;
        eind = sind;
    }
    count = 0;
    median(root, count, sind, eind, ans);
    return ans;
}