// 3152. Special Array II

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries)
    {
        vector<bool> res(queries.size());
        vector<int> prefix(nums.size());

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] % 2 == nums[i - 1] % 2)
                prefix[i] = prefix[i - 1] + 1;
            else
                prefix[i] = prefix[i - 1];
        }

        for (int i = 0; i < queries.size(); i++) {
            int start = queries[i][0];
            int end = queries[i][1];
            res[i] = prefix[end] - prefix[start] == 0;
        }
        return res;
    }
};