// 1863. Sum of All Subset XOR Totals

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    int res = 0;

    void dfs(int idx, int local, vector<int> &nums)
    {
        if (idx == nums.size()) {
            res += local;
            return;
        }
        dfs(idx + 1, local ^ nums[idx], nums);
        dfs(idx + 1, local, nums);
    }

public:
    int subsetXORSum(vector<int> &nums)
    {
        dfs(0, 0, nums);
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> data = {5, 1, 6};
    int res = sol.subsetXORSum(data);
    cout << res;
}