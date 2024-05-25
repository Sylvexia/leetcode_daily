// 140. Word Break II

#include <string>
#include <unordered_set>
#include <vector>
#include "bits/stdc++.h"

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    void dfs(unordered_set<string> &u_set,
             string &s,
             vector<string> &gen,
             vector<string> &res)
    {
        if (s.size() == 0) {
            string str = "";
            for (auto &e : gen)
                str += e + " ";
            str.pop_back();
            res.push_back(str);
            return;
        }

        for (int i = 0; i < s.length(); i++) {
            if (u_set.count(s.substr(0, i + 1))) {
                gen.push_back(s.substr(0, i + 1));
                string sub = s.substr(i + 1);
                dfs(u_set, sub, gen, res);
                gen.pop_back();
            }
        }
    }

public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        vector<string> res, gen;
        unordered_set<string> u_set(wordDict.begin(), wordDict.end());

        dfs(u_set, s, gen, res);
        return res;
    }
};