// 2914. Minimum Number of Changes to Make Binary String Beautiful

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int minChanges(string s)
    {
        int res = 0;
        for (int i = 0; i < s.size() - 1; i += 2) {
            if (s[i] != s[i + 1])
                res++;
        }
        return res;
    }
};