#include<bits//stdc++.h>
using namespace std;
class Rules{
    string rule1(unordered_map<string,int>&evaluation){
        if(evaluation["communication"]>=4 && evaluation["teamwork"]>=4){
            return "The empoyee strong communication and teamwork ";
        }else{
            return "";
        }
    }
    string reule2(unordered_map<string,int>&evaluation){
        if(evaluation["puntuality"]>=4 && evaluation["attendance"]>=4){
             return "The employee consistently shows punctuality and excellent attendance.";
        } else
        {
            return "";
        }
    }
    string rule3(unordered_map<string, int> &evaluation)
    {
        if (evaluation["quality"] >= 4 && evaluation["productivity"] >= 4)
            return "The employee consistently delivers high-quality work and maintains good productivity levels.";
        return "";
    }

    string rule4(unordered_map<string, int> &evaluation)
    {
        if (evaluation["adaptability"] >= 4 && evaluation["problem_solving"] >= 4)
            return "The employee demonstrates excellent adaptability and problem-solving skills.";
        return "";
    }

    string rule5(unordered_map<string, int> &evaluation)
    {
        if (evaluation["leadership"] >= 4 && evaluation["initiative"] >= 4)
            return "The employee exhibits strong leadership qualities and takes initiative.";
        return "";
    }
    public:
    vector<string> evaluate_performance(unordered_map<string,int>& evaluation){
        vector<string> results;
        string s = rule1(evaluation);
        if(s!=""){
            results.push_back(s);
        }
        s = rule2(evaluation);
        if (s != "")
            results.push_back(s);

        s = rule3(evaluation);
        if (s != "")
            results.push_back(s);

        s = rule4(evaluation);
        if (s != "")
            results.push_back(s);

        s = rule5(evaluation);
        if (s != "")
            results.push_back(s);

        return results;
    }
    unordered_map<string,int>getInput()
    {
        unordered_map<string,int> evaluation;
        vector<string> qualities = {"attendance","adaptibility","punctuality","consistency","problem-solving","teamwork","leadership","intiative","productivity","communication","quality"};
        int score=0;
        for(int i=0;i<10;i++){
            lbl:
                cout<<"Enter the score between 0-5"<<qualities[i]<<" fot the employee: ";
                while(!(cin>score)){
                    cout<<"Enter a valid numeric value: "<<endl;
                    cin.clear();
                    cin.ignore(100,'\n');
                }
                if(score<0 || score>5){
                    cout<<"value out of bound detected, reinput the value "<<endl;
                    cin.clear();
                    cin.ignore(1000,'\n');
                    goto lbl;
                }
                evaluation[qualities[i]]=score;
        }
        return evaluation;
    }
};
int main(){
    
    Rules r;
    unordered_map<string, int> evaluation = r.getInput();
    vector<string> result = r.evaluate_perfromance(evaluation);
    if (result.empty())
    {
        cout << "Can not commit on the performance of the employee!!\n";
    }

    else
    {
        for (auto &x : result)
            cout << x << endl;
        cout << endl;
    }

    return 0;
}