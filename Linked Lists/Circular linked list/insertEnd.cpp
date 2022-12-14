#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};

Node* insertEnd(Node* head,int x){
    Node* temp=new Node(x);
    if(head==NULL){
        temp->next=temp;
        return temp;
    }
    temp->next=head->next;
    head->next=temp;
    int t=temp->data;
    temp->data=head->data;
    head->data=t;
    return temp;
}

void printList(Node* head){
    if(head==NULL)
        return;
    cout<<head->data<<" ";
    for(Node* p=head->next;p!=head;p=p->next){
        cout<<p->data<<" ";
    }
}

int main(){
    Node* head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    head->next->next->next=new Node(40);
    head->next->next->next->next=head;
    cout<<"Before insertion"<<endl;
    printList(head);
    cout<<endl<<"After insertion"<<endl;
    head=insertEnd(head,3);
    printList(head);
    return 0;
}