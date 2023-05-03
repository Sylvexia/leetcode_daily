// 2215. Find the Difference of Two Arrays

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> set1, set2;

        for (auto n : nums1)
            set1.insert(n);

        for (auto n : nums2)
            set2.insert(n);

        vector<vector<int>> res(2);

        for (auto n : set1)
        {
            if (set2.count(n) == 0)
                res[0].push_back(n);
        }

        for (auto n : set2)
        {
            if (set1.count(n) == 0)
                res[1].push_back(n);
        }

        return res;
    }
};