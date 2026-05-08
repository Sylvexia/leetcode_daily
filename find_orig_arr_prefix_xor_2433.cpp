// 2433. Find The Original Array of Prefix Xor

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<int> findArray(vector<int> &pref)
    {
        int n = pref.size();
        vector<int> res(n);
        res[0] = pref[0];
        for (int i = 1; i < n; i++)
            res[i] = pref[i] ^ pref[i - 1];
        return res;
    }
};