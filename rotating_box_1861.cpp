// 1861. Rotating the Box

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
    {
        int m = box.size();
        int n = box[0].size();
        for (auto &r : box) {
            int rightmost = n - 1;
            for (int i = n - 1; i >= 0; i--) {
                if (r[i] == '#') {
                    r[i] = '.';
                    r[rightmost] = '#';
                    rightmost--;
                }
                if (r[i] == '*')
                    rightmost = i - 1;
            }
        }

        vector<vector<char>> res(n, vector<char>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[j][m - i - 1] = box[i][j];
            }
        }
        return res;
    }
};