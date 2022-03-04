//In this program we are going to print stack without deleting any element from stack
//so we use recursion here 
//at each recursion we store top of stack in variable temp and print it
//then we perform pop opertion on stack which remove current element and shift top to next
//now we againg called same fucntion for same stack but now one element is less as we pop one element
//Hence stack will peform same step upto top points -1;
//we again push temp to stack after recursion call which will again store temp in stack which remove due to stack;

#include<iostream>
#include <bits//stdc++.h>
using namespace std;
void printstack(stack <int> s);
int main(){
    stack <int>  s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    printstack(s);
}
void printstack(stack <int> s){
    if(s.empty()){
        return ;
    }
    int temp=s.top();
    cout <<temp <<endl;
    s.pop();
    printstack(s);
    s.push(temp);


}