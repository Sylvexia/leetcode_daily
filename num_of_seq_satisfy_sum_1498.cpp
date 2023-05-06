// 1498. Number of Subsequences That Satisfy the Given Sum Condition

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numSubseq(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());

        int res = 0;
        int mod = 1000000007;

        vector<int> pow2(nums.size() + 1, 1);

        for (int i = 1; i < pow2.size(); i++)
            pow2[i] = (2 * pow2[i - 1]) % mod;

        for (int l = 0, r = nums.size() - 1; l <= r; l++)
        {
            while (l <= r and nums[l] + nums[r] > target)
                r--;

            if (r - l < 0)
                break;

            res = (res + pow2[r - l]) % mod;
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums{2, 3, 3, 4, 6, 7};
    int target = 12;

    cout << sol.numSubseq(nums, target);
}