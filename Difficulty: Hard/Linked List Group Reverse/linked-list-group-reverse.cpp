//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution {
  public:
    pair<Node *,Node *> reverse(Node *head, Node *tail){
        Node *cur=NULL, *ptr=head, *prev=NULL;
        while(ptr!=tail){
            cur=ptr;
            ptr=ptr->next;
            
            cur->next=prev;
            
            prev=cur;
        }
        if(ptr)
            ptr->next=prev;
        if(!tail)
            return {cur,head};
        return {tail,head};
    }
    Node *reverseKGroup(Node *head, int k) {
        // code here
        int count=1;
        Node *start=head, *prevstart=NULL, *end=head, *newhead=NULL;
        while(end){
            if(count==k){
                Node *nextstart=end->next;
                
                pair<Node *,Node *> temp=reverse(start,end);
                Node *newstart=temp.first;
                Node *newend=temp.second;
                
                if(!newhead)
                    newhead=newstart;
                else
                    prevstart->next=newstart;
                
                prevstart=newend;
                newend->next=start=end=nextstart;
                count=1;
            }
            else{
                ++count;
                end=end->next;
            }
        }
        if(count!=1 and count<=k){
            pair<Node *,Node *> temp=reverse(start,end);
            Node *newstart=temp.first;
            Node *newend=temp.second;
            prevstart->next=newstart;
        }
        return newhead;
    }
};


//{ Driver Code Starts.

/* Driver program to test above function*/
int main(void) {

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
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.reverseKGroup(head, k);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends