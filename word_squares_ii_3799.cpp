// 3799. Word Squares II

#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();


class Solution
{
public:
    vector<vector<string>> wordSquares(vector<string> &words)
    {
        ranges::sort(words);
        vector<vector<string>> res;
        int n = words.size();

        for (int t = 0; t < n; t++) {
            for (int l = 0; l < n; l++) {
                if (t == l or words[t][0] != words[l][0])
                    continue;
                for (int r = 0; r < n; r++) {
                    if (r == t or r == l or words[t][3] != words[r][0])
                        continue;
                    for (int b = 0; b < n; b++) {
                        if (b == l or b == t or b == r or
                            words[b][0] != words[l][3] or
                            words[b][3] != words[r][3])
                            continue;
                        res.push_back({words[t], words[l], words[r], words[b]});
                    }
                }
            }
        }
        return res;
    }
};