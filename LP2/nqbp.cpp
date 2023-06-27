#include <bits//stdc++.h>
using namespace std;
class NQueens
{
private:
    int n;

public:
    NQueens(int n)
    {
        this->n = n;
    }
    bool isSafe(vector<string> board,int row,int col);
    void solve(vector<string>&board,vector<vector<string>>&ans,int col);
};
bool NQueens :: isSafe(vector<string> board,int row,int col){
    for(int i=0;i<n;i++){
        if(board[row][i]=='Q'){
            return false;
        }
    }
    for(int i=0;i<n;i++){
        if(board[i][col]=='Q'){
            return false;
        }
    }
    int r = row;
    for(int c =col;c<n,r>=0;c++,r--){
        if(board[r][c]=='Q'){
            return false;
        }
    }
     r = row;
    for(int c=col;c>=0,r>=0;c--,r--){
        if(board[r][c]=='Q'){
            return false;
        }
    }
     r=row;
    for(int c=col;c<n,r<n;c++,r++){
        if(board[r][c]=='Q'){
            return false;
        }
    }
    r = row;
    for(int c = col;c>=0,r<n;c--,r++){
        if(board[r][c]=='Q'){
            return false;
        }
    }
    return true;
}
void NQueens ::solve(vector<string>&board,vector<vector<string>>& ans,int col){
    if(col==n){
        ans.push_back(board);
        return ;
    }
    for(int row=0;row<n;row++){
        if(isSafe(board,row,col)){
            board[row][col] ='Q';
            solve(board,ans,col+1);
            board[row][col]='.';

        }
    }
}
int main(){
    int n;
    cout << "Enter N:" << endl;
    cin >> n;
    NQueens nq(n);
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }
    nq.solve(board, ans, 0);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j];
            cout << endl;
        }
        cout << endl;
    }
}