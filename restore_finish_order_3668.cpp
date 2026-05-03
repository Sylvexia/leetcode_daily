// 3668. Restore Finishing Order

#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<int> recoverOrder(vector<int> &order, vector<int> &friends)
    {
        unordered_set<int> fq{friends.begin(), friends.end()};
        vector<int> res;
        for (int o : order) {
            if (fq.find(o) != fq.end())
                res.push_back(o);
        }
        return res;
    }
};