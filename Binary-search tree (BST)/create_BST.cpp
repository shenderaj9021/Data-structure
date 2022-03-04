#include<iostream>
using namespace std;
class Node{
    public:
    Node* lchild;
    Node* rchild;
    int data;
    
    Node(int data){
        lchild = NULL;
        rchild = NULL;
        this->data = data;
    }
}*root =NULL;
void Insert(int key){
    cout<<"Insert"<<endl;
    Node* t = root;
    Node *r,*p;
    if(root==NULL){
        p=new Node(key);
        root =p;
    }
    while(t!=NULL){
        r =t;
        if(key<t->data){
            t = t->lchild;
        }else if(key>t->data){
            t = t->rchild;
        }else{
            return;
        }
    }
    p =new Node(key);
    if(key<r->data){
        r->lchild =p;
    }else{
        r->rchild =p;
    }
    return ;
}
void Inorder(Node* p){
    if(p){
        Inorder(p->lchild);
        cout<<p->data<<" ";
        Inorder(p->rchild);
    }
}
int main(){
    Insert(10);
    Insert(5);
    Insert(20);
    Insert(8);
    Insert(30);
    Inorder(root);
    return 0;
}