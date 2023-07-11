// 2024. Maximize the Confusion of an Exam
// https://leetcode.com/problems/maximize-the-confusion-of-an-exam/description/
#include <bits//stdc++.h>
using namespace std;

int maxConsecutiveAnswers(string answerKey, int k)
{
    vector<char> arr = {'T', 'F'};
    int n = answerKey.size();
    int ans = 0;

    int i = 0;
    int j = 0;
    int sum = 0;
    for (j = 0; j < n; j++)
    {
        if (answerKey[j] != 'T')
        {
            sum++;
        }
        while (sum > k)
        {
            if (answerKey[i] != arr[0])
            {
                sum--;
            }
            i++;
        }
        ans = max(j - i + 1, ans);
    }
    i = 0;
    j = 0;
    sum = 0;
    for (j = 0; j < n; j++)
    {
        if (answerKey[j] != 'F')
        {
            sum++;
        }
        while (sum > k)
        {
            if (answerKey[i] != arr[1])
            {
                sum--;
            }
            i++;
        }
        ans = max(j - i + 1, ans);
    }

    return ans;
}
int main()
{
    string answerKey = "TTFF";
    int k = 2;
    cout<<maxConsecutiveAnswers(answerKey,k);
}
