// 2780. Minimum Index of a Valid Split

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int minimumIndex(vector<int> &nums)
    {
        unordered_map<int, int> front, back;
        for (int n : nums)
            back[n]++;

        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            back[n]--;
            front[n]++;
            if (front[n] * 2 > (i + 1) and back[n] * 2 > (nums.size() - i - 1))
                return i;
        }
        return -1;
    }
};