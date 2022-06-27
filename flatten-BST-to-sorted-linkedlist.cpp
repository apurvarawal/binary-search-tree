#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

node* insertinBST(node* root, int data){
    if(root==NULL){
        return new node(data);
    }
    if(data<=root->data){
        root->left=insertinBST(root->left,data);
    }else{
        root->right = insertinBST(root->right,data);
    }
    return root;
}

node* build(){
    int data;
    cin>>data;

    node* root = NULL;
    while(data!=-1){
        root = insertinBST(root,data);
        cin>>data;
    }
    return root;
}

void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

class Pair{
    public:
    node* head;
    node* tail;
};

Pair flatten(node* root){
    Pair l;
    if(root==NULL){
        l.head=l.tail=NULL;
        return l;
    }
    if(root->left==NULL && root->right==NULL){
        l.head=l.tail=root;
        return l;
    }
    if(root->left!=NULL && root->right==NULL){
        Pair leftLL = flatten(root->left);
        leftLL.tail->right=root;

        l.head=leftLL.head;
        l.tail=root;
        return l;
    }
    if(root->right!=NULL && root->left==NULL){
        Pair rightLL=flatten(root->right);
        root->right=rightLL.head;

        l.head=root;
        l.tail=rightLL.tail;
        return l;
    }

    Pair leftLL=flatten(root->left);
    Pair rightLL=flatten(root->right);

    leftLL.tail->right=root;
    root->right=rightLL.head;

    l.head=leftLL.head;
    l.tail=rightLL.tail;

    return l;
}
int main(){
    node* root =build();
    inorder(root);

    cout<<endl;
    Pair p=flatten(root);
    node* temp = p.head;

    while(temp!=NULL){
        cout<<temp->data<<" --> ";
        temp=temp->right;
    }

    cout<<endl;
    return 0;
}