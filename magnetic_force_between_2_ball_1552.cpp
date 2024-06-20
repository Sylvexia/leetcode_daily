// 1552. Magnetic Force Between Two Balls

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    bool valid(vector<int> &position, int mid, int m)
    {
        int prev = 0, j = 1;
        for (int i = 1; i < m; i++) {
            while (j < position.size() and position[j] < position[prev] + mid)
                j++;
            if (j >= position.size())
                return false;
            prev = j;
        }
        return true;
    }

public:
    int maxDistance(vector<int> &position, int m)
    {
        sort(position.begin(), position.end());
        if (m == 2)
            return position.back() - position[0];

        int l = 1, r = position.back() - position[0];
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (valid(position, mid, m))
                l = mid + 1;
            else
                r = mid - 1;
        }
        return r;
    }
};