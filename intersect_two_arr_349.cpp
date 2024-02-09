// 349. Intersection of Two Arrays

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> u_set, u_set_2;
        for (int n : nums1)
            u_set.insert(n);
        for (int n : nums2) {
            if (u_set.find(n) != u_set.end())
                u_set_2.insert(n);
        }

        vector<int> res;
        for (int n : u_set_2)
            res.push_back(n);

        return res;
    }
};