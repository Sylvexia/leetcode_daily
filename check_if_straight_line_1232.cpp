// 1232. Check If It Is a Straight Line

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    inline int f(int x_coef, int x, int y_coef, int y)
    {
        return x * x_coef + y * y_coef;
    }

public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        int x_coef = coordinates[0][1] - coordinates[1][1];
        int y_coef = coordinates[1][0] - coordinates[0][0];
        int check = f(x_coef, coordinates[0][0], y_coef, coordinates[0][1]);

        for (auto c : coordinates) {
            if (f(x_coef, c[0], y_coef, c[1]) != check)
                return false;
        }
        return true;
    }
};