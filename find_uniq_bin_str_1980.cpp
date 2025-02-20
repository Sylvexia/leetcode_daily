// 1980. Find Unique Binary String

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        int n = nums.size();
        string res;
        for (int i = 0; i < n; i++) {
            res += nums[i][i] == '0' ? '1' : '0';
        }
        return res;
    }
};