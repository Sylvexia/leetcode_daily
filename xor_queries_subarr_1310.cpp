// 1310. XOR Queries of a Subarray

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        vector<int> prefix(arr.size());
        prefix[0] = arr[0];
        for (int i = 1; i < arr.size(); i++)
            prefix[i] = prefix[i - 1] ^ arr[i];

        vector<int> res;
        for (auto &q : queries) {
            int start = q[0] - 1;
            int end = q[1];
            if (start < 0)
                res.push_back(prefix[end]);
            else
                res.push_back(prefix[end] ^ prefix[start]);
        }

        return res;
    }
};