
#include<bits//stdc++.h>
using namespace std;
const int N = 1e5+2;
int a[N],tree[4*N];
void build(int node,int st,int en){
    if(st==en){
        tree[node] = a[st];
        return ;
    }
    int mid = (st+en)/2;
    build(2*node,st,mid);
    build(2*node+1,mid+1,en);
    tree[node] = max( tree[node*2],tree[node*2+1]);

}
int query_max(int node,int st,int en,int l,int r){
    if(r<st || l>en){
        return 0;
    }
    if(st==en){
        return tree[node];
        
    }else if(l==st&& r==en){
        return tree[node];
    }else{
        int mid = (st+en)/2;
        int left = query_max(node*2,st,mid,l,r);
        int right = query_max(node*+1,mid+1,en,l,r);
        int ans = max(left,right);
        return ans;
    }
    return 0;
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
            int ans = query_max(1,0,n-1,l,r);
            cout<<ans<<endl;
        }
    }
    return 0;
}