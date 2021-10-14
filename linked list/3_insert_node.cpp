#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
};
void insert_node(node* prev_node,int data){
    if(prev_node==NULL){
        cout << "The given previous node cannot ne null"<<endl;
    }
    node* new_node = new node;
    new_node ->data = data;
    new_node -> next = prev_node->next;
    prev_node -> next = new_node;
}
void printlist(node* n){
    while (n!= NULL){
        cout << n->data << endl;
        n = n->next;
    }

    
}
int main(){
    node *head = NULL;
    node *second = NULL;
    node *third = NULL;
 
    head = new node;
    second = new node;
    third = new node;

    head -> data = 1;
    head->next = second;

    second-> data = 2;
    second-> next = third;

    third-> data = 3;
    third-> next = NULL;
    printlist(head);
    insert_node(second,6);
    printlist(head);
}