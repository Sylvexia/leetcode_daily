// 1295. Find Numbers with Even Number of Digits

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int res = 0;
        for (int n : nums) {
            string s = to_string(n);
            res += (s.size() % 2 == 0);
        }
        return res;
    }
};