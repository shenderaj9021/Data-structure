#include<iostream>
using namespace std;
class queue{
    public:
    int front,rear,size;

    int* arr;
};
queue* createqueue(int capacity){
    queue* new_queue = new queue;
    
    new_queue->front=new_queue->rear = 0;
    new_queue->size = 0;
    new_queue->arr = new int[new_queue->size];
}
int isfull(queue* q){


    return (q->front == (q->size)-1);

}
int isempty(queue* q){
    return (q-> front== q->rear);
}
void enqueue(queue* q,int x){
    if(isfull(q)){
        cout <<"queue is full"<<endl;
    }else{
        q->arr[q->front]=x;
        q->front=q->front+1; 
        
    }
   
}
int dequeue(queue* q){
    if(isempty(q)){
        return -1 ;
    }
    int item = q->arr[q->rear];
    q->rear++;
    return item;
    
}
int front(queue* q){
    if(isempty(q)){
        return -1;
    }
    return q->arr[q->front-1];
}
int rear(queue* q){
    if(isempty(q)){
        return -1;
    }
    return q->arr[q->rear];
}
int main(){
    queue* q = createqueue(100);
    enqueue(q,100);
    cout <<rear(q)<<endl;
    cout <<front(q)<<endl;
    enqueue(q,111);
    cout <<rear(q)<<endl;
    cout <<front(q)<<endl;
    enqueue(q,90);
    cout <<rear(q)<<endl;
    cout <<front(q)<<endl;
    cout << dequeue(q)<<endl;
    cout <<dequeue(q)<<endl;
    cout <<rear(q)<<endl;
    

}