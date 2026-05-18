// 1253. Reconstruct a 2-Row Binary Matrix

#include <bits/stdc++.h>
#include <numeric>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<vector<int>> reconstructMatrix(int upper,
                                          int lower,
                                          vector<int> &colsum)
    {
        int sum = accumulate(colsum.begin(), colsum.end(), (int) 0);
        if (sum != upper + lower)
            return {};

        int n = colsum.size();
        vector<int> u_vec(n), l_vec(n);
        for (int i = 0; i < n; i++) {
            if (colsum[i] == 2) {
                u_vec[i] = 1;
                l_vec[i] = 1;
                colsum[i] = 0;
                upper--;
                lower--;
            }
        }

        if (upper < 0 or lower < 0)
            return {};

        for (int i = 0; i < n and upper > 0; i++) {
            if (colsum[i] == 1) {
                u_vec[i] = 1;
                colsum[i] = 0;
                upper--;
            }
        }

        for (int i = 0; i < n and lower > 0; i++) {
            if (colsum[i] == 1) {
                l_vec[i] = 1;
                colsum[i] = 0;
                lower--;
            }
        }

        for (int i = 0; i < n; i++) {
            if (colsum[i] == 1)
                return {};
        }

        return {{u_vec}, {l_vec}};
    }
};