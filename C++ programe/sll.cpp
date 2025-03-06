#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
     int data;
     Node *nxt;
     Node(int val){
        data=val;
        nxt=nullptr;
     } 
};
class Operation{
 public:
  Node* readEle(Node* head,int n){
    int ele;
    Node *temp;
    for(int i=0;i<n;i++){
        cout<<"Enter the ele-"<<i+1<<"=";
        cin>>ele;
        Node *New=new Node(ele);
        if(head==nullptr){
            head=temp=New;
        }
        else{
            temp->nxt=New;
            temp=New;
        }
    }
    return head;
  }
  void printEle(Node* head){
    cout<<"Data:\n";
    Node *temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<"\t";
        temp=temp->nxt;
    }
    cout<<endl;
  }
  Node* insertEle(Node* head,int pos,int n){
        Node *temp=head;
        int ele;
        if((pos-1)>=n || pos<0){
            cout<<"Inavid Position\n";
        }
        else{
         for(int i=0;i<n;i++){
            if(pos-1==0){
                cout<<"Enter the ele=";
                cin>>ele;
                Node *New=new Node(ele);
                New->nxt=head;
                head=New;
                break;
              }
              else if(pos-1==i){
                cout<<"Enter the ele=";
                cin>>ele;
                Node *New=new Node(ele);
                New->nxt=temp->nxt;
                temp->nxt=New;
                temp=New;
                break;
              }
              temp=temp->nxt;
            }
        }
    return head;
  }
};
int main(){
    int n,pos;
    cout<<"Enter the no.of ele=";
    cin>>n;
    Node* head=nullptr;
    Operation obj;
    head=obj.readEle(head,n);
    obj.printEle(head);
    
    cout<<"Enter the insertEle pos=";
    cin>>pos;
    head=obj.insertEle(head,pos,n);
    obj.printEle(head);
}
