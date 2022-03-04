#include<iostream>
using namespace std;
int *add(int a[], int b[]){
    int m=a[0];
    int n=b[0];
    int size=max(m,n);
    int c[size];
    
    int i=1,j=1,k=1;
    while(i<2*m && j<2*n){
        if(a[i]>b[j]){
            c[k]=a[i];
            c[k+1]=a[i+1];
            k=k+2;
            i=i+2;
        }else if(b[j]>a[i]){
            c[k]=b[j];
            c[K+1]=b[j+1];
            k=k+2;
            j=j+2;
        }else{
            c[k]=a[i];
            c[k+1]=a[i+1]+b[j+1];
            k=k+2;
            i=i+2;
            j=j+2;
        }
        while(i<2*m){
            c[k]=a[i];
            c[k+1]=a[i+1];
            k=k+2;
            i=i+2;
        }
        while(j<2*n){
            c[k]=b[j];
            c[k+1]=b[j+1];
            k=k+2;
            j=j+2;
        }
        c[0]=k/2;
    }
    return c;
}
int main(){
    int a[]={3,2,3,1,2,0,9};
    int b[]={3,3,4,2,2,0,4};
    int c[10]=add(a,b);
}