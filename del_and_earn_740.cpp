// 740. Delete and Earn

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
    int deleteAndEarn(vector<int> &nums)
    {
        vector<int> map(10001);
        int n = map.size();
        for (int num : nums)
            map[num] += num;

        int take = 0, skip = 0;
        for (int i = 0; i < n; i++) {
            int skip_i = max(take, skip);
            int take_i = skip + map[i];
            skip = skip_i;
            take = take_i;
        }
        return max(take, skip);
    }
};