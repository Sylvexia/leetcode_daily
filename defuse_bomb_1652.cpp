// 1652. Defuse the Bomb

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<int> decrypt(vector<int> &code, int k)
    {
        int n = code.size();
        vector<int> res(n, 0);
        if (k == 0)
            return res;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            if (k > 0) {
                for (int j = 0; j < k; j++)
                    sum += code[(i + j) % n];
                res[(i - 1 + n) % n] = sum;
            } else if (k < 0) {
                for (int j = k; j < 0; j++)
                    sum += code[((i + j) + n) % n];
                res[i] = sum;
            }
        }
        return res;
    }
};