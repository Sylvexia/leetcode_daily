// 2570. Merge Two 2D Arrays by Summing Values

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1,
                                    vector<vector<int>> &nums2)
    {
        map<int, int> map;

        for (auto ele : nums1)
            map[ele[0]] += ele[1];
        for (auto ele : nums2)
            map[ele[0]] += ele[1];

        vector<vector<int>> res;
        for (auto [key, val] : map)
            res.push_back({key, val});

        return res;
    }
};