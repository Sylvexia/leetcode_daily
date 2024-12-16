// 3264. Final Array State After K Multiplication Operations I

#include <bits/stdc++.h>
#include <queue>

using namespace std;

class Solution
{
    typedef pair<int, int> pii;

public:
    vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
    {
        auto comp = [](pii &a, pii &b) {
            if (a.first == b.first)
                return a.second > b.second;
            return a.first > b.first;
        };
        priority_queue<pii, vector<pii>, decltype(comp)> pq(comp);

        int n = nums.size();
        for (int i = 0; i < n; i++)
            pq.push({nums[i], i});

        while (k--) {
            auto [val, index] = pq.top();
            pq.pop();

            val *= multiplier;
            nums[index] = val;

            pq.push({val, index});
        }
        return nums;
    }
};