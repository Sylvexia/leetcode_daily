#include <bits/stdc++.h>
#include <climits>
#include <string>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int rev(int num)
    {
        string str = to_string(num);
        reverse(str.begin(), str.end());
        return atoi(str.c_str());
    }

    int minMirrorPairDistance(vector<int> &nums)
    {
        unordered_map<int, int> getIndex;
        int res = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (getIndex.find(nums[i]) != getIndex.end())
                res = min(res, i - getIndex[nums[i]]);
            int rev_num = rev(nums[i]);
            getIndex[rev_num] = i;
        }
        return res == INT_MAX ? -1 : res;
    }
};