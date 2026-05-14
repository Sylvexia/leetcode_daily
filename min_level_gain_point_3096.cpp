// 3096. Minimum Levels to Gain More Points

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int minimumLevels(vector<int> &possible)
    {
        for (auto &p : possible) {
            p = (p == 0) ? -1 : p;
        }

        int n = possible.size();
        vector<int> alice(n), bob(n);

        alice[0] = possible[0];
        for (int i = 1; i < n; i++)
            alice[i] = possible[i] + alice[i - 1];

        bob[n - 1] = possible[n - 1];
        for (int i = n - 2; i >= 0; i--)
            bob[i] = possible[i] + bob[i + 1];

        for (int i = 0; i < n - 1; i++) {
            if (alice[i] > bob[i + 1])
                return i + 1;
        }
        return -1;
    }
};