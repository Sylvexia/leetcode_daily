// 2542. Maximum Subsequence Score

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int n = nums1.size();
        vector<pair<int, int>> pairs(n);

        for (int i = 0; i < n; i++)
            pairs[i] = {nums2[i], nums1[i]};

        sort(pairs.rbegin(), pairs.rend());

        long long res = 0, sums = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto [n2, n1] : pairs)
        {
            pq.emplace(n1);
            sums += n1;
            if (pq.size() > k)
            {
                sums -= pq.top();
                pq.pop();
            }
            if (pq.size() == k)
                res = max(res, sums * n2);
        }
        return res;
    }
};