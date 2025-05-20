// 3355. Zero Array Transformation I

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        vector<int> vec(n + 1);
        for (auto &q : queries) {
            vec[q[0]]++;
            vec[q[1] + 1]--;
        }

        int cur = 0;
        for (int i = 0; i < n; i++) {
            cur += vec[i];
            if (cur < nums[i])
                return false;
        }
        return true;
    }
};