#include<iostream>
#include<bits//stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    public:
    Node(){
        data = 0;
        left = NULL;
        right=NULL;
    }
};
struct Node* create(){
    struct Node* new_node = new Node();
    cout<<"Enter a data you want to insert(enter -1 for no node)"<<endl;
    int d;
    cin >> d;
    if(d==-1){
        return 0;
    }
    new_node->data = d;
    cout<<" Does node has left child? (y/n)";
    char ans;
    cin >>ans;
    if(ans=='y'){
        new_node->left = create();
    }else{
        new_node->left =NULL;
    }
    cout<<" Does node has right child? (y/n)";
    cin >>ans;
    if(ans=='y'){
        new_node->right = create();
    }else{
        new_node->right = NULL;
    }

}
void preorder(struct Node* root){
    cout<<root->data<<"  ";
    if(root->left!=NULL){
        preorder(root->left);
    }
    if(root->right!=NULL){
        preorder(root->right);
    }
    
}
int main(){
    struct Node* root;
    root= create();
    preorder(root);


}