#include<bits//stdc++.h>
using namespace std;
class Graph {
    int **gr;
    int n;
    int *visited1;
    int *visited2;
    queue<int> q;
    public:
    Graph(int n){
        this->n = n;
        gr = new int*[n];
        visited1= new int[n];
        visited2 = new int[n];
        for(int i=0;i<n;i++){
            gr[i] = new int[n];
            visited1[i] = 0;
            visited2[i] =0;
            for(int j=0;j<n;j++){
                gr[i][j] =0;
            }
        }
    }

    void create(int edge);
    void display();
    void dfsr(int);
    void dfs(int);
    void bfsr(int);
    void bfs(int);
};
void Graph :: create(int edge){
    int s,d;
    for(int i=0;i<edge;i++){
        cout<<"Enter source "<<i+1<<endl;
        cin>>s;
        cout<<"Enter Destination "<<i+1<<endl;
        cin>>d;
        gr[s][d] = 1;
        gr[d][s]=1;
    }
    
}
void Graph :: display(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<gr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void Graph::dfs(int v1){
    vector<bool> visited(n, false);
    stack<int> s;
    s.push(v1);
    while (!s.empty())
    {
        int a = s.top();
        s.pop();
        if (!visited[a])
        {
            cout << a << " ";
            visited[a] = true;
        }
        for(int i=0;i<n;i++)
        {
            if (gr[a][i] == 1 && !visited[i])
            {
                s.push(i);
            }
        }
    }
}
void Graph::dfsr(int v1){
    cout<<v1<<" ";
    visited1[v1]=1;
    for(int i=0;i<n;i++){
        if(gr[v1][i]==1 && visited1[i]==0){
            dfsr(i);
        }
    }

}

void Graph:: bfs(int v1){
    queue<int> q;
    vector<bool> visited(n,false);
    q.push(v1);
    visited[v1] = true;
    while(!q.empty()){
        int s = q.front();
        q.pop();
        cout<<s<<" ";
        for(int i=0;i<n;i++){
            if(gr[s][i]==1 && !visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}
void Graph::bfsr(int v1){
    cout<<v1<<" ";
    visited2[v1] = 1;
    for(int i=0;i<n;i++){
        if(gr[v1][i]==1 && visited2[i]==0){
            q.push(i);
            visited2[i]=1;
        }
    }
    if(q.empty()){
        return ;
    }
    int x = q.front();
    q.pop();
    bfsr(x);
}
int main(){
    int v,e;
    cout<<"Enter number of vertices "<<endl;
    cin>>v;
    cout<<"Enter number of edges "<<endl;
    cin>>e;
    Graph g(v);
    g.create(e);
    while(true){
        cout<<"1. Display Graph "<<endl;
        cout<<"2. Dfs "<<endl;
        cout<<"3. BFS "<<endl;
        cout<<"4. Exit "<<endl;
        cout<<"Enter choice "<<endl;
        int ch;
        cin>>ch;
        switch(ch){
            case 1:
            cout<<"Enter Graph is: "<<endl;
            g.display();
            break;
              case 2:
            cout << "Enter node to start dfs from: "<<endl;
            int n1;
            cin >> n1;
            cout << "Recursive DFS: "<<endl;
            g.dfsr(n1);
            cout << "Non - Recursive DFS: "<<endl;
            g.dfs(n1);
            cout <<endl;
            break;
        case 3:
            cout << "Enter node to start bfs from: "<<endl;
            int n2;
            cin >> n2;
            cout << "Recursive BFS: "<<endl;
            g.bfsr(n2);
            cout << "Non - Recursive BFS: "<<endl;
            g.bfs(n2);
            cout<<endl;
            break;
        case 4:
            return 0;
              default:
            cout << "Enter correct choice!!"<<endl;
            break;
        }
        }
        return 0;
    }
