// 799. Champagne Tower

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        vector<double> curr_r(1, poured);

        for (int i = 0; i <= query_row; i++) {
            vector<double> next_r(i + 2, 0);
            for (int j = 0; j <= i; j++) {
                if (curr_r[j] >= 1) {
                    next_r[j] += (curr_r[j] - 1) / 2.0;
                    next_r[j + 1] += (curr_r[j] - 1) / 2.0;
                    curr_r[j] = 1;
                }
            }
            if (i != query_row)
                curr_r = next_r;
        }
        return curr_r[query_glass];
    }
};