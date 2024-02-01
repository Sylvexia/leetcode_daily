// 89. Gray Code

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    void backtrack(int n, vector<int> &res, int &gen)
    {
        if (n == 0) {
            res.push_back(gen);
            return;
        }

        backtrack(n - 1, res, gen);
        gen ^= (1 << (n - 1));  // flip n-1th bit
        backtrack(n - 1, res, gen);
        return;
    }

public:
    vector<int> grayCode(int n)
    {
        vector<int> res;
        int gen = 0;
        backtrack(n, res, gen);
        return res;
    }
};

class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> res{0};

        for (int i = 0; i < n; i++) {
            vector<int> cur;
            for (int j = res.size() - 1; j >= 0; j--) {
                int value = (1<<i) | res[j];
                cur.push_back(value);
            }
            res.insert(res.end(), cur.begin(), cur.end());
        }

        return res;
    }
};