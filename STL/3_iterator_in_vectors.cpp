#include<iostream>
#include<bits//stdc++.h>
using namespace std;
int main(){
    vector<int> v={1,2,3,4,5,7};
    for(int i=0;i<v.size();i++){
        cout <<v[i]<<" ";
    }
    cout <<endl;
    //iterator is pointer pointing to the fist location of vector
    // it.begin()   = pointing to fist element that is begining of vector
    // it.end() = pointint to the pointer next to the last element so if 
    //beign is equal to end that is iteration is and;
    vector<int> ::iterator it=v.begin();
    cout <<(*(it+2))<<endl;
    for(it=v.begin();it!=v.end();++it){
        cout <<(*it)<<endl;
    }
    //remeber that we should create different iterator for different vector in same program
    vector<pair<int,int>> v_p ={{1,2},{2,3},{9,7}};  //vector of pairs
    vector<pair<int,int>> :: iterator itp;          //iterator pointing to vactor of pairs
    for(itp=v_p.begin();itp!=v_p.end();++itp){
        cout <<itp->first <<"  "<<(*itp).second <<endl;  // here can use *it as wll
    }

    //we can also use iterator in short code as follows
    vector<int> vec = {2,3,4,5,6,7,9};
    for(int value:vec){             //when we use this it create copy of element in vetctor
        cout <<value<<" ";       //change on value not affect vector element
    }
    cout <<endl;
    for(int value:vec){        //this will print copy of value of element with by icreamenting copy
        value++;
        cout <<value<<" ";
    }
    cout <<endl;
     for(int value:vec){      //this is default vector so no change
        
        cout <<value<<" ";
    }
    cout <<endl;
     for(int &value:vec){       //here we are passing reference to the vactor so
        value++;             // so increment in value also change value of element in original vec
        cout <<value<<" ";
    }
    cout <<endl;
     for(int &value:vec){   //heare we can see actual change
        cout <<value<<" ";
    }
    for(pair<int,int> &value:v_p){
        cout <<value.first <<" "<<value.second<<endl;
    }


    //another way to iterate vector
    // iteration using auto keyword
    //what does actuall auto keyword do?
    for(auto it = vec.begin();it!=vec.end();it++){
        cout <<(*it)<<"  ";
    }
    //auto defines it data type by it self we does not neee to define it
    //so when we declare auto it is define datatype of it by itself
    //hence our work to write   vector<int> ::iterator it=vec.begin();  this line is save
    return 0;

}