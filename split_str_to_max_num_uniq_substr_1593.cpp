// 1593. Split a String Into the Max Number of Unique Substrings

#include <bits/stdc++.h>
#include <string>
#include <unordered_set>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    int dfs(string &s, int start, unordered_set<string> &u_set)
    {
        if (start == s.size())
            return u_set.size();

        int res = 0;
        for (int i = 1; i <= s.size() - start; i++) {
            string split = s.substr(start, i);
            if (u_set.find(split) != u_set.end())
                continue;
            u_set.insert(split);
            res = max(res, dfs(s, start + i, u_set));
            u_set.erase(split);
        }
        return res;
    }

public:
    int maxUniqueSplit(string s)
    {
        unordered_set<string> u_set;
        return dfs(s, 0, u_set);
    }
};