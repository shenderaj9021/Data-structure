#include<iostream>
using namespace std;
int main(){
    int m,n=3;
    cout << "Enter no of rows in sparse matrix"<<endl;
    cin >>m;
    int sparse[m][n];
    cout<<"Enter Number of row in sparse matrix"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> sparse[i][j];
        }
    }
    cout << "Entered sparse matrix"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
        cout << sparse[i][j];
    }
    int temp;
    for(int i=1;i<m;i++){
            temp = sparse[i][0];
            sparse[i][0]=sparse[i][1];
            sparse[i][1]=temp;
    
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout << sparse[i][j]<<" "<<endl;
        }
        cout <<endl;
    }
    return 0;

}