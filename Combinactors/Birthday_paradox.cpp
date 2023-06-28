/* question - what should be the minimum number of people 
that should be present in a hall so that heres atleast 50% chance of two people having the same birthday

sol - 
p => denotes the chance of atleast 2 ppl have same b'day
1-p => all ppl have diff b'day ( we can easily compute it>>)

let N =1 ( one people will have diffn bday)  ->   365c1 / 365 = 1
    N=2  (Tow people will have diffn bday)   -> (365/365) * (364/365) = 99.72%
    N=3  (Three people will have diffn bday) -> (365/365)*(364/365)*(363/365) = 99.17%

so we can see trend Probabily 1-p is decreasing so p will increas
so we have to just loop N upto certain value where p increate and goes just above 50% or 1-p goes just below 50%


*/

#include<bits//stdc++.h>
using namespace std;
int main(){
    int people = 0;
    float num = 365;
    float denom = 365;

    float prob_diff_bady = 1;
    while(prob_diff_bady>0.5){
        prob_diff_bady = prob_diff_bady*(num/denom);
        cout<<"People "<<people<<" Prob: "<<prob_diff_bady<<endl;
        num--;
        people++;
    }
    cout<<"final ans "<<people<<endl;
    return 0;
}
