//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}


// } Driver Code Ends

/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node *ptr=head;
        Node *zerohead=NULL, *zeroptr=NULL;
        Node *onehead=NULL, *oneptr=NULL;
        Node *twohead=NULL, *twoptr=NULL;
        while(ptr){
            if(ptr->data == 0){
                if(!zerohead)
                    zerohead=zeroptr=ptr;
                else{
                    zeroptr->next = ptr;
                    zeroptr = zeroptr->next;
                }
            }
            else if(ptr->data == 1){
                if(!onehead)
                    onehead=oneptr=ptr;
                else{
                    oneptr->next = ptr;
                    oneptr = oneptr->next;
                }
            }
            else if(ptr->data == 2){
                if(!twohead)
                    twohead=twoptr=ptr;
                else{
                    twoptr->next = ptr;
                    twoptr = twoptr->next;
                }
            }
            ptr = ptr->next;
        }
        if(twoptr){
            twoptr->next = NULL;
            if(oneptr)
                oneptr->next = twohead;
            else if(zeroptr)
                zeroptr->next = twohead;
        }
        if(oneptr){
            if(!twohead)
                oneptr->next = NULL;
            if(zeroptr)
                zeroptr->next = onehead;
        }
        if(zeroptr){
            if(!onehead and !twohead)
                zeroptr->next = NULL;
        }
        if(zerohead)
            return zerohead;
        else if(onehead)
            return onehead;
        return twohead;
    }
};



//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int t, k;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;

            while (ss >> x) {
                tail->next = new Node(x);
                tail = tail->next;
            }

            // Link the last node to the head if k is 1 to make it circular
            if (k == 1) {
                tail->next = head;
            }
        }

        Solution ob;
        Node* newHead = ob.segregate(head);
        printList(newHead);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends