#include<bits//stdc++.h>
using namespace std;
#define V 5
int minKey(vector<int> key,vector<bool> mstset){
    int mi = INT_MAX;
    int min_index;
    for(int v=0;v<V;v++){
        if(mstset[v]==false && key[v]<mi){
            mi = key[v];
            min_index = v;
        }
    }
    return min_index;
}
void printmst(vector<int> parent,vector<vector<int>>graph){
    cout<<"Edge weight"<<endl;
    for(int i=1;i<V;i++){
        cout<<parent[i]<<" - "<<i<<"\t"<<graph[i][parent[i]]<<" \n ";
    }
}
void primmst(vector<vector<int>> graph){
    vector<int> parent(V);
    vector<int> key(V);
    vector<bool>mstset(V);
    for(int i=0;i<V;i++){
        key[i] = INT_MAX;
        mstset[i] = false;
    }
    key[0] =0;
    parent[0]= -1;
    for(int count=0;count<V-1;count++){
        int u = minKey(key,mstset);
        mstset[u] = true;
        for(int i=0;i<V;i++){
            if(graph[u][i] && mstset[i]==false && graph[u][i]<key[i]){
                parent[i]= u;
                key[i] = graph[u][i];
            }

        }
        
    }
    printmst(parent,graph);
}
int main(){
    vector<vector<int>>graph = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
 
    // Print the solution
    primmst(graph);
 
    return 0;
}