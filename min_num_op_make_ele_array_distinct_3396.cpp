// 3396. Minimum Number of Operations to Make Elements in Array Distinct

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        unordered_set<int> u_set;
        int n = nums.size();
        int i = n - 1;

        for (; i >= 0; i--) {
            if (u_set.size() and u_set.count(nums[i]))
                break;
            u_set.insert(nums[i]);
        }

        return i == -1 ? 0 : (i / 3) + 1;
    }
};