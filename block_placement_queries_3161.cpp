// 3161. Block Placement Queries

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution {
    vector<int> seg;

    void update(int idx, int val, int p, int l, int r) {
        if (l == r) {
            seg[p] = val;
            return;
        }

        int m = (l + r) >> 1;

        if (idx <= m)
            update(idx, val, p << 1, l, m);
        else
            update(idx, val, p << 1 | 1, m + 1, r);

        seg[p] = max(seg[p << 1], seg[p << 1 | 1]);
    }

    int query(int L, int R, int p, int l, int r) {
        if (L <= l && r <= R)
            return seg[p];

        int m = (l + r) >> 1;
        int res = 0;

        if (L <= m)
            res = max(res, query(L, R, p << 1, l, m));

        if (R > m)
            res = max(res, query(L, R, p << 1 | 1, m + 1, r));

        return res;
    }

public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int mx = 50000;

        seg.resize(4 * (mx + 1));

        set<int> st = {0, mx};

        update(mx, mx, 1, 0, mx);

        vector<bool> res;

        for (auto& q : queries) {
            if (q[0] == 1) {
                int x = q[1];

                auto it = st.upper_bound(x);
                int r = *it;
                int l = *prev(it);

                update(x, x - l, 1, 0, mx);
                update(r, r - x, 1, 0, mx);

                st.insert(x);
            } else {
                int x = q[1];
                int sz = q[2];

                auto it = st.upper_bound(x);
                --it;

                int pre = *it;

                int max_space = query(0, pre, 1, 0, mx);
                max_space = max(max_space, x - pre);

                res.push_back(max_space >= sz);
            }
        }

        return res;
    }
};