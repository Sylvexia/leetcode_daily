// 3068. Find the Maximum Sum of Node Values

#include <bits/stdc++.h>
#include <climits>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    long long maximumValueSum(vector<int> &nums,
                              int k,
                              vector<vector<int>> &edges)
    {
        long long sum = 0;
        int count = 0;
        long long sacrifice = LONG_LONG_MAX;

        for (long long n : nums) {
            sum += max(n ^ k, n);
            count += (n ^ k) > n;
            sacrifice = min(sacrifice, abs(n - (n ^ k)));
        }
        return sum - (count % 2 ? sacrifice : 0);
    }
};