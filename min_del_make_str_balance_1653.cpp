// 1653. Minimum Deletions to Make String Balanced

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int minimumDeletions(string s)
    {
        int b_count = 0;
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'b')
                b_count++;
            else
                res = min(res + 1, b_count);
        }
        return res;
    }
};