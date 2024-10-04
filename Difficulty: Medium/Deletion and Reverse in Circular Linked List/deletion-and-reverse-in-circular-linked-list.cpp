//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Structure for the linked list node
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Function to print nodes in a given circular linked list
void printList(struct Node *head) {
    if (head != NULL) {
        struct Node *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    } else {
        cout << "empty" << endl;
    }
    cout << endl;
}


// } Driver Code Ends
class Solution {
  public:
    // Function to reverse a circular linked list
    Node* reverse(Node* head) {
        // code here
        Node *ptr=head, *cur=NULL, *prev=NULL;
        do{
            cur = ptr;
            ptr = ptr->next;
            
            cur->next = prev;
            prev = cur;
        }while(ptr != head);
        
        head->next = prev;
        
        return prev;
    }

    // Function to delete a node from the circular linked list
    Node* deleteNode(Node* head, int key) {
        // code here
        Node *ptr=head, *prev=NULL;
        bool mila=false;
        
        // finding the node to delete
        do{
            if(ptr->data == key){
                mila = true;
                break;
            }
            prev = ptr;
            ptr = ptr->next;
        }while(ptr!=head);
        
        // deleting the node
        if(mila and ptr == head){
            Node *tail=head;
            while(tail->next != head)
                tail = tail->next;
            tail->next = head->next;
            head = head->next;
        }
        else if(mila)
            prev->next = ptr->next;
        
        // don't have headache to reverse, just return
        return head;
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

        // Reading input into a vector
        while (ss >> number) {
            arr.push_back(number);
        }

        int key;
        cin >> key;
        cin.ignore();

        // Creating the circular linked list
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        tail->next = head; // Make the list circular

        Solution ob;

        // Delete the node with the given key
        head = ob.deleteNode(head, key);

        // Reverse the circular linked list
        head = ob.reverse(head);

        // Print the modified list
        printList(head);
    }
    return 0;
}

// } Driver Code Ends