// 2554. Maximum Number of Integers to Choose From a Range I

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int maxCount(vector<int> &banned, int n, int maxSum)
    {
        set<int> white, black;

        for (auto b : banned)
            black.insert(b);

        for (int i = 1; i <= n; i++) {
            if (!black.count(i))
                white.insert(i);
        }

        int sum = 0, count = 0;
        for (auto ele : white) {
            sum += ele;
            if (sum > maxSum)
                return count;
            count++;
        }
        return count;
    }
};