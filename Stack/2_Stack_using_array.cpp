// In this program we implement stack using array data structure.
//This known as static represention of stack as we have fixed value of constant size in program
//we have define operation such as pop, push ,isempty in stack using array
//we can also implement stack using linked list;
//pros  = it is easy to implement and no pointer involved 
//cons = it is not dynamic so we have to fix it's size so it can't grow or shrink as our need;
#include<iostream>
using namespace std;
const int size=10;

class stack{
    int top;
    public:
    int arr[size];
    stack(){
        top=-1;
    }
    bool push(int x);
    int pop();
    int peek();
    bool isempty();
    
};
bool stack :: push(int x){

    if(top>size-1){
        cout << "Stack is overflow"<<endl;
        return false;
    }else{
        arr[++top]=x;
        cout << x <<" is pushed into stack"<<endl;
    }
};
int stack :: pop(){
    if(top<0){
        cout << "Stack is underflow"<<endl;
        return 0;
    }else{
        int temp = arr[top--];
        return temp;
        cout << temp <<" is remove from stack"<<endl;

    }
};
int stack :: peek(){
    if(top<0){
        cout << "stack is empty"<<endl;
        return 0;
    }else{
        int temp =arr[top];
        return temp;
    }
};
bool stack :: isempty(){
    return top<0;
};

int main(){
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    
    return 0;
}
