// 1105. Filling Bookcase Shelves

#include <bits/stdc++.h>
#include <vector>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    vector<vector<int>> dp;
    int dfs(vector<vector<int>> &books, int shelfWidth, int i, int w, int h)
    {
        if (i >= books.size())
            return h;
        if (dp[i][w] != -1)
            return dp[i][w];
        int res = h + dfs(books, shelfWidth, i + 1, books[i][0], books[i][1]);
        if (w + books[i][0] <= shelfWidth)
            res = min(res, dfs(books, shelfWidth, i + 1, w + books[i][0],
                               max(h, books[i][1])));
        return dp[i][w] = res;
    }

public:
    int minHeightShelves(vector<vector<int>> &books, int shelfWidth)
    {
        dp.resize(1001, vector<int>(1001, -1));
        return dfs(books, shelfWidth, 0, 0, 0);
    }
};