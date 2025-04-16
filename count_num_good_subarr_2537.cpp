// 2537. Count the Number of Good Subarrays

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    long long countGood(vector<int> &nums, int k)
    {
        long long res = 0;
        unordered_map<int, int> uMap;
        int n = nums.size();
        for (int l = 0, r = 0; r < n; r++) {
            k -= uMap[nums[r]]++;
            while (k <= 0)
                k += --uMap[nums[l++]];
            res += l;
        }
        return res;
    }
};