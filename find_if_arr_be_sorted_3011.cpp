// 3011. Find if Array Can Be Sorted

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    bool canSortArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> vec = nums;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n - i; j++) {
                if (vec[j - 1] < vec[j])
                    continue;
                if (__builtin_popcount(vec[j - 1]) ==
                    __builtin_popcount(vec[j])) {
                    swap(vec[j - 1], vec[j]);
                } else
                    return false;
            }
        }

        return true;
    }
};