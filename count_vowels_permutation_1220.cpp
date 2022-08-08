// 1220. Count Vowels Permutation

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    const int MOD = 1e9 + 7;
    const unordered_map<char, vector<char>> mappings{
        {'s', {'a', 'e', 'i', 'o', 'u'}},
        {'a', {'e'}},
        {'e', {'a', 'i'}},
        {'i', {'a', 'e', 'o', 'u'}},
        {'o', {'i', 'u'}},
        {'u', {'a'}}};

    unordered_map<int, vector<int>> dp;

    int countVowelPermutation(int n)
    {
        dp['s'] = dp['a'] = dp['e'] = dp['i'] = dp['o'] = dp['u'] = vector<int>(n + 1);
        return solve(n, 's');
    }

    int solve(int dim, char prev)
    {
        if (dim == 0)
            return 1;

        if (dp[prev][dim])
            return dp[prev][dim];

        for (auto c : mappings.at(prev))
            dp[prev][dim] = (solve(dim - 1, c) + dp[prev][dim]) % MOD;

        return dp[prev][dim];
    }
};