//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
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
    int ans;
    pair<bool,int> func(Node *root, int target){
        // base case
        if(!root)
            return {false,0};
        
        // recursive case
        pair<bool,int> lc = func(root->left, target);
        pair<bool,int> rc = func(root->right, target);
        bool foundleft = lc.first;
        bool foundright = rc.first;
        int maxdisleft = lc.second;
        int maxdisright = rc.second;
        
        // backtracking case
        bool targetfound = foundleft or foundright or (root->data == target);
        
        if(foundleft or foundright)
            ans = max(ans, maxdisleft+maxdisright);
        else if(root->data == target)
            ans = max(ans, max(maxdisleft,maxdisright));
        
        int heightreturn;
        if(root->data == target)
            heightreturn = 1;
        else if(foundleft)
            heightreturn = maxdisleft + 1;
        else if(foundright)
            heightreturn = maxdisright + 1;
        else
            heightreturn = max(maxdisleft,maxdisright) + 1;
        
        // return from current state
        return {targetfound, heightreturn};
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        ans = 0;
        pair<bool,int> dummy = func(root, target);
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends