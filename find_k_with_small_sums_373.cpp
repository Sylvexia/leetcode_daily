// 373. Find K Pairs with Smallest Sums

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<vector<int>> res;
        auto comp = [&nums1, &nums2](pair<int, int> &a, pair<int, int> &b)
        {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);

        pq.push({0, 0});
        while (k-- > 0 and pq.size())
        {
            auto top_pair = pq.top();
            pq.pop();
            res.push_back({nums1[top_pair.first], nums2[top_pair.second]});
            if (top_pair.first + 1 < nums1.size())
                pq.push({top_pair.first + 1, top_pair.second});
            if (top_pair.first == 0 and top_pair.second + 1 < nums2.size())
                pq.push({top_pair.first, top_pair.second + 1});
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1{1, 2}, nums2{3};
    int k = 3;

    vector<vector<int>> res{sol.kSmallestPairs(nums1, nums2, k)};

    for (auto &r : res)
    {
        for (auto &c : r)
            cout << c << " ";
        cout << "\n";
    }

    return 0;
}