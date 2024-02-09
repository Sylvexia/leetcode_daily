// 350. Intersection of Two Arrays II

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> u_map;
        for (int n : nums1)
            u_map[n]++;

        vector<int> res;
        for (int n : nums2) {
            if (u_map[n] > 0) {
                u_map[n]--;
                res.push_back(n);
            }
        }
        return res;
    }
};