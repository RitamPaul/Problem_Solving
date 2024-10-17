//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        // Your code here
        Node *h1=NULL, *h2=NULL, *p1=NULL, *p2=NULL, *ptr=head;
        while(ptr){
            if(!h1)
                h1 = p1 = ptr;
            else if(!h2)
                h2 = p2 = ptr;
            else{
                p1->next = ptr;
                p1 = p1->next;
                ptr = ptr->next;
                
                if(ptr){
                    p2->next = ptr;
                    p2 = p2->next;
                }
            }
            if(ptr)
                ptr = ptr->next;
        }
        if(p1)
            p1->next = NULL;
        if(p2)
            p2->next = NULL;
        return {h1,h2};
    }
};


//{ Driver Code Starts.

void printList(struct Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;

        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        vector<Node*> result = ob.alternatingSplitList(head);
        printList(result[0]);
        printList(result[1]);
    }

    return 0;
}

// } Driver Code Ends