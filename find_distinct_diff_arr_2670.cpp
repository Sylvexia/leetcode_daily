// 2670. Find the Distinct Difference Array

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> distinctDifferenceArray(vector<int> &nums)
    {
        unordered_set<int> p, s;
        vector<int> pre(nums.size(), 0), suf(nums.size(), 0), ret(nums.size());

        for (int i = 0; i < nums.size(); i++)
        {
            p.insert(nums[i]);
            if (i != 0)
            {
                s.insert(nums[nums.size() - i]);
                suf[nums.size() - i - 1] = s.size();
            }
            pre[i] = p.size();
        }

        for (int i = 0; i < nums.size(); i++)
            ret[i] = pre[i] - suf[i];

        return ret;
    }
};
