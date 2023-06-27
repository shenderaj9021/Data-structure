#include<bits//stdc++.h>
using namespace std;
typedef pair<int,int>Pair;
typedef pair<double,pair<int,int>>pPair;
class Astar{
    int Row;
    int Col;
    vector<vector<int>> grid;
    public:
    Astar(){
        cout<<"Enter number of row"<<endl;
        cin>>this->Row;
        cout<<"Enter number of col"<<endl;
        cin>>this->Col;
        grid.resize(Row,vector<int>(Col));
        cout<<"Enter your grid "<<endl;
        for(int i=0;i<Row;i++){
            for(int j=0;j<Col;j++){
                cin>>grid[i][j];
            }
        }
        helper();
    }
    struct cell{
        int parent_i;
        int parent_j;
        double f,g,h;
    };
    bool isValid(int row,int col);
    bool isUnBlocked(vector<vector<int>> grid,int row,int col);
    bool isDestination(int row,int col,Pair dest);
    double calculateHValue(int row,int col,Pair dest);
    void tarcePath(vector<vector<cell>> cellDetails,Pair dest);
    void AstarSearch(vector<vector<int>> grid,Pair src,Pair dest);
    void helper();
};
bool Astar::isValid(int row,int col){
    return (row>=0 && row<Row && col>=0 && col<Col);
}
bool Astar::isUnBlocked(vector<vector<int>>grid,int row,int col){
    return grid[row][col];
}
bool Astar::isDestination(int row,int col,Pair dest){
    return (dest.first==row && dest.second==col);
}
double Astar::calculateHValue(int row,int col,Pair dest){
    return ((double)sqrt((row-dest.first)*(row-dest.first) + (col-dest.second)*(col-dest.second)));
}
void Astar :: tarcePath(vector<vector<cell>> cellDetails,Pair dest){
    cout<<"The Path is "<<endl;
    int row = dest.first;
    int col = dest.second;
    stack<Pair> Path;
    while(!(cellDetails[row][col].parent_i==row && cellDetails[row][col].parent_j==col)){
        Path.push({row,col});
        int temp_row = cellDetails[row][col].parent_i;
        int temp_col = cellDetails[row][col].parent_j;
        row = temp_row;
        col = temp_col;
    }
    Path.push({row,col});
    while(!Path.empty()){
        pair<int,int> p = Path.top();
        Path.pop();
        cout<<"-> "<<p.first<<" "<<p.second<<" ";
    }
    cout<<endl;
    return ;
}
void Astar :: AstarSearch(vector<vector<int>> grid,Pair src,Pair dest){
    if(!isValid(src.first,src.second)){
        cout<<"Source is not valid "<<endl;
        return ;
    }
    if(!isValid(dest.first,dest.second)){
        cout<<"Destination is not valid "<<endl;
        return ;
    }
    if(isUnBlocked(grid,src.first,src.second)==false || isUnBlocked(grid,dest.first,dest.second)==false){
        cout<<"Source or destination is blocked "<<endl;
        return ;
    }
    if(isDestination(src.first,src.second,dest)==true){
        cout<<"we already at destination "<<endl;
        return ;
    }
    vector<vector<int>>closedList(this->Row,vector<int>(this->Col,false));
    vector<vector<cell>>cellDetails(this->Row,vector<cell>(this->Col));
    for(int i=0;i<Row;i++){
        for(int j=0;j<Col;j++){
            cellDetails[i][j].f = FLT_MAX;
            cellDetails[i][j].h = FLT_MAX;
            cellDetails[i][j].g = FLT_MAX;
            cellDetails[i][j].parent_i= -1;
            cellDetails[i][j].parent_j=-1;
        }
    }
    int i = src.first;
    int j = src.second;
    cellDetails[i][j].f =0.0;
    cellDetails[i][j].g=0.0;
    cellDetails[i][j].h =0.0;
    cellDetails[i][j].parent_i = i;
    cellDetails[i][j].parent_j = j;
    set<pPair> openList;
    openList.insert({0.0,{i,j}});
    bool foundDest = false;
    while(!openList.empty()){
        cout<<"open list "<<endl;
        pPair p = *openList.begin();
        openList.erase(openList.begin());
        i =p.second.first;
        j = p.second.second;
        closedList[i][j] = true;
        double gNew,hNew,fNew;
        vector<int> rowv ={-1,-1,-1,0,0,1,1,1};
        vector<int>colv ={-1,0,1,-1,1,-1,0,1};
        for(int k=0;k<8;k++){
            int tempi = i+rowv[k];
            int tempj = j+colv[k];
              cout<<tempi<<" "<<tempj<<endl;
            if(isValid(tempi,tempj)==true){
                cout<<tempi<<" "<<tempj<<endl;
                if(isDestination(tempi,tempj,dest)==true){
                    cellDetails[tempi][tempj].parent_i = i;
                    cellDetails[tempi][tempj].parent_j = j;
                    cout<<"Destination FOund"<<endl;
                    tarcePath(cellDetails,dest);
                    foundDest = true;
                    return ;
                }else if(closedList[tempi][tempj]==false && isUnBlocked(grid,tempi,tempj)==true){
                    gNew = cellDetails[i][j].g +1.0;
                    hNew = calculateHValue(tempi,tempj,dest);
                    fNew = gNew+hNew;
                    if(cellDetails[tempi][tempj].f==FLT_MAX || cellDetails[tempi][tempj].f>fNew){
                        openList.insert({fNew,{tempi,tempj}});
                        cellDetails[tempi][tempj].f = fNew;
                        cellDetails[tempi][tempj].g = gNew;
                        cellDetails[tempi][tempj].h = hNew;
                        cellDetails[tempi][tempj].parent_i = i;
                        cellDetails[tempi][tempj].parent_j =j;
                    }
                }
            }
        }
    }
    if(foundDest==false){
        cout<<"Faild to find the Destination cell "<<endl;
    }
    return ;
}

void Astar:: helper(){
    bool r = true;
    while(r){
        Pair src = make_pair(8, 0);
        Pair dest = make_pair(0, 0);
        int x,y;
        cout<<"Enter source row "<<endl;
        cin>>x;
        cout<<"Enter source col "<<endl;
        cin>>y;
        src = {x,y};
        cout<<"Enter Destination row"<<endl;
        cin>>x;
        cout<<"Enter destination col "<<endl;
        cin>>y;
        dest = {x,y};
        AstarSearch(this->grid, src, dest);
        cout<<"want to continuew 1/0"<<endl;
        cin>>r;

    }
    
   

   return ;
}
int main(){
   Astar* obj = new Astar();
   
    return (0);
}