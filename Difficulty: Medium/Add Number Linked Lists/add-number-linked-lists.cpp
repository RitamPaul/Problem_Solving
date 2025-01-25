//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node *reverse(Node *head){
        Node *cur=NULL, *ptr=head, *prev=NULL;
        while(ptr){
            cur=ptr;
            ptr=ptr->next;
            
            cur->next=prev;
            
            prev=cur;
        }
        return cur;
    }
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        Node *rhead1=reverse(num1);
        Node *rhead2=reverse(num2);
        int sum=0, carry=0;
        Node *p1=rhead1, *p2=rhead2, *head=NULL, *ptr=head;
        while(p1 or p2){
            sum=0;
            if(p1){
                sum+=p1->data;
                p1=p1->next;
            }
            if(p2){
                sum+=p2->data;
                p2=p2->next;
            }
            sum+=carry;
            // starting of answer linked list
            if(!head)
                head=ptr=new Node(sum%10);
            // continue inserting into answer linked list
            else{
                ptr->next=new Node(sum%10);
                ptr=ptr->next;
            }
            carry=sum/10;
        }
        if(carry){
            ptr->next=new Node(carry);
            ptr=ptr->next;
        }
        Node *rhead=reverse(head);
        ptr=rhead;
        while(ptr and ptr->data==0){
            Node *temp=ptr;
            ptr=ptr->next;
            delete(temp);
        }
        return !ptr ? new Node(0) : ptr;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends