// 1007. Minimum Domino Rotations For Equal Row

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution {
public:
    int getSum(int c)
    {
        int res = 0;
        while(c)
        {
            res += c%10;
            c /= 10;
        }
        return res;
    }
    int minElement(vector<int>& nums) {
        int res = INT_MAX;
        for(int c:nums)
            res = min(res, getSum(c));
        return res;
    }
};