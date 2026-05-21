// 2249. Count Lattice Points Inside a Circle

#include <bits/stdc++.h>
#include <string>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    string get_key(int a, int b) { return to_string(a) + "_" + to_string(b); }

public:
    int countLatticePoints(vector<vector<int>> &circles)
    {
        unordered_set<string> u_set;

        for (auto &c : circles) {
            int x = c[0];
            int y = c[1];
            int r = c[2];
            for (int i = y - r; i <= y + r; i++) {
                for (int j = x - r; j <= x + r; j++) {
                    if (r * r >= (i - y) * (i - y) + (j - x) * (j - x))
                        u_set.insert(get_key(i, j));
                }
            }
        }

        return u_set.size();
    }
};