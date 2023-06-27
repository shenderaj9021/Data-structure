
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
    cout<<"sol "<<cols<<endl;
    for(int i=0;i<n;i++){
        cout<<"i "<<i<<endl;
        cout<<isSafe(i,cols,rows,ld,rd)<<endl;
        if(isSafe(i,cols,rows,ld,rd)){
            cout<<"step2 "<<cols<<endl;
            rows[i] = true;
            ld[i+cols]=true;
            ld[cols-i+n-1]=true;
            board[i][cols]='Q';
            solve(board,cols+1,rows,ld,rd);
            rows[i]=false;
            ld[i+cols] = false;
            ld[cols-i+n-1]=false;
            board[i][cols] ='-';
        }
    }
    
}