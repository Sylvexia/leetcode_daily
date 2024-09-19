// 241. Different Ways to Add Parentheses

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    vector<int> dfs(string &str)
    {
        vector<int> res;
        if (str.length() == 0)
            return res;
        if (str.length() == 1)
            return {str[0] - '0'};
        if (str.length() == 2)
            return {(str[0] - '0') * 10 + str[1] - '0'};

        for (int i = 0; i < str.size(); i++) {
            if (str[i] >= '0' and str[i] <= '9')
                continue;

            string left_str = str.substr(0, i);
            vector<int> left_res = dfs(left_str);

            string right_str = str.substr(i + 1);
            vector<int> right_res = dfs(right_str);

            for (int l : left_res) {
                for (int r : right_res) {
                    int res_val = 0;
                    if (str[i] == '+')
                        res_val = l + r;
                    else if (str[i] == '-')
                        res_val = l - r;
                    else if (str[i] == '*')
                        res_val = l * r;
                    res.push_back(res_val);
                }
            }
        }
        return res;
    }

public:
    vector<int> diffWaysToCompute(string expression) { return dfs(expression); }
};