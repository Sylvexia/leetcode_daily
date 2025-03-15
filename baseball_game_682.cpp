// 682. Baseball Game

#include <bits/stdc++.h>
#include <numeric>

using namespace std;

class Solution
{
public:
    int calPoints(vector<string> &operations)
    {
        vector<int> vec;
        for (auto &s : operations) {
            if (s == "+") {
                int n = vec.size();
                vec.push_back(vec[n - 1] + vec[n - 2]);
            } else if (s == "D") {
                vec.push_back(vec.back() * 2);
            } else if (s == "C")
                vec.pop_back();
            else
                vec.push_back(stoi(s));
        }
        return accumulate(vec.begin(), vec.end(), 0);
    }
};