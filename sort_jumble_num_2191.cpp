// 2191. Sort the Jumbled Numbers

#include <bits/stdc++.h>
#include <string>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums)
    {
        vector<pair<int, int>> vec;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            string str_num = to_string(num);
            string str_res = "";
            for (char ch : str_num)
                str_res += (to_string(mapping[ch - '0']));
            int val = stoi(str_res);
            vec.push_back({val, i});
        }

        sort(vec.begin(), vec.end());

        vector<int> res;
        for (auto [_, index] : vec) {
            res.push_back(nums[index]);
        }

        return res;
    }
};