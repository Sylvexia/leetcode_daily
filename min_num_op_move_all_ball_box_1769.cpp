// 1769. Minimum Number of Operations to Move All Balls to Each Box

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<int> minOperations(string boxes)
    {
        int n = boxes.size();
        int cur = 0, add = 0, sub = 0;
        for (int i = 0; i < n; i++) {
            if (boxes[i] == '1')
                sub++, cur += (i + 1);
        }

        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            cur -= sub;
            cur += add;
            res[i] = cur;
            if (boxes[i] == '1')
                add++, sub--;
        }
        return res;
    }
};