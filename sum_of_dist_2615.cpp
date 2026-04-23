// 2615. Sum of Distances

#include <bits/stdc++.h>
#include <numeric>
#include <unordered_map>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<long long> distance(vector<int> &nums)
    {
        unordered_map<int, vector<int>> getIndices;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            getIndices[nums[i]].push_back(i);
        }

        vector<long long> res(n, 0);
        for (auto &[num, indices] : getIndices) {
            long long sum =
                accumulate(indices.begin(), indices.end(), 0LL);
            long long leftSum = 0;
            int m = indices.size();
            for (int i = 0; i < m; i++) {
                long long rightSum = sum - leftSum - indices[i];
                long long left = 1LL * indices[i] * i - leftSum;
                long long right = rightSum - 1LL * indices[i] * (m - i - 1);
                res[indices[i]] = left + right;
                leftSum += indices[i];
            }
        }
        return res;
    }
};