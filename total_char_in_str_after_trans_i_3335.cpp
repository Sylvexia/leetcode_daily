// 3335. Total Characters in String After Transformations I

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int lengthAfterTransformations(string s, int t)
    {
        const int MOD = 1e9 + 7;
        vector<long long> count(26);

        for (char c : s)
            count[c - 'a']++;

        for (int i = 0; i < t; i++) {
            vector<long long> tmp(26);
            for (int j = 0; j < 26; j++) {
                if (j == 25) {
                    tmp[0] = (tmp[0] + count[j]) % MOD;
                    tmp[1] = (tmp[1] + count[j]) % MOD;
                } else {
                    tmp[j + 1] = (tmp[j + 1] + count[j]);
                }
            }
            count = tmp;
        }

        long long res = 0;
        for (long long c : count)
            res = (res + c) % MOD;
        return res;
    }
};