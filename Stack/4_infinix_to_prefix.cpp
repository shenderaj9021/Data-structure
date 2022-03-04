#include<iostream>
using namespace std;
class stacknode{
    public:
    stacknode* next;
    int data;
};
stacknode* newnode(int x){
    stacknode* new_node = new stacknode;
    new_node->data = x;
    new_node->next = NULL;
    return new_node;
}
void push(stacknode** head, int x){
    stacknode* new_node = newnode(x);
    new_node->next = (*head);
    (*head)= new_node;
    cout <<x <<" is pushed"<<endl;
}
int pop(stacknode** head){
    stacknode* temp = (*head);
    int popped;
    popped=temp->data;
    (*head)=(*head)->next;
    free(temp);
    cout <<popped<<" is popped"<<endl;
    return popped;
}
bool isempty(stacknode* head){
    return !head;
}
int peek(stacknode* head){
    if(isempty(head)){
        return -1;
    }else{
        return head->data;
    }
}
int precedence(char x){
    if(x=='+' || x=='-'){
        return 1;
    }else if(x=='*' || x=='/'){
        return 2;
    }else{
        return 0;
    }
}
int isoperand(char x){
    if(x=='+' || x=='*' || x=='/' || x=='-'){
        return 0;
    }else{
        return 1;
    }
}
string intopostfix(string infix){
    
    int l = infix.length();
    string postfix[l+1];
    int i=0,j=0;
    while(infix[i]!='\0'){
        if(isoperand(infix[i])){
            postfix[j++] = infix[i];
        }else{
            if(precedence(infix[i])>precedence[postfix])
        }
    }

}

int main(){
    stacknode* head;
    head==NULL;
    push(&head,45);
    push(&head,12);
    push(&head,90);
    cout << peek(head)<<endl;
    pop(&head);
    cout <<peek(head)<<endl;
    string infix = "a+b*c";
    

}


