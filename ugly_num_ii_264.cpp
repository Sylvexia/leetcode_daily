// 264. Ugly Number II

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> res{1};
        int i = 0, j = 0, k = 0;
        while (res.size() < n) {
            res.push_back(min(res[i] * 2, min(res[j] * 3, res[k] * 5)));
            if (res.back() == res[i] * 2)
                ++i;
            if (res.back() == res[j] * 3)
                ++j;
            if (res.back() == res[k] * 5)
                ++k;
        }
        return res.back();
    }
};

int main()
{
    Solution sol;
    sol.nthUglyNumber(11);
}