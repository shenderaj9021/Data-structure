#include<iostream>
using namespace std;
int main(){
    int m,n;
    cout << "Enter number of row and column in sparse matrix"<<endl;
    cin >> m >>n;
    cout << "Enter sparse matrix "<<endl;
    int sparse[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> sparse[i][j];
        }
    }
    int row = sparse[0][0];
    int col = sparse[0][1];
    int mat[row][col];
    for(int i=0;i<sparse[0][0];i++){
        for(int j=0;j<col;j++){
            mat[i][j]=0;
        }
    }
    cout <<"This is Entered sparse matrix"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout << sparse[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=1;i<m;i++){
        int p = sparse[i][0];
        int q= sparse[i][1];
        cout <<p <<" ";
        cout <<q<<" ";
        mat[p][q]=sparse[i][2];
    }
    cout << "Normal matrix is "<<endl;
    for(int i=0;i<sparse[0][0];i++){
        for(int j=0;j<sparse[0][1];j++){
            cout << mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
