// 3005. Count Elements With Maximum Frequency

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        unordered_map<int, int> count;
        for (int n : nums)
            count[n]++;

        int max_freq = 0;
        for (auto [key, value] : count)
            max_freq = max(max_freq, value);

        int res = 0;
        for (auto [key, value] : count) {
            if (value == max_freq)
                res += value;
        }
        return res;
    }
};