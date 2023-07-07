#include<bits//stdc++.h>
using namespace std;
struct  Node {
    Node* linker[2];
    bool containsKey(int c){
        return linker[c]!=NULL;
    }
    void put(int c,Node* node){
        linker[c] = node;
    }
    Node* get(int c){
        return linker[c];
    }
};
class Trie {
    Node* root;
    public:
    Trie(){
        root=  new Node();
    }
    void insert(int num){
        Node* node = root;
        for(int i=31;i>=0;i--){
            int bit = (num>>i)&1;
            if(!node->containsKey(bit)){
                node->put(bit,new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int num){
        Node* node  = root;
        int maxNum =0;
        for(int i=31;i>=0;i--){
            int bit = (num>>i)&1;
            if(node->containsKey(1-bit)){
                maxNum = maxNum |(1<<i);
                node = node->get(1-bit);
            }else{
                node = node->get(bit);
            }

        }
        return maxNum;
    }
};
int main(){
    vector<int> arr1 ={1,2,3,5,8};
    vector<int> arr2 = {2,3,7,9,12};
    Trie trie;
    cout<<"Helo "<<endl;
    for(auto it:arr1){
        trie.insert(it);
    }
    int maxi =0;
     cout<<"Helo "<<endl;
    for(auto &it:arr2){
        maxi = max(maxi,trie.getMax(it));
    }
     cout<<"Helo "<<endl;
    cout<<maxi<<endl;
    return 0;
}