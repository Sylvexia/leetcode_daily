// 3151. Special Array I

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    bool isArraySpecial(vector<int> &nums)
    {
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            int a = nums[i] & 1;
            int b = nums[i + 1] & 1;
            if (a + b != 1)
                return false;
        }
        return true;
    }
};