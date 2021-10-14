#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
};
void printlist(node* n){
    while(n!=NULL){
        cout << n->data<<endl;
        n = n->next;

    }
    
}
void deletenode(node* head_ref,int node_data){
    
    node* temp = head_ref;
    node* prev = NULL;
    if(temp!= NULL && temp->data==node_data){
        head_ref = temp->next;
        delete temp;
        return;

    }else{
        while(temp!=NULL and temp->data != node_data){
            prev = temp;
            temp = temp-> next;
        }
        

        if(temp==NULL){
            return ;
        }
        prev -> next = temp->next;

        delete temp;
        
    }

}
int main(){
   node *head = NULL;
   node *second = NULL;
   node *third = NULL;
   node *fourth =NULL;

   head = new node;
   second = new node;
   third = new node;
   fourth = new node;
   head -> data = 1;
   head->next = second;

   second-> data = 2;
   second-> next = third;

   third-> data = 3;
   third->next = fourth;
    
    fourth -> data = 4;
    fourth->next = NULL;
    printlist(head);
    deletenode(head,2);
    printlist(head);
   

  
}