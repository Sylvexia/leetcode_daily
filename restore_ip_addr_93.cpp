// 93. Restore IP Addresses

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    void dfs(string &s, string &gen, int start, int step, vector<string> &res)
    {
        if (start == s.size() && step == 4)
        {
            gen.erase(gen.end() - 1);
            res.push_back(gen);
            return;
        }

        if (s.size() - start > (4 - step) * 3)
            return;

        if (s.size() - start < (4 - step))
            return;

        int num = 0;
        for (int i = start; i < start + 3; i++)
        {
            num = num * 10 + (s[i] - '0');
            if (num < 256)
            {
                gen.push_back(s[i]);
                string temp = gen + '.';
                dfs(s, temp, i + 1, step + 1, res);
            }
            if (num == 0)
                break;
        }
    }

public:
    vector<string> restoreIpAddresses(string s)
    {
        string gen{};
        vector<string> res{};
        dfs(s, gen, 0, 0, res);
        return res;
    }
};