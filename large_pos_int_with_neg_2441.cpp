// 2441. Largest Positive Integer That Exists With Its Negative

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int findMaxK(vector<int> &nums)
    {
        unordered_set<int> u_set;

        for (int n : nums)
            u_set.insert(n);

        int res = -1;
        for (int n : u_set) {
            if (u_set.count(-n))
                res = max(res, abs(n));
        }

        return res;
    }
};