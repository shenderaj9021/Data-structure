#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void printmap(unordered_map<int,string> &m){
    cout << m.size()<<endl;
    for(auto it = m.begin();it!=m.end();it++){
        cout << it->first <<" "<<it->second<<endl;
    }
}

int main(){
    //Difference between map and uordered map
    //inbuilt implementation
    //time complexity
    // valid keys datatype
    unordered_map<int,string> un;
    un[8] = "kdhj";
    un[9] = "kdfh";
    un[3] = "djfhk";
    printmap(un);
}