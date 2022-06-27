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
        root->left = insertinBST(root->left,data);
    }else{
        root->right= insertinBST(root->right,data);
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

void bfs(node* root){
    queue <node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* f=q.front();
        if(f==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<f->data<<" ";
            q.pop();
            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
}

node* deleteinBST(node* root, int data){
    if(root==NULL){
        return NULL;
    }
    else if(data<root->data){
        root->left=deleteinBST(root->left,data);
        return root;
    }else if(data==root->data){
        //3 types
        //1. 0 roots
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        //2. 1 root
        if(root->left!=NULL && root->right==NULL){
            node* temp=root->left;
            delete root;
            return temp;
        }else if(root->right!=NULL && root->left==NULL){
            node* temp=root->right;
            delete root;
            return temp;
        }

        //3. both roots are present
        node* replace=root->right;
        while(replace->left!=NULL){
            replace=replace->left;  //find the min data in the left of right subtree. or we could have the max in the right of left subtree.
        }
        root->data=replace->data;

        //now delete the root from the subtree which has been used for replacement.

        root->right=deleteinBST(root->right,replace->data);
        return root;

    }else{
        root->right=deleteinBST(root->right,data);
        return root;
    }
}
int main(){
    node* root=build();
    inorder(root);
    cout<<endl;
    bfs(root);
    int deletedata;
    cin>>deletedata;
    deleteinBST(root,deletedata);
    bfs(root);
    return 0;
}