// 786. K-th Smallest Prime Fraction

#include <bits/stdc++.h>
#include <queue>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    struct comp {
        bool operator()(pair<int, int> &a, pair<int, int> &b)
        {
            float res_a = float(a.first) / a.second;
            float res_b = float(b.first) / b.second;

            return res_a > res_b;
        }
    };

public:
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;

        for (int i = 0; i < arr.size() - 1; i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                pq.push({arr[i], arr[j]});
            }
        }
        vector<int> res{-1, -1};
        while (k--) {
            auto [a, b] = pq.top();
            pq.pop();
            res = {a, b};
        }
        return res;
    }
};