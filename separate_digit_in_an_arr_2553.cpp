// 2553. Separate the Digits in an Array

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class SolutionN2
{
public:
    vector<int> separateDigits(vector<int> &nums)
    {
        vector<int> res;
        for (int n : nums) {
            vector<int> inner;
            if (n == 0)
                inner.push_back(0);

            while (n) {
                inner.push_back(n % 10);
                n /= 10;
            }
            reverse(inner.begin(), inner.end());
            res.insert(res.end(), inner.begin(), inner.end());
        }
        return res;
    }
};

class Solution
{
public:
    vector<int> separateDigits(vector<int> &nums)
    {
        vector<int> res;
        for (int n : nums) {
            string str = to_string(n);
            for (char ch : str)
                res.push_back(ch - '0');
        }
        return res;
    }
};