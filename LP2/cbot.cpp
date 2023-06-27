#include<bits//stdc++.h>
using namespace std;

vector<pair<regex,string>>rules ={
    {regex("hi|hello",regex_constants::icase),"hello, How can i assist uo "},
    {regex(".*name.*",regex_constants::icase),"my name is rjbot"},
    {regex(".*sports.*",regex_constants::icase),"I love cricket"},
    {regex(".*actor.*",regex_constants::icase),"sallu bhai"},
    {regex(".*created.* | .*creator.*",regex_constants::icase),"raj bhai"},
    {regex("how.*are.* you",regex_constants::icase),"i ma doing well "},
    {regex("exit",regex_constants::icase),"goodbye"},
};
string generateResponse(string& userInput){
    for(const auto& rule:rules){
        if(regex_search(userInput,rule.first)){
            return rule.second;
        }
    }
    return " I am sorry, I don't understand ";
}
int main(){
    string userInput;
    cout<<"Hello How can i assist you "<<endl;
    while(true){
        cout<<"User ";
        getline(cin,userInput);
        string response = generateResponse(userInput);
        cout<<"chatbot "<<response<<endl;
        if(regex_search(userInput,regex("exit",regex_constants::icase))){
            break;
        }
    }
}