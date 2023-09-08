// 454. 4Sum II

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int fourSumCount(vector<int> &nums1,
                     vector<int> &nums2,
                     vector<int> &nums3,
                     vector<int> &nums4)
    {
        unordered_map<int, int> add_count;

        for (int i : nums1) {
            for (int j : nums2)
                add_count[i + j]++;
        }

        int res = 0;

        for (int i : nums3) {
            for (int j : nums4)
                res += add_count[-(i + j)];
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> data1{-1, -1}, data2{-1, 1}, data3{-1, 1}, data4{1, -1};
    cout << sol.fourSumCount(data1, data2, data3, data4);
}