#include<bits//stdc++.h>
using namespace std;
const int N = 1e5+2;
int a[N], tree[4*N];
void build(int node,int st,int en){
    if(st==en){
        tree[node] = a[st];
        return ;
    }
    int mid = (st+en)/2;
    build(2*node,st,mid);
    build(2*node+1,mid+1,en);
    tree[node] = min(tree[node*2],tree[node*2+1]);

}
int query(int node,int st,int en,int l,int r){
    if(en<l || r<st){
        return INT_MAX;
    }
    if(st==en){
        return tree[node];
    }else
    if(st==l && r==en){
        return tree[node];
    }
    int mid = (st+en)/2;
    int q1=query(node*2,st,mid,l,r);
    int q2=query(node*2+1,mid+1,en,l,r);
    return min(q1,q2);
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    build(1,0,n-1);
    for(int i=0;i<25;i++){
        cout<<tree[i]<<" ";
    }
    cout<<endl;
    while(1){
        int t;
        cin>>t;
        if(t==-1){
            break;
        }
        int l,r;
        cin>>l>> r;
       int ans = query(1,0,n-1,l,r);
       cout<<ans<<endl;
    }
}