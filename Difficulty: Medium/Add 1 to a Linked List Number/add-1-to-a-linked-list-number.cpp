//{ Driver Code Starts
// Initial template for C++

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

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

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
    Node *reverse(Node *head){
        Node *cur=head, *prev=NULL, *next=NULL;
        while(cur){
            next = cur->next;
            
            cur->next = prev;
            prev = cur;
            
            cur = next;
        }
        return prev;
    }
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        Node *rhead = reverse(head);
        
        Node *cur=rhead, *prev=NULL;
        int carry{1}, sum{0};
        while(cur){
            sum = cur->data + carry;
            cur->data = sum % 10;
            carry = sum / 10;
            
            prev = cur;
            cur = cur->next;
        }
        if(carry > 0){
            prev->next = new Node(carry);
        }
        
        return reverse(rhead);
    }
};


//{ Driver Code Starts.

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

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends