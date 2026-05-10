// 3925. Concatenate Array With Reverse

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        nums.insert(nums.end(), nums.rbegin(), nums.rend());
        return nums;
    }
};