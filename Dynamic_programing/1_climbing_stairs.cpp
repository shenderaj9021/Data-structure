/*
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

so we have two choices either 1 or 2 and we have find number of ways so it is recurion problem with base cas
 f(0)=1;   if no stair case
 f[(1)=1   if one stair case
 f(2)=2    if two star case (1+1) and (2)
 hence f(n) = f[n-1]+f[n-2];
 so this can be converted int 1-D dp with intialization array of size(n+1)
 such that arr[i] = arr[i-1]+arr[i-2];
 arr[0]=1;
 arr[1]=1; if(n>=1)
 arr[2] =2 if(n>=2)  Now we done with base use loop and fill memoization table till n+1 
 return arr[n];

*/
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>> n;
    int arr[n+1];
    arr[0]=0;
    if(n>=1){
        arr[1]=1;
    }
    if(n>=2){
        arr[2]=2;
    }
    for(int i=3;i<=n;i++){
        arr[i] = arr[i-1]+arr[i-2];
    }
    cout<< arr[n];
    return 0;
}

