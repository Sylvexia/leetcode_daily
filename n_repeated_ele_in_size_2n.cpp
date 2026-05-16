// 961. N-Repeated Element in Size 2N Array

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int repeatedNTimes(vector<int> &nums)
    {
        int n = nums.size() / 2;
        unordered_map<int, int> u_map;
        for (int i : nums) {
            u_map[i]++;
        }
        for (auto [key, val] : u_map) {
            if (val == n)
                return key;
        }
        return -1;
    }
};