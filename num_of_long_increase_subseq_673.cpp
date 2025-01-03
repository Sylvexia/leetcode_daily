// 673. Number of Longest Increasing Subsequence

#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> len(n, 1);
        vector<int> freq(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (len[j] + 1 > len[i]) {
                        len[i] = len[j] + 1;
                        freq[i] = 0;
                    }
                    if (len[j] + 1 == len[i])
                        freq[i] += freq[j];
                }
            }
        }
        int maxLIS = *max_element(len.begin(), len.end());
        int res = 0;

        for (int i = 0; i < n; i++) {
            if (len[i] == maxLIS)
                res += freq[i];
        }
        return res;
    }
};