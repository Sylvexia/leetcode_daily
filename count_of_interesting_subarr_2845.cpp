// 2845. Count of Interesting Subarrays

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    long long countInterestingSubarrays(vector<int> &nums, int modulo, int k)
    {
        int n = nums.size();
        unordered_map<int, int> uMap;
        long long res = 0;

        uMap[0] = 1;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            cur += nums[i] % modulo == k;
            res += uMap[(cur - k + modulo) % modulo];
            uMap[cur % modulo]++;
        }
        return res;
    }
};