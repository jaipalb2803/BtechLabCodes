//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
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

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
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
struct Node*reverse(struct Node*first)
{
    struct Node *cur=NULL,*pre,*nxt;
    pre=nxt=first;
    while(nxt)
    {
        nxt=nxt->next;
        pre->next=cur;
        
        cur=pre;
        pre=nxt;
    }
    return cur;
}
class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
         Node*a,*b,*temp,*head=NULL;
         a=reverse(first);
         b=reverse(second);
         int r=0;
         while(a||b)
         {
             int val,k;
             if(a&&b)
                val=(a->data)+(b->data)+r;
             else if(a)
                val=(a->data)+r;
             else if(b)
                val=(b->data)+r;
             k=val%10;
             if(head==NULL)
             {
                head=new Node(k);
                temp=head;
             }
             else
             {
                 temp->next=new Node(k);
                 temp=temp->next;
             }
             if(a)
                a=a->next;
             if(b)
                b=b->next;
             r=val/10;
             
         }
         return reverse(head);
    
    }

};


//{ Driver Code Starts.

int main()
{
    int t;
    //cin>>t;
    //while(t--)
    //{
        int n, m;
        cout<<"enter=";
        cin>>n;
        Node* first = buildList(n);
        cout<<"enter=";
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    //}
    return 0;
}

// } Driver Code Ends