#include<bits//stdc++.h>
using namespace std;
// Program to find sum of element fron given array in given range l to r

const int N = 1e5+2;
int a[N], tree[4*N];
void build(int node,int st, int en){
    if(st==en){
        tree[node] = a[st];
        return ;
    }
    int mid = (st+en)/2;
    build(2*node,st,mid);
    build(2*node+1,mid+1,en);
    tree[node] = tree[2*node]+ tree[2*node+1];

}
// Types of segment 
//1] Complete segment
//2] Partial segment.

int query(int node,int st,int en,int l,int r){
    if(st>r || en<l){
        return 0;
    }
    if(l<=st && en<=r){
        return tree[node];
    }
    int mid = (st+en)/2;
    int left = query(2*node,st,mid,l,r);
    int right = query(2*node+1,mid+1,en,l,r);
    return left+right;


}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    build(1,0,n-1);
    while(1){
        int type;
        cin>>type;
        if(type==-1){
            break;
        }
        if(type==1){
            int l,r;
            cin>>l>>r;
            int ans = query(1,0,n-1,l,r);
            cout<<ans<<endl;
        }
    }
}