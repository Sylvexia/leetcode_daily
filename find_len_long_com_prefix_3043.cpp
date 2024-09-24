// 3043. Find the Length of the Longest Common Prefix

#include <bits/stdc++.h>
#include <string>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    int get_digits(int n)
    {
        string num_str = to_string(n);
        return num_str.size();
    }

public:
    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
    {
        unordered_set<int> pre_set;
        for (int n : arr1) {
            while (n) {
                pre_set.insert(n);
                n /= 10;
            }
        }

        int res = 0;
        for (int n : arr2) {
            while (n) {
                if (pre_set.count(n))
                    res = max(res, get_digits(n));
                n /= 10;
            }
        }
        return res;
    }
};