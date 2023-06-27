#include<bits//stdc++.h>
using namespace std;
class BNB
{
    int n;
    public:
    BNB(int n){
        this->n = n;
    }
    void solve(vector<vector<char>> &board,int cols,vector<bool> rows,vector<bool>ld,vector<bool> rd);
    bool isSafe(int row,int col,vector<bool> rows,vector<bool> ld,vector<bool> rd);
    void print(vector<vector<char>> &board);
};

bool BNB::isSafe(int row,int col,vector<bool> rows,vector<bool> ld,vector<bool> rd){
    if(rows[row]==true || ld[row+col]==true || rd[col-row+n-1]==true){
        return false;
    }
    return true;
}
void BNB::solve(vector<vector<char>>&board,int cols,vector<bool> rows,vector<bool> ld,vector<bool> rd){
    if(cols>=n){
        print(board);
        return ;
    }
    for(int i=0;i<n;i++){
        if(isSafe(i,cols,rows,ld,rd)){
            rows[i] = true;
            ld[i+cols]= true;
            rd[cols-i+n-1] = true;
            board[i][cols]='Q';
            solve(board,cols+1,rows,ld,rd);
            rows[i] = false;
            ld[i+cols] = false;
            rd[cols-i+n-1] = false;
            board[i][cols] = '-';
        }
    }
}
void BNB::print(vector<vector<char>> &board){
    cout<<"Solution : "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int main(){
    cout<<"Enter N : "<<endl;
    int n;
    cin>>n;
    if(n==2 || n==3){
        cout<<"No solution "<<endl;
        return 0;
    }
    BNB b(n);
    vector<vector<char>>board (n,vector<char>(n,'-'));
    vector<bool> rows(n,false);
    vector<bool> ld(2*n-1,false);
    vector<bool> rd(2*n-1,false);
    b.solve(board,0,rows,ld,rd);
    return 0;
}