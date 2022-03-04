#include<iostream>
using namespace std;
class stacknode{
    public:
    int data;
    stacknode* next;
};
stacknode* newnode(int x){
    stacknode* newnode = new stacknode();
    newnode->data = x;
    newnode->next=NULL;
    return newnode;
};
int isempty(stacknode* point ){
    return !point;
};
void push(stacknode** head,int x){
    stacknode* new_node = newnode(x);
    new_node -> next = (*head);
    (*head) = new_node;
    cout << x << "push to stack"<<endl;

}
int pop(stacknode** head){
    if(isempty(*head)){
        return -1;
    }
    stacknode* temp = *head;
    (*head)=(*head)->next;
    int popped = temp->data;
    free(temp);
    cout <<popped << " is popped "<<endl;
    return popped;
}
int peek(stacknode* head){
    if(isempty(head)){
        return -1;
    }
    return head->data;
}
int main(){
    stacknode* head;
    head=NULL;
    push(&head,30);
    push(&head,989);
    push(&head,89);
    pop(&head);
    cout << peek(head)<<endl;
    
    return 0;

    

    
}
