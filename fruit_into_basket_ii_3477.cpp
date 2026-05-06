// 3477. Fruits Into Baskets II

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets)
    {
        int n = fruits.size();
        int res = n;
        vector<bool> used(n, false);

        for (int f : fruits) {
            for (int i = 0; i < n; i++) {
                if (f <= baskets[i] and !used[i]) {
                    res--;
                    used[i] = true;
                    break;
                }
            }
        }
        return res;
    }
};