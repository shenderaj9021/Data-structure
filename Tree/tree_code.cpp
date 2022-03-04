#include<iostream>
#include<bits//stdc++.h>
using namespace std;
class Node{
    public:
    Node* lchild;
    Node* rchild;
    int data;

};
class Queue{
    private:
    int front;
    int rear;
    int size;
    Node **Q;
    public:
    Queue(){
        front = rear = -1;
        size =10;
        Q = new Node* [size];
    }
    Queue(int size){
        front = rear =-1;
        this->size = size;
        Q=new Node*[this->size];
    }
    void enqueue(Node* x);
    Node* dequeue();
    void Display();
    int isEmpty(){
        return front==rear;
    }
};
void Queue :: enqueue(Node* x) {
    if(rear==size-1){
        cout<<"Queue full"<<endl;
    }else{
        rear++;
        Q[rear] = x;
    }
}
Node* Queue:: dequeue(){
    Node* x ;
    if(front==rear){
        cout<<"Queue is empty"<<endl;
    }else{
        x = Q[front+1];
        front++;
    }
    return x;

}

class Tree{
    public:
    Node* root;
    Tree(){
        root=NULL;
    }
    void CreateTree();
    void Preorder(Node *p);
    void postorder(Node* p);
    void Inorder(Node* p);
    void levelorder(Node* p);
    int Height(Node *p);
};
void Tree ::Inorder(Node *p){
    cout<<p->data<<" ";
    if(p->lchild!=NULL){
        Inorder(p->lchild);
    }
      cout<<p->data<<" ";
    if(p->rchild!=NULL){
        Inorder(p->rchild);
    }
}
void Tree:: Preorder(Node* p){
      cout<<p->data<<" ";
    if(p->lchild!=NULL){
        Preorder(p->lchild);
    }
    if(p->rchild!=NULL){
        Preorder(p->rchild);
    }
}
void Tree::postorder(Node* p){
     if(p->lchild!=NULL){
        Preorder(p->lchild);
    }
    if(p->rchild!=NULL){
        Preorder(p->rchild);
    }
      cout<<p->data<<" ";
}
void Tree:: levelorder(Node* p){
    queue<Node*> q;
    q.push(p);
    while(!q.empty()){
        Node* temp = q.front();
        cout<<temp->data<<" ";
        if(temp->lchild!=NULL){
            q.push(temp->lchild);
        }
        if(temp->rchild!=NULL){
            q.push(temp->rchild);
        }
    }
}
void Tree:: CreateTree(){
    Node* p,t;
    int x;
    Queue q(100);
    cout<<"Enter a root value"<<endl;
    cin >> x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild =NULL;
    q.enqueue(root);
    while(!q.isEmpty()){
        p = q.dequeue();
        cout<<"Enter a left child of "<<p->data;
        cin >> x;
        if(x!=-1){
            Node* t = new Node;
            t->data = x;
            t->lchild = t->rchild =NULL;
            p->lchild=t;
            q.enqueue(t);
        } 
        cout<<"Enter a right child of "<<p->data;
        cin>>x;
        if(x!=-1){
            Node* t = new Node;
            t->data = x;
            t->lchild = t->rchild =NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
    
}
int Tree ::Height(Node* root){
    int x =0;
    int y =0;
    if(root=0){
        return 0;
    }
    x = Height(root->lchild);
    x = Height(root->rchild);
    if(x>y){
        return x+1;
    }else{
        return y+1;
    }
}
int main(){
    Tree  t;
    t.CreateTree();
    t.Preorder(t.root);
    t.postorder(t.root);
    t.Inorder(t.root);
    return 0;
}