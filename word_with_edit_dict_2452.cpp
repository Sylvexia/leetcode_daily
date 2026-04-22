// 2452. Words Within Two Edits of Dictionary

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<string> twoEditWords(vector<string> &queries,
                                vector<string> &dictionary)
    {
        vector<string> res;
        for (auto &q : queries) {
            for (auto &d : dictionary) {
                int n = q.size();
                int diff = 0;
                for (int i = 0; i < n; i++) {
                    diff += (d[i] != q[i]);
                }
                if(diff<=2)
                {
                    res.push_back(q);
                    break;
                }
            }
        }
        return res;
    }
};