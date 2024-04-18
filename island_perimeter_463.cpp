// 463. Island Perimeter

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            int j = 0;
            int count = 0;
            while (j < grid[0].size()) {
                if (grid[i][j] == 1) {
                    count++;
                    while (j < grid[0].size() and grid[i][j] == 1)
                        j++;
                }
                j++;
            }
            res += count * 2;
        }

        for (int j = 0; j < grid[0].size(); j++) {
            int i = 0;
            int count = 0;
            while (i < grid.size()) {
                if (grid[i][j] == 1) {
                    count++;
                    while (i < grid.size() and grid[i][j] == 1)
                        i++;
                }
                i++;
            }
            res += count * 2;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> data{
        {0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
    cout << sol.islandPerimeter(data);
}