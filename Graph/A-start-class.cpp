#include <bits//stdc++.h>
using namespace std;

typedef pair<int, int> Pair;
typedef pair<double, pair<int, int>> pPair;
class Astar
{
    int ROW;
    int COL;
    vector<vector<int>> grid;

public:
    Astar()
    {
        cout << "Enter Numbe of row" << endl;
        cin >> this->ROW;
        cout << "Enter number of col" << endl;
        cin >> this->COL;
        grid.resize(ROW, vector<int>(COL));
        cout << "Enter your grid" << endl;
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COL; j++)
            {
                cin >> grid[i][j];
            }
        }
        helper();
    }
    struct cell
    {
        int parent_i;
        int parent_j;
        double f, g, h;
    };
    bool isValid(int row, int col)
    {
        return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
    }
    bool isUnBlocked(vector<vector<int>> grid, int row, int col)
{
    if (grid[row][col] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isDestination(int row, int col, Pair dest)
{
    if (row == dest.first && col == dest.second)
    {
        return true;
    }
    else
    {
        return false;
    }
}

double calculateHValue(int row, int col, Pair dest)
{
    return ((double)sqrt((row - dest.first) * (row - dest.first) + (col - dest.second) * (col - dest.second)));
}
void tracePath(vector<vector<cell>>cellDetails, Pair dest)
{
    cout << "The Path is" << endl;
    int row = dest.first;
    int col = dest.second;
    stack<Pair> Path;
    while (!(cellDetails[row][col].parent_i == row && cellDetails[row][col].parent_j == col))
    {
        Path.push({row, col});
        int temp_row = cellDetails[row][col].parent_i;
        int temp_col = cellDetails[row][col].parent_j;
        row = temp_row;
        col = temp_col;
    }
    Path.push({row, col});
    while (!Path.empty())
    {
        pair<int, int> p = Path.top();
        Path.pop();
        cout << " ->" << p.first << " " << p.second << " ";
    }
    cout << endl;
    return;
}

void aStartSearch(vector<vector<int>> grid, Pair src, Pair dest)
{
    if (isValid(src.first, src.second) == false)
    {
        cout << "Source is not valid " << endl;
        return;
    }
    if (isValid(dest.first, dest.second) == false)
    {
        cout << "Destination is not valid" << endl;
        return;
    }
    if (isUnBlocked(grid, src.first, src.second) == false || isUnBlocked(grid, dest.first, dest.second) == false)
    {
        cout << "Source or destination is blocked" << endl;
        return;
    }
    if (isDestination(src.first, src.second, dest) == true)
    {
        cout << "We already at destination" << endl;
        return;
    }
    vector<vector<int>> closedList(this->ROW,vector<int> (this->COL,false));
  

    vector<vector<cell>>cellDetails(this->ROW,vector<cell>(this->COL));
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            cellDetails[i][j].f = FLT_MAX;
            cellDetails[i][j].h = FLT_MAX;
            cellDetails[i][j].g = FLT_MAX;
            cellDetails[i][j].parent_i = -1;
            cellDetails[i][j].parent_j = -1;
        }
    }
    int i = src.first;
    int j = src.second;
    cellDetails[i][j].f = 0.0;
    cellDetails[i][j].g = 0.0;
    cellDetails[i][j].h = 0.0;
    cellDetails[i][j].parent_i = i;
    cellDetails[i][j].parent_j = j;
    set<pPair> openList;
    openList.insert({0.0, {i, j}});

    bool foundDest = false;
    while (!openList.empty())
    {
        pPair p = *openList.begin();
        openList.erase(openList.begin());
        i = p.second.first;
        j = p.second.second;

        closedList[i][j] = true;
        double gNew, hNew, fNew;
        vector<int> rowv = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> colv = {-1, 0, 1, -1, 1, -1, 0, 1};
        for (int k = 0; k < 8; k++)
        {
            int tempi = i + rowv[k];
            int tempj = j + colv[k];
            if (isValid(tempi, tempj) == true)
            {
                if (isDestination(tempi, tempj, dest) == true)
                {
                    cellDetails[tempi][tempj].parent_i = i;
                    cellDetails[tempi][tempj].parent_j = j;
                    cout << "Destination Found " << endl;
                    tracePath(cellDetails, dest);
                    foundDest = true;
                    return;
                }
                else if (closedList[tempi][tempj] == false && isUnBlocked(grid, tempi, tempj) == true)
                {

                    gNew = cellDetails[i][j].g + 1.0;
                    hNew = calculateHValue(tempi, tempj, dest);
                    fNew = gNew + hNew;
                    if (cellDetails[tempi][tempj].f == FLT_MAX || cellDetails[tempi][tempj].f > fNew)
                    {

                        openList.insert({fNew, {tempi, tempj}});
                        cellDetails[tempi][tempj].f = fNew;
                        cellDetails[tempi][tempj].g = gNew;
                        cellDetails[tempi][tempj].h = hNew;
                        cellDetails[tempi][tempj].parent_i = i;
                        cellDetails[tempi][tempj].parent_j = j;
                    }
                }
            }
        }
    }
    if (foundDest == false)
    {
        cout << "Failed to find the Destination cell" << endl;
    }
    return;
}
void helper()
{
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
        aStartSearch(this->grid, src, dest);
        cout<<"want to continuew 1/0"<<endl;
        cin>>r;

    }
    
   

   return ;
}
};


int main()
{
   Astar* obj = new Astar();
   
    return (0);
}





