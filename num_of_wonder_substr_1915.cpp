// 1915. Number of Wonderful Substrings

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long wonderfulSubstrings(string word)
    {
        vector<int> state_count(1024);
        long long res = 0, cur = 0;
        state_count[0] = 1L;
        for (char c : word) {
            cur ^= 1 << (c - 'a');
            res += state_count[cur]++;
            for (int i = 0; i < 10; i++)
                res += state_count[cur ^ (1 << i)];
        }
        return res;
    }
};