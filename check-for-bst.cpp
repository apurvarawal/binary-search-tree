#include<iostream>
#include<queue>
#include<algorithm>
#include<climits>
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
        return NULL;
    }

    if(data<=root->data){
        root->left=insertinBST(root->left,data);
    }
    else{
        root->right=insertinBST(root->right,data);
    }
    return root;
}

node* build(){
    int data;
    cin>>data;

    node* root=NULL;
    while(data!=-1){
        root=insertinBST(root,data);
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

bool checkBST(node* root, int minV = INT_MIN, int maxV=INT_MAX){
    if(root==NULL){
        return true;
    }
    if(root->data>maxV && root->data<minV && checkBST(root->left,minV,root->data) && checkBST(root->right, root->data,maxV)){
        return true;
    }
    return false;
}
int main(){
    node* root = build();
    inorder(root);
    cout<<endl;
    if(checkBST(root)){
        cout<<"BST"<<endl;
    }else{
        cout<<"not a BST";
    }
    return 0;
}