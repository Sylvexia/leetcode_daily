// 3289. The Two Sneaky Numbers of Digitville

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<int> getSneakyNumbers(vector<int> &nums)
    {
        unordered_set<int> uset;
        vector<int> res;
        for (int n : nums) {
            if (uset.count(n))
                res.push_back(n);
            uset.insert(n);
        }
        return res;
    }
};