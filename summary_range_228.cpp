// 228. Summary Ranges

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> res;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j <= nums.size(); j++) {
                long long int target = (long long int) nums[i] + j - i;
                if (j == nums.size() or target != nums[j]) {
                    if (j - i == 1)
                        res.push_back(to_string(nums[i]));
                    else
                        res.push_back(to_string(nums[i]) + "->" +
                                      to_string(nums[j - 1]));
                    i = j - 1;
                    break;
                }
            }
        }
        return res;
    }
};