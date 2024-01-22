// 260. Single Number III

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        long long int xors = 0;
        for (auto num : nums)
            xors = num ^ xors;

        xors &= (-xors);

        int res_a = 0;
        int res_b = 0;
        for (auto num : nums) {
            if (xors & num)
                res_a ^= num;
            else
                res_b ^= num;
        }

        return {res_a, res_b};
    }
};