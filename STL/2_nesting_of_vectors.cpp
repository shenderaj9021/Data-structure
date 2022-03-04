#include<iostream>
#include<bits//stdc++.h>
using namespace std;
void printpairvector(vector<pair<int,int>> &v){
    for(int i=0;i<v.size();i++){
        cout <<v[i].first <<"  "<<v[i].second<<endl;
    }
}
void printvector(vector<int> &v){
    for(int i=0;i<v.size();i++){
        cout <<v[i]<<endl;
    }
    cout <<endl;
}
int main(){
    //this  will create vector of pairs
    //vector is predefine
    vector<pair<int,int>> v ={{1,2},{2,3}};

    //how to print nested vetor
    printpairvector(v);   //look function code
   

    vector<pair<int,int>> vec;

    //push back
    vec.push_back({6,7});
    vec.push_back({10,70});
    vec.push_back(make_pair(40,50));
    printpairvector(vec);

    //vector of vector
    vector <vector<int>> v1;
    //heare v1 is vector of vector that this vector contain vector
    for(int i=0;i<4;i++){
        vector <int> temp;          //here we create temporary vector which get element
        for(int j=0;j<8;j++){    //then this vector push into big vector
            temp.push_back(j);
        }
        v1.push_back(temp);
    }
    //print vector of vector
    for(int i=0;i<v1.size();i++){
        printvector(v1[i]);
    }

    //array of vector
    //vector<int> v[10]; this is array of vector
    

    return 0;
    

}