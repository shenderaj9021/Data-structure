#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void printset(set <string> &s){
    for(auto it=s.begin();it!=s.end();it++)
    {
        cout << (*it)<<endl;
    }

}
int main(){
    set<string> s;
    // we can insert ellement in set using insert
    // we cannot use indexing same as map m[8] in set
    s.insert("jdjjhjk");    //log(n)
    s.insert("kjdfk");
    s.insert("kdjk");
    printset(s);
    auto it = s.find("kdjk"); //log(n) //point to the iterator pointint to the iterator of given key

    // function to erase element
    s.erase("kdjk");
    printset(s);  

    //unorderd set use where ordering doesn't matter
    unordered_set<string> sun;

    sun.insert("djhfhjdf");
    sun.insert("dfdjkfjlsl");
    sun
    
    
    
    
    
    
    
    
    
    
    
    .insert("eireir");


}  