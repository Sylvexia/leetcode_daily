// 877. Stone Game

#include <bits/stdc++.h>
#include <numeric>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class SolutionOn
{
    unordered_map<long long, int> dp;

    int dfs(int l, int r, vector<int>& piles) {
        if (l > r) return 0;

        long long key = (l << 16) | r;
        if (dp.count(key)) return dp[key];

        bool even = ((r - l) % 2 == 0);

        int takeLeft = dfs(l + 1, r, piles) + (even ? piles[l] : 0);
        int takeRight = dfs(l, r - 1, piles) + (even ? piles[r] : 0);

        return dp[key] = max(takeLeft, takeRight);
    }

public:
    bool stoneGame(vector<int>& piles) {
        int total = accumulate(piles.begin(), piles.end(), 0);
        int alice = dfs(0, piles.size() - 1, piles);
        return alice > total - alice;
    }
};

class Solution
{
public:
    bool stoneGame(vector<int> &piles) { return true; }
};