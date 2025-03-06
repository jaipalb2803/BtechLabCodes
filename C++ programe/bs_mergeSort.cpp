     //{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
            
        
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        
        Node* slow = head;
        Node* fast = head->next;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* head2= slow->next;
        slow->next = NULL;
        Node* sorted1 = mergeSort(head);
        printList(sorted1);
        Node* sorted2 = mergeSort(head2);

        // Merge the two sorted halves of the linked list
        return merge(sorted1, sorted2);
    }
    
  private:
    Node* merge(Node* l1, Node* l2) 
    {
        Node* dummy = new Node(0);
        Node* tail = dummy;

        while (l1 != NULL && l2 != NULL)
        {
            if (l1->data< l2->data)
            {
                tail->next = l1;
                l1 = l1->next;
            }
            else 
            {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        if (l1 != NULL)
        {
            tail->next = l1;
        }
        else
        {
            tail->next = l2;
        }

        return dummy->next;
    }
  void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends