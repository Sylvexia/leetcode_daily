// 88. Merge Sorted Array

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int m_i = m - 1;
        int n_i = n - 1;
        int k_i = m + n - 1;

        while (n_i >= 0) {
            if (m_i >= 0 and nums1[m_i] > nums2[n_i]) {
                nums1[k_i] = nums1[m_i];
                m_i--;
                k_i--;
            } else {
                nums1[k_i] = nums2[n_i];
                n_i--;
                k_i--;
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<int> data1{1}, data2{};
    int m = 1;
    int n = 0;
    sol.merge(data1, m, data2, n);
}