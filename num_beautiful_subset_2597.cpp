// 2597. The Number of Beautiful Subsets

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution
{
    int dfs(vector<int> &nums, int k, int start, unordered_map<int, int> &gen)
    {
        if (start == nums.size()) {
            return 1;
        }

        int cur = dfs(nums, k, start + 1, gen);

        if (!gen[nums[start] - k]) {
            gen[nums[start]]++;
            cur += dfs(nums, k, start + 1, gen);
            gen[nums[start]]--;
        }
        return cur;
    }

public:
    int beautifulSubsets(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> gen;
        return dfs(nums, k, 0, gen) - 1;
    }
};