// 873. Length of Longest Fibonacci Subsequence

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int lenLongestFibSubseq(vector<int> &arr)
    {
        unordered_set<int> u_set(arr.begin(), arr.end());
        int res = 0;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                int a = arr[i], b = arr[j];
                int cur = 2;
                while (u_set.count(a + b)) {
                    b = a + b;
                    a = b - a;
                    cur++;
                }
                res = max(res, cur);
            }
        }
        return res > 2 ? res : 0;
    }
};