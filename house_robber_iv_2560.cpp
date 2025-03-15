// 2560. House Robber IV

#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int minCapability(vector<int> &nums, int k)
    {
        int ok = *max_element(nums.begin(), nums.end());
        int no = *min_element(nums.begin(), nums.end()) - 1;

        auto valid = [&](long long m) {
            int leq = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] <= m) {
                    leq++;
                    i++;
                }
            }
            return leq >= k;
        };

        while (abs(ok - no) > 1) {
            long long m = (ok + no) / 2;
            if (valid(m))
                ok = m;
            else
                no = m;
        }
        return ok;
    }
};