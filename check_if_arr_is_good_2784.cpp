// 2784. Check if Array is Good

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    bool isGood(vector<int> &nums)
    {
        unordered_set<int> u_set(nums.begin(), nums.end());
        int n = nums.size() - 1;
        int count2 = 0;

        for (int i = 1; i <= n; i++) {
            if (!u_set.count(i))
                return false;
        }
        
        for (int i : nums)
            count2 += i == n;

        return count2 == 2;
    }
};