// 838. Push Dominoes

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string pushDominoes(string dominoes)
    {
        int n = dominoes.size();
        vector<int> force(n, 0);

        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (dominoes[i] == 'R')
                cur = n;
            else if (dominoes[i] == 'L')
                cur = 0;
            else
                cur = max(cur - 1, 0);
            force[i] += cur;
        }

        for (int i = n - 1; i >= 0; i--) {
            if (dominoes[i] == 'L')
                cur = n;
            else if (dominoes[i] == 'R')
                cur = 0;
            else
                cur = max(cur - 1, 0);
            force[i] -= cur;
        }
        string res;
        for (int f : force) {
            char ch = '.';
            if (f > 0)
                ch = 'R';
            if (f < 0)
                ch = 'L';
            res.push_back(ch);
        }
        return res;
    }
};