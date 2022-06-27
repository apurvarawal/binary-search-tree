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
        root->right=insertinBST(root->right,data);
    }
    return root;
}

node* inorder(node* root){
    if(root==NULL){
        return NULL;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    return root;
}

void bfs(node* root){
    queue <node*> q;
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
}

node* build(){
    int data;
    cin>>data;

    node* root =NULL;

    while(data!=-1){
        root=insertinBST(root,data);
        cin>>data;
    }
    return root;
}

bool search(node* root, int data){
    if(root==NULL){
        return false;
    }
    if(root->data==data){
        return true;
    }
    if(data<=root->data){
        return search(root->left,data);
    }else{
        return search(root->right,data);
    }
}
int main(){
    node* root=build();
    inorder(root);
    cout<<endl;
    bfs(root);

    int s;
    cin>>s;

    if(search(root,s)){
        cout<<"Data is present"<<endl;
    }else{
        cout<<"Data is absent"<<endl;
    }
    return 0;
}