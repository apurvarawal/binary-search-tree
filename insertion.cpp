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

void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    
}

node* insertinBST(node* root, int data){
    if(root==NULL){
        return new node(data);
    }

    if(data<=root->data){
        root->left=insertinBST(root->left,data);
    }else{
        root->right=insertinBST(root->right,data);
    }
    return root;
}

node* build(){
    int data;
    cin>>data;

    node* root=NULL;

    while(data!=-1){
        root = insertinBST(root,data);
        cin>>data;
    }
    return root;
}

void bfs(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* f = q.front();
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
    return;
}

int main(){
    node* root=build();
    inorder(root);
    cout<<endl;
    bfs(root);
    return 0;
}