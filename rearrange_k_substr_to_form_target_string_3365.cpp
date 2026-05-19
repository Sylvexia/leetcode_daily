// 3365. Rearrange K Substrings to Form Target String

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
    bool isPossibleToRearrange(string s, string t, int k)
    {
        unordered_map<string, int> u_map;
        int n = s.size();
        for (int i = 0; i < n; i += n / k) {
            string cur = s.substr(i, n / k);
            u_map[cur]++;
        }

        for (int i = 0; i < n; i += n / k) {
            string cur = t.substr(i, n / k);
            if (u_map[cur] == 0)
                return false;
            u_map[cur]--;
        }
        return true;
    }
};