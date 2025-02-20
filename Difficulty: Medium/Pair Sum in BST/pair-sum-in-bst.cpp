//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000
#define MAX_SIZE 100000

// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
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
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
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

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
Node is as follows
class Node {
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
    bool findTarget(Node *root, int target) {
        // your code here.
        stack<Node *> inc, dec;
        Node *ptr = root;
        while(ptr){
            inc.push(ptr);
            ptr = ptr->left;
        }
        ptr = root;
        while(ptr){
            dec.push(ptr);
            ptr = ptr->right;
        }
        int incval=inc.top()->data, decval=dec.top()->data;
        Node *incvalnode=NULL, *decvalnode=NULL;
        while(incval < decval){
            if(incval+decval == target)
                return true;
            // moving left pointer of 2sum problem
            else if(incval+decval < target){
                incvalnode = inc.top();
                inc.pop();
                if(incvalnode->right){
                    inc.push(incvalnode = incvalnode->right);
                    while(incvalnode->left)
                        inc.push(incvalnode = incvalnode->left);
                }
                incval = inc.top()->data;
            }
            // moving right pointer of 2sum problem
            else{
                decvalnode = dec.top();
                dec.pop();
                if(decvalnode->left){
                    dec.push(decvalnode = decvalnode->left);
                    while(decvalnode->right)
                        dec.push(decvalnode = decvalnode->right);
                }
                decval = dec.top()->data;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);

        getline(cin, s);
        int k = stoi(s);
        // getline(cin, s);
        Solution obj;
        cout << obj.findTarget(root, k) << endl;
        // cout<<"~"<<endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends