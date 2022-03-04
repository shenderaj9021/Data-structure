#include<iostream>
using namespace std;
int main(){
    int m,n=3;
    cout << "Enter no of rows in saprse matrix"<<endl;
    cin >> m;
    int sparse[m][3];
    cout << "Enter sparse matrix"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<3;j++){
            cin >> sparse[i][j];
        }
    }
    cout << "Entered sparse matrix is"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout << sparse[i][j] <<" ";
        }
        cout <<endl;
    }
    int trans[m][n];
    trans[0][0]=sparse[0][1];
    trans[0][1]=sparse[0][0];
    trans[0][2]=sparse[0][2];
    int k=1;
    int t = sparse[0][2];
    for(int i=0;i<trans[0][1];i++){
        for(int j=1;j<t;j++){
            if(i==sparse[j][1]){
                trans[k][0]=i;
                trans[k][1]=sparse[j][0];
                trans[k][2]=sparse[j][2];
                k++;
            }

        }
    }
    cout << "Transposd matrix is"<<endl;
    for(int i=0;i<trans[0][0]+1;i++){
        for(int j=0;j<trans[0][1];j++){
            cout << trans[i][j]<<" ";
        }
        cout <<endl;
    }
}
