//As our matrix contain more number of zeros so it is difficult to store it and it consum to  much memory
//so sparse maatrix is use to represent only non zero values of matrix which will save memory
//sparse matrix containe (row ,column,value)
//first row represent row colunmn value
#include<iostream>
using namespace std;

int main(){
    cout << "Enter number of row and column in matrix"<<endl;
    int m,n;
    cin >> m >>n;
    cout << "Enter matrix"<<endl;
    int mat[m][n];
    int size=0;                //size of parse matrix calculated by calculating number of non-zero elements in matrix
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
                cin >> mat[i][j];
                if(mat[i][j]!=0){
                    size++;
                }
        }
    }
    cout << "Your matrix is"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout << mat[i][j]<<" ";
        }
        cout << endl;
    }
    size++;
    int parse[size][3];
    parse[0][0]=m;
    parse[0][1]=m;
    parse[0][2]=size-1;
    int k=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]!=0){
                parse[k][0]=i;
                parse[k][1]=j;
                parse[k][2]=mat[i][j];
                k++;
            }
        }
    }
    cout << "Your parse matrix is"<<endl;
    for(int i=0;i<size;i++){
        for(int j=0;j<3;j++){
            cout << parse[i][j]<<" ";
        }
        cout <<endl;
    }
    return 0;
    
 

}
