// 523. Continuous Subarray Sum

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        unordered_set<int> mod_k;
        int sum = 0, pre = 0;
        for (auto num : nums)
        {
            sum += num;
            int mod = sum % k;
            if (mod_k.count(mod))
                return true;
            mod_k.insert(pre);
            pre = mod;
        }
        return false;
    }
};