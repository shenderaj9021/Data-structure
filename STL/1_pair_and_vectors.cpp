#include<iostream>
#include<bits//stdc++.h>
using namespace std;
void printvector(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout <<v[i]<<endl;
    }
    cout <<endl;
}
int main(){
    pair<int, string> p;
    // syntax pair< datatype 1, datatype2>
    //Declaration of pair
    // p = make_pair(datatype1 value, datatype2 value)
    // p = {datatype1 value, datatype2 value}
    p = make_pair(2,"raj");
    cout << p.first <<"  "<<p.second<<endl;
    //copy one pair to other
    pair <int ,string> pcopy=p;
    //above one pair copy to other
    pair<int,string> &pref = p;
    //in above one pair is reference to other


    //Array of pair
    pair<int,int> pair_arr[4];    //pair array of size 4


    //--------------------------------------------------------------------------
    //vectors
    //vector is contigious memory blocks same as array but array cannot change size but vector can change size
    vector<int> v;
    //vector of given size, but this vector can be also incresed furhter not , mns it not same as array
    vector <int> v_sized(10);     //vector of 10 element
    //declare vector of given size and fill with on number
    vector <int>v_filled(5,1)  ;  //vector with 5 elements with all value 1
    printvector(v_filled);
    

    //push element in vector (add element at last);
    v.push_back(80);     //O(1)
    v.push_back(90);
    v.push_back(100);
    printvector(v);
    // remove last element from vector(remove last element)
    v.pop_back();    //O(1);
    printvector(v);

    //copy of vector
    vector<int> v1 = v;       //complexity O(n)
    //here v1 is copy of v that change in any of them no affect oher
    vector<int> &v2 = v;
    //here v2 is not copy of v but it have same element as v and any changes in both
    //affect each other-*


// so always remeber when we passing vector to other function don't send vector directly
//send it's reference, that is &v , becoz when we directy pass vectors it not passed actullay
//but its copy is created which takes O(n) complexity,
    
    return 0;
}