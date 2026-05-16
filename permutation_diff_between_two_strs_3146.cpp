// 3146. Permutation Difference between Two Strings

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int findPermutationDifference(string s, string t)
    {
        unordered_map<int, int> s_map, t_map;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            s_map[s[i]] = i;
            t_map[t[i]] = i;
        }

        int res = 0;
        for (auto [key, val] : s_map) {
            res += abs(t_map[key] - val);
        }
        return res;
    }
};