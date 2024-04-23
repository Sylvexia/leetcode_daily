// 752. Open the Lock

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    vector<string> turn(string s, int i)
    {
        vector<string> res(2, s);
        res[0][i] = '0' + (res[0][i] - '0' + 1) % 10;
        res[1][i] = '0' + (res[1][i] - '0' - 1 + 10) % 10;
        return res;
    }

public:
    int openLock(vector<string> &deadends, string target)
    {
        unordered_set<string> banned{deadends.begin(), deadends.end()},
            seen({"0000"});
        if (banned.count("0000"))
            return -1;
        if (target == "0000")
            return 0;

        queue<string> q({"0000"});

        int res = 0;
        while (!q.empty()) {
            int q_size = q.size();
            res++;
            for (int i = 0; i < q_size; i++) {
                auto front = q.front();
                q.pop();
                for (int j = 0; j < 4; j++) {
                    for (auto adj_str : turn(front, j)) {
                        if (seen.find(adj_str) == seen.end() and
                            banned.find(adj_str) == banned.end()) {
                            if (adj_str == target)
                                return res;
                            else {
                                q.push(adj_str);
                                seen.insert(adj_str);
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
};