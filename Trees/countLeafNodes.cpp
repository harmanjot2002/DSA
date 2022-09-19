#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
    Node(int k){
        key=k;
        left=right=NULL;
    }
};

int countLeafNodes(Node* root){
    if(root==NULL)
        return 0;
    else if((root->left==NULL)&& (root->right==NULL)){
        return 1;
    }
    else{
        return countLeafNodes(root->left)+countLeafNodes(root->right);
    }
}


int main(){
    Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->right->left=new Node(40);
    root->right->right=new Node(50);
    root->right->right->right=new Node(6);
    cout<<countLeafNodes(root);
    return 0;
}