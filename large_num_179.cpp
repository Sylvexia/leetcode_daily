// 179. Largest Number

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        vector<string> str_num;
        for (int n : nums)
            str_num.push_back(to_string(n));
        auto comp = [](string &a, string &b) { return a + b > b + a; };
        sort(str_num.begin(), str_num.end(), comp);
        string res;
        for (string &str : str_num)
            res += str;
        for (char c : res) {
            if (c != '0')
                return res;
        }
        return "0";
    }
};