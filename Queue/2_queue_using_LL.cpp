#include<iostream>
using namespace std;
queue* front=NULL;
queue *rear = NULL;
class queue{
    public:
    int data;
    queue* next;

};
void enqueue(int x){
    queue* temp = new queue;
    temp->data = x;
    if(temp==NULL){
        cout <<"queue is full"<<endl;
    }else{
        if(front==NULL){
            front=rear = temp;
        }else{
            rear->next = temp;
            rear=temp;
        }
    }
}
void dequeue(){
    queue* t;

    if(front==NULL){
        cout << "queue is empty"<<endl;

    }else{
        int x = front->data;
        t = front;
        front=front->next;
        free(t);
    }
}
void display(){
    queue* q;
    while(q){
        cout <<q->data <<endl;
        q=q->next;
    }
}
int main(){
    enqueue(45);
    enqueue(47);
    enqueue(90);
    display();
}