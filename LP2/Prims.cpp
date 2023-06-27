#include<bits//stdc++.h>
using namespace std;
class Graph {
    unordered_map<int,vector<pair<int,int>>>gr;
    vector<int> key;
    vector<bool> mst;
    vector<int> parent;
    int n;
    public:
    Graph(){
        int edge;
        cout<<"Enter number of vertices "<<endl;
        cin>>this->n;
        cout<<"Enter number of Edges "<<endl;
        cin>>edge;
        for(int i=0;i<edge;i++){
            int src,dest;
            cout<<"Enter source "<<i+1<<endl;
            cin>>src;
            cout<<"Enter Destinatination "<<i+1<<endl;
            cin>>dest;
            int dist;
            cout<<"Enter Edge weight "<<endl;
            cin>>dist;
            gr[src].push_back({dest,dist});
            gr[dest].push_back({src,dist});
        }
        key.resize(n+1);
        mst.resize(n+1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            key[i] = INT_MAX;
            parent[i] = -1;
            mst[i] = false;
        }
    }
    void prims(){
        key[1] = 0;
        parent[1] =-1;
        for(int i=1;i<n;i++){
            int mini = INT_MAX;
            int u;
            for(int v=i;v<=n;v++){
                if(mst[v]==false && key[v]< mini){
                    u = v;
                    mini= key[v];
                }
            }
            mst[u] = true;
            for(auto it:gr[u]){
                int v = it.first;
                int w = it.second;
                if(mst[v]==false && w<key[v]){
                    parent[v] = u;
                    key[v] = w;
                }
            }
        }

        for(int i=2;i<=n;i++){
            cout<<parent[i]<<"  "<<i<<"  "<<key[i]<<endl;
        }
    }
};
int main(){
    Graph* g =new Graph();
    g->prims();
}