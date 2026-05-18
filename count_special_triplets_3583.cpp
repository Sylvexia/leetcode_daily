// 3583. Count Special Triplets

#include <bits/stdc++.h>
#include <cmath>
#include <unordered_map>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class SolutionNlogN
{
public:
    int specialTriplets(vector<int> &nums)
    {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        unordered_map<int, vector<int>> getIdx;
        for (int i = 0; i < n; i++) {
            getIdx[nums[i]].push_back(i);
        }

        long long res = 0;
        for (int i = 0; i < n; i++) {
            int query = nums[i] * 2;
            if (!getIdx.count(query))
                continue;

            auto &vec = getIdx[query];
            int before = lower_bound(vec.begin(), vec.end(), i) - vec.begin();

            int after = vec.end() - upper_bound(vec.begin(), vec.end(), i);
            res = (res + 1LL * before * after) % MOD;
        }
        return res;
    }
};

class Solution
{
public:
    int specialTriplets(vector<int> &nums)
    {
        const int MOD = 1e9 + 7;
        int n = nums.size();

        unordered_map<int, int> left, right;
        for (int x : nums)
            right[x]++;

        long long res = 0;
        for (int i = 0; i < n; i++) {
            right[nums[i]]--;
            int query = nums[i] * 2;

            long long before = left[query];
            long long after = right[query];

            res = (res + before * after) % MOD;
            left[nums[i]]++;
        }

        return res;
    }
};