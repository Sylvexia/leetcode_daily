// 1718. Construct the Lexicographically Largest Valid Sequence

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    bool dfs(int i, vector<int> &res, vector<bool> isUsed, int targetNum)
    {
        if (i == res.size())
            return true;

        if (res[i] != 0)
            return dfs(i + 1, res, isUsed, targetNum);

        for (int num = targetNum; num >= 1; num--) {
            if (isUsed[num])
                continue;

            isUsed[num] = true;
            res[i] = num;
            if (num == 1) {
                if (dfs(i + 1, res, isUsed, targetNum))
                    return true;
            } else if (i + num < res.size() and res[i + num] == 0) {
                res[i + num] = num;

                if (dfs(i + 1, res, isUsed, targetNum))
                    return true;

                res[i + num] = 0;
            }
            res[i] = 0;
            isUsed[num] = false;
        }
        return false;
    }

public:
    vector<int> constructDistancedSequence(int n)
    {
        vector<int> res(2 * n - 1);
        vector<bool> isUsed(n + 1);
        dfs(0, res, isUsed, n);
        return res;
    }
};