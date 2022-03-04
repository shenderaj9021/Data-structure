#include<iostream>
#include<bits//stdc++.h>
using namespace std;
void printmap(map<int,string> &m){
    cout << m.size()<<endl;
    for(auto it = m.begin();it!=m.end();it++){
        cout << it->first <<" "<<it->second<<endl;
    }
}
int main(){
    //maps have one key and value pair whrer each key hold on value
    //map declared as follows
    map<int, string> m;
    //key and value pair can be added in map in different ways as folows
    // map[key] = value
    m[1]="abc";                         //complexity O(log n)
    m[4]="djh";
    m[3]="dkdj";
    m.insert({9,"kijk"});
    for(auto it = m.begin();it!=m.end();it++){
        cout << it->first <<" "<<it->second<<endl;
    }
    //the output the above code will change the order of insertion of key and pair 
    // that is map stored key in order 
    //IMP - key in map are unit if we enter different value for same key it replace that value
    auto it = m.find(3);   //complexity O(log n) //returns iterator pointing to the value of key 3
    m.erase(3);              //complexity O(log n)
    //this will delete kay 3 form map 

    m.clear();
    //this will delete all key and value pairs from map
    printmap(m);
    return 0;
}