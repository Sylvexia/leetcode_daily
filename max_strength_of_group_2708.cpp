// 2708. Maximum Strength of a Group

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
    long long maxStrength(vector<int> &nums)
    {
        vector<int> pos, neg, zero;
        for (int n : nums) {
            if (n > 0)
                pos.push_back(n);
            else if (n < 0)
                neg.push_back(n);
            else
                zero.push_back(n);
        }

        if (zero.size() and pos.size() == 0 and neg.size() == 0)
            return 0;

        if (pos.size() == 0 and neg.size() == 1) {
            if (zero.size())
                return 0;
            else
                return neg[0];
        }

        long long res = 1;
        for (int n : neg)
            res *= (long long) n;

        if (neg.size() % 2)
            res /= (long long) *max_element(neg.begin(), neg.end());

        for (int p : pos)
            res *= (long long) p;

        return res;
    }
};