// 2962. Count Subarrays Where Max Element Appears at Least K Times


#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        int max_ele = *max_element(nums.begin(), nums.end());
        int cur = 0, i = 0;
        long long res = 0;
        for (int j = 0; j < nums.size(); j++) {
            cur += nums[j] == max_ele;
            while (cur >= k) {
                cur -= nums[i] == max_ele;
                i++;
            }
            res += i;
        }
        return res;
    }
};