// 3184. Count Pairs That Form a Complete Day I

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int countCompleteDayPairs(vector<int> &hours)
    {
        int n = hours.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++)
                res += ((hours[i] + hours[j]) % 24) == 0;
        }
        return res;
    }
};