#include<bits//stdc++.h>
using namespace std;

vector<pair<regex,string>> rules = {
    {regex("hi|hello",regex_constants::icase),"Hello!, How can I assist you? "},
    {regex(".*name.*",regex_constants::icase),"My name is chatbot. "},
    {regex(".*sports.*",regex_constants::icase)," I love sports ! I like playing cricket "},
    {regex(".*actor.*",regex_constants::icase),"Hesfsdf"},
    {regex(".*created.* | .*creator.*",regex_constant::icase),"Raj shende"},
    {regex("how.*are.*you",regex_constants::icase),"i am doing well"},
    {regex("exit",regex_constants::icase),"GoodBye "},
};
string generateResponse(string& userInput){
    for(const auto& rule:rules){
        if(regex_search(userInput,rule.first)){
            return rule.second;
        }
    }
    return "I am sorry, I don't understand";
}
int main(){
    string userInput;
    cout<<"Hello How can i assist you?"<<endl;
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
