// 120. Triangle

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<int> dp{triangle[0][0]};

        for (int i = 0; i < n - 1; i++) {
            vector<int> cur(i + 2, 100000);
            for (int j = 0; j <= i; j++) {
                cur[j] = min(cur[j], dp[j] + triangle[i + 1][j]);
                cur[j + 1] = min(cur[j + 1], dp[j] + triangle[i + 1][j + 1]);
            }
            dp = cur;
        }
        return *min_element(dp.begin(), dp.end());
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> data{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    sol.minimumTotal(data);
}