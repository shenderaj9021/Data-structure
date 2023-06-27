#include<bits//stdc++.h>
using namespace std;
struct Job {
    int id;
    int dead;
    int profit;
}Job;
bool  compare(Job a,Job b){
    
    return (a.profit>b.profit);
}
int min(int num1,int num2){
    return (num1>num2)? num2:num1;
}
void printJobScheduling(Job arr[],int n){
    sort(arr,arr+n,compare);
    int maxline=0,j=0;
    int result[n];
    bool slot[n];
    for(int i=0;i<n;i++){
        slot[i] = false;
    }
    for(int i=0;i<n;i++){
        for(int j=min(n,arr[i].dead)-1;j>=0;j--){
            if(slot[j]==false){
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(slot[i]){
            cout<<arr[result[i]].id<<endl;
        }
    }
}
int main(){
      Job arr[] = { { 'a', 2, 100 },
                  { 'b', 1, 19 },
                  { 'c', 2, 27 },
                  { 'd', 1, 25 },
                  { 'e', 3, 15 } };

                int n = sizeof(arr) / sizeof(arr[0]);
                cout<<"job scheduling "<<endl;
                printJobScheduling(arr,n);
                return 0;
}